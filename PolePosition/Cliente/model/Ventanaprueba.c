#include "../headers/Ventanaprueba.h"
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <math.h>


#define PI 3.14159265358979323846

VentanaPrueba* crearVentanaPrueba(sfColor color) {
    VentanaPrueba* ventana = malloc(sizeof(VentanaPrueba));
    ventana->ventana = sfRenderWindow_create((sfVideoMode){1000, 1000, 32}, "Ventana de Carreras", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(ventana->ventana, 60);
    cargarMapa(ventana, "../recursos/map.txt");
    ventana->color = color; // Asignar el color recibido
    ventana->playerAngle = 0; // Inicializar el ángulo del jugador mirando hacia adelante
    return ventana;
}


void manejarEventos(VentanaPrueba* ventana) {
    float moveStep = 0.5; // Ajusta esto según sea necesario para la velocidad del movimiento
    while (sfRenderWindow_pollEvent(ventana->ventana, &ventana->evento)) {
        if (ventana->evento.type == sfEvtClosed) {
            sfRenderWindow_close(ventana->ventana);
        }
        if (ventana->evento.type == sfEvtKeyPressed) {
            float newX = ventana->carroX;
            float newY = ventana->carroY;

            switch (ventana->evento.key.code) {
                case sfKeyW: // Mover adelante
                    newX += cos(ventana->playerAngle) * moveStep;
                    newY -= sin(ventana->playerAngle) * moveStep;
                    break;
                case sfKeyS: // Mover atrás
                    newX -= cos(ventana->playerAngle) * moveStep;
                    newY += sin(ventana->playerAngle) * moveStep;
                    break;
                case sfKeyA: // Girar a la izquierda
                    ventana->playerAngle -= 0.05; // Reduce la cantidad de cambio para giros más suaves
                    if (ventana->playerAngle < 0) ventana->playerAngle += 2 * PI; // Normalizar el ángulo
                    break;
                case sfKeyD: // Girar a la derecha
                    ventana->playerAngle += 0.05;
                    if (ventana->playerAngle > 2 * PI) ventana->playerAngle -= 2 * PI; // Normalizar el ángulo
                    break;
            }

            // Solo actualiza la posición del carro si se presionan W o S
            if (ventana->evento.key.code == sfKeyW || ventana->evento.key.code == sfKeyS) {
                // Verificar colisión después de calcular la nueva posición
                if (newX >= 0 && newX < MAX_WIDTH && newY >= 0 && newY < MAX_HEIGHT && ventana->mapa[(int)newY][(int)newX] != '1') {
                    ventana->carroX = newX;
                    ventana->carroY = newY;
                }
            }
        }
    }
}

void renderizar(VentanaPrueba* ventana) {
    sfRenderWindow_clear(ventana->ventana, sfBlack);  // Limpia la ventana con un fondo negro

    // Renderizar la vista en tercera persona
    castRays(ventana->ventana, ventana);

    // Renderizar el minimapa en la mitad inferior
    renderMinimap(ventana);

    // Renderizar el carro en el minimapa
    renderCarro(ventana);

    sfRenderWindow_display(ventana->ventana);
}

void castRays(sfRenderWindow* window, VentanaPrueba* game) {
    float rayAngle, distanceToWall, stepSize = 0.1;
    int hitWall;
    const int screenHeight = 500;  // Altura de la mitad superior de la ventana de renderizado
    const int screenWidth = 1000;  // Anchura de la ventana de renderizado

    for (int i = 0; i < NUM_RAYS; i++) {
        rayAngle = (game->playerAngle - FOV / 2.0) + (i / (float)NUM_RAYS) * FOV;
        distanceToWall = 0;
        hitWall = 0;

        float eyeX = cos(rayAngle);
        float eyeY = -sin(rayAngle);

        while (!hitWall && distanceToWall < MAX_DEPTH) {
            distanceToWall += stepSize;
            int testX = (int)(game->carroX + eyeX * distanceToWall);
            int testY = (int)(game->carroY + eyeY * distanceToWall);

            if (testX < 0 || testX >= MAX_WIDTH || testY < 0 || testY >= MAX_HEIGHT) {
                hitWall = 1;
                distanceToWall = MAX_DEPTH;
            } else if (game->mapa[testY][testX] == '1') {
                hitWall = 1;
            }
        }

        int wallHeight = (int)(screenHeight / distanceToWall);
        int wallTop = (screenHeight / 2) - (wallHeight / 2);
        int wallBottom = (screenHeight / 2) + (wallHeight / 2);

        // Pintar el suelo amarillo claro hasta el punto donde se encuentra la pared
        for (int y = wallBottom; y < screenHeight; y++) {
            sfRectangleShape* floorTile = sfRectangleShape_create();
            sfRectangleShape_setPosition(floorTile, (sfVector2f){i * (screenWidth / NUM_RAYS), y});
            sfRectangleShape_setSize(floorTile, (sfVector2f){(screenWidth / NUM_RAYS), 1});
            sfRectangleShape_setFillColor(floorTile, sfColor_fromRGB(255, 255, 128));
            sfRenderWindow_drawRectangleShape(window, floorTile, NULL);
            sfRectangleShape_destroy(floorTile);
        }

        sfRectangleShape* wall = sfRectangleShape_create();
        sfRectangleShape_setPosition(wall, (sfVector2f){i * (screenWidth / NUM_RAYS), wallTop});
        sfRectangleShape_setSize(wall, (sfVector2f){(screenWidth / NUM_RAYS), wallBottom - wallTop});
        sfRectangleShape_setFillColor(wall, sfColor_fromRGB(255 / distanceToWall, 255 / distanceToWall, 255 / distanceToWall));
        sfRenderWindow_drawRectangleShape(window, wall, NULL);
        sfRectangleShape_destroy(wall);
    }

    // Renderizar el carro en 3D
    sfRectangleShape* carro = sfRectangleShape_create();
    sfRectangleShape_setSize(carro, (sfVector2f){screenWidth / 10, screenHeight / 20});
    sfRectangleShape_setFillColor(carro, game->color);
    // Posicionar el carro en la parte inferior central de la vista
    sfVector2f carroPos = {screenWidth / 2 - (screenWidth / 20) / 2, screenHeight - screenHeight / 10};
    sfRectangleShape_setPosition(carro, carroPos);
    sfRenderWindow_drawRectangleShape(window, carro, NULL);
    sfRectangleShape_destroy(carro);
}

void renderCarro(VentanaPrueba* ventana) {
    int minimapScale = 4; // Escala del minimapa
    int offsetY = 500; // Desplazamiento vertical para dibujar en la mitad inferior

    // Representar el carro como un cuadrado y un triángulo
    sfRectangleShape* carroCuadrado = sfRectangleShape_create();
    sfRectangleShape_setSize(carroCuadrado, (sfVector2f){minimapScale, minimapScale});
    //sfRectangleShape_setFillColor(carroCuadrado, ventana->color); // Usar el color almacenado

    sfConvexShape* carroTriangulo = sfConvexShape_create();
    sfConvexShape_setPointCount(carroTriangulo, 3);

    // Puntos del triángulo (punta del carro)
    sfConvexShape_setPoint(carroTriangulo, 0, (sfVector2f){0, -minimapScale / 2});
    sfConvexShape_setPoint(carroTriangulo, 1, (sfVector2f){minimapScale / 2, minimapScale / 2});
    sfConvexShape_setPoint(carroTriangulo, 2, (sfVector2f){-minimapScale / 2, minimapScale / 2});

    sfConvexShape_setFillColor(carroTriangulo, ventana->color); // Usar el color almacenado

    // Calcular la posición del carro en el minimapa
    float carroMinimapX = ventana->carroX * minimapScale;
    float carroMinimapY = ventana->carroY * minimapScale + offsetY;

    // Calcular la rotación del carro en grados
    float carroAngle = ventana->playerAngle * (180 / PI);

    // Dibujar el cuadrado del carro
    sfRectangleShape_setPosition(carroCuadrado, (sfVector2f){carroMinimapX - minimapScale / 2, carroMinimapY - minimapScale / 2});
    sfRenderWindow_drawRectangleShape(ventana->ventana, carroCuadrado, NULL);

    // Calcular la posición del triángulo con respecto al cuadrado
    float trianguloX = carroMinimapX + cos(ventana->playerAngle) * minimapScale;
    float trianguloY = carroMinimapY - sin(ventana->playerAngle) * minimapScale;

    // Dibujar el triángulo del carro
    sfConvexShape_setPosition(carroTriangulo, (sfVector2f){trianguloX, trianguloY});
    sfConvexShape_setRotation(carroTriangulo, -carroAngle); // Negativo para ajustar la dirección correcta
    sfRenderWindow_drawConvexShape(ventana->ventana, carroTriangulo, NULL);

    sfRectangleShape_destroy(carroCuadrado);
    sfConvexShape_destroy(carroTriangulo);
}



void renderMinimap(VentanaPrueba* ventana) {
    int minimapScale = 4; // Incrementa la escala para hacer el minimapa más grande
    int offsetY = 500; // Desplazamiento vertical para dibujar en la mitad inferior

    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            sfRectangleShape* tile = sfRectangleShape_create();
            sfRectangleShape_setPosition(tile, (sfVector2f){j * minimapScale, i * minimapScale + offsetY});
            sfRectangleShape_setSize(tile, (sfVector2f){minimapScale, minimapScale});

            switch (ventana->mapa[i][j]) {
                case '0':
                    sfRectangleShape_setFillColor(tile, sfColor_fromRGB(0, 0, 0)); // Negro para fuera de pista
                    break;
                case '1':
                    sfRectangleShape_setFillColor(tile, sfColor_fromRGB(255, 255, 255)); // Blanco para los límites
                    break;
                case '2':
                    sfRectangleShape_setFillColor(tile, sfColor_fromRGB(0, 255, 0)); // Verde para la carretera
                    break;
                case '3':
                    sfRectangleShape_setFillColor(tile, sfColor_fromRGB(255, 0, 0)); // Rojo para el punto de partida/final
                    break;
                default:
                    sfRectangleShape_setFillColor(tile, sfColor_fromRGB(0, 0, 0)); // Negro por defecto
            }

            sfRenderWindow_drawRectangleShape(ventana->ventana, tile, NULL);
            sfRectangleShape_destroy(tile);
        }
    }
}

void cargarMapa(VentanaPrueba* ventana, const char* nombreArchivo) {
    FILE* file = fopen(nombreArchivo, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo del mapa");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_HEIGHT && !feof(file); i++) {
        fgets(ventana->mapa[i], MAX_WIDTH, file);
    }

    fclose(file);

    // Inicializar la posición del carro en el punto de partida (asumiendo que el punto de partida es '3')
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            if (ventana->mapa[i][j] == '3') {
                ventana->carroX = j;
                ventana->carroY = i;
                return;
            }
        }
    }
}

void ciclarVentana(VentanaPrueba* ventana) {
    while (sfRenderWindow_isOpen(ventana->ventana)) {
        manejarEventos(ventana);
        renderizar(ventana);
    }

    // Cleanup after the window is closed
    sfRenderWindow_destroy(ventana->ventana);
    free(ventana);
}

