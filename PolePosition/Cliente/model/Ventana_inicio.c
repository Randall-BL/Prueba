#include "../headers/Ventana_inicio.h"
#include "../headers/Ventanaprueba.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#include "../headers/Ventana_Juego.h"

// Definición del socket global
extern int sockfd;

// Lógica que construye la ventana de inicio
Ventana_inicio* crearVentanaInicio() {
    Ventana_inicio* ventana_inicio = (Ventana_inicio*)malloc(sizeof(Ventana_inicio));
    ventana_inicio->ventana_inicio = sfRenderWindow_create((sfVideoMode){1000, 1000, 32}, "Ventana de seleccion de carros", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(ventana_inicio->ventana_inicio, 165);

    ventana_inicio->btn_selec_carroR = sfRectangleShape_create();
    sfRectangleShape_setSize(ventana_inicio->btn_selec_carroR, (sfVector2f){150, 50});
    sfRectangleShape_setPosition(ventana_inicio->btn_selec_carroR, (sfVector2f){100, 450});
    sfRectangleShape_setFillColor(ventana_inicio->btn_selec_carroR, sfRed);

    ventana_inicio->btn_selec_carroA = sfRectangleShape_create();
    sfRectangleShape_setSize(ventana_inicio->btn_selec_carroA, (sfVector2f){150, 50});
    sfRectangleShape_setPosition(ventana_inicio->btn_selec_carroA, (sfVector2f){300, 450});
    sfRectangleShape_setFillColor(ventana_inicio->btn_selec_carroA, sfBlue);

    ventana_inicio->btn_selec_carroB = sfRectangleShape_create();
    sfRectangleShape_setSize(ventana_inicio->btn_selec_carroB, (sfVector2f){150, 50});
    sfRectangleShape_setPosition(ventana_inicio->btn_selec_carroB, (sfVector2f){500, 450});
    sfRectangleShape_setFillColor(ventana_inicio->btn_selec_carroB, sfWhite);

    ventana_inicio->btn_selec_carroM = sfRectangleShape_create();
    sfRectangleShape_setSize(ventana_inicio->btn_selec_carroM, (sfVector2f){150, 50});
    sfRectangleShape_setPosition(ventana_inicio->btn_selec_carroM, (sfVector2f){700, 450});
    sfRectangleShape_setFillColor(ventana_inicio->btn_selec_carroM, sfMagenta);

    //ciclar la ventana
    Ciclar(ventana_inicio);

    return ventana_inicio;
}

// Función que maneja los eventos
void manejarCierre(sfEvent event, sfRenderWindow* window) {
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void manejarClick(sfEvent event, Ventana_inicio* ventana) {
    if (event.mouseButton.button == sfMouseLeft) {
        sfVector2f pos;
        sfVector2f size;
        char request[100] = {0};
        sfColor color = sfBlack; // Default color

        pos = sfRectangleShape_getPosition(ventana->btn_selec_carroR);
        size = sfRectangleShape_getSize(ventana->btn_selec_carroR);
        if (event.mouseButton.x >= pos.x && event.mouseButton.x <= pos.x + size.x &&
            event.mouseButton.y >= pos.y && event.mouseButton.y <= pos.y + size.y) {
            strcat(request, "Red\n");
        }

        pos = sfRectangleShape_getPosition(ventana->btn_selec_carroA);
        size = sfRectangleShape_getSize(ventana->btn_selec_carroA);
        if (event.mouseButton.x >= pos.x && event.mouseButton.x <= pos.x + size.x &&
            event.mouseButton.y >= pos.y && event.mouseButton.y <= pos.y + size.y) {
            strcat(request, "Blue\n");
        }

        pos = sfRectangleShape_getPosition(ventana->btn_selec_carroB);
        size = sfRectangleShape_getSize(ventana->btn_selec_carroB);
        if (event.mouseButton.x >= pos.x && event.mouseButton.x <= pos.x + size.x &&
            event.mouseButton.y >= pos.y && event.mouseButton.y <= pos.y + size.y) {
            strcat(request, "White\n");
        }

        pos = sfRectangleShape_getPosition(ventana->btn_selec_carroM);
        size = sfRectangleShape_getSize(ventana->btn_selec_carroM);
        if (event.mouseButton.x >= pos.x && event.mouseButton.x <= pos.x + size.x &&
            event.mouseButton.y >= pos.y && event.mouseButton.y <= pos.y + size.y) {
            strcat(request, "Purple\n");
        }

        if (strlen(request) > 0) {
            printf("Botón %s seleccionado\n", request);
            send(sockfd, request, strlen(request), 0);  // Envía la selección del color

            char response[100];
            int bytesReceived = recv(sockfd, response, sizeof(response) - 1, 0);  // Espera la confirmación
            if (bytesReceived > 0) {
                response[bytesReceived] = '\0';
                printf("Respuesta del servidor por parte de la ventana inicio: %s\n", response);

                // Procesa la respuesta y establece el color correspondiente
                if (strstr(response, "Red")) {
                    color = sfRed;
                } else if (strstr(response, "Blue")) {
                    color = sfBlue;
                } else if (strstr(response, "White")) {
                    color = sfWhite;
                } else if (strstr(response, "Purple")) {
                    color = sfMagenta;
                }
                // Crea la ventana de juego con el color seleccionado
                Ventana_juego* ventana_juego = crearVentanaJuego(response);
            }
        }
    }
}


void Eventos(Ventana_inicio *ventana_inicio) {
    while (sfRenderWindow_pollEvent(ventana_inicio->ventana_inicio, &ventana_inicio->events)) {
        manejarCierre(ventana_inicio->events, ventana_inicio->ventana_inicio);
        if (ventana_inicio->events.type == sfEvtMouseButtonPressed) {
            manejarClick(ventana_inicio->events, ventana_inicio);
        }
    }
}

// Función que renderiza la ventana
void Renderizar(Ventana_inicio *ventana_inicio) {
    sfRenderWindow_clear(ventana_inicio->ventana_inicio, sfBlack);
    sfRenderWindow_drawRectangleShape(ventana_inicio->ventana_inicio, ventana_inicio->btn_selec_carroR, NULL);
    sfRenderWindow_drawRectangleShape(ventana_inicio->ventana_inicio, ventana_inicio->btn_selec_carroA, NULL);
    sfRenderWindow_drawRectangleShape(ventana_inicio->ventana_inicio, ventana_inicio->btn_selec_carroB, NULL);
    sfRenderWindow_drawRectangleShape(ventana_inicio->ventana_inicio, ventana_inicio->btn_selec_carroM, NULL);
    sfRenderWindow_display(ventana_inicio->ventana_inicio);
}

// Función que contiene el ciclo principal
void Ciclar(Ventana_inicio *ventana_inicio) {
    while (sfRenderWindow_isOpen(ventana_inicio->ventana_inicio)) {
        Eventos(ventana_inicio);
        Renderizar(ventana_inicio);
        // Podrías agregar un pequeño delay aquí para reducir el uso de CPU
        //sfSleep(sfMilliseconds(10));
    }
    // Limpieza de la memoria
    sfRectangleShape_destroy(ventana_inicio->btn_selec_carroR);
    sfRectangleShape_destroy(ventana_inicio->btn_selec_carroA);
    sfRectangleShape_destroy(ventana_inicio->btn_selec_carroB);
    sfRectangleShape_destroy(ventana_inicio->btn_selec_carroM);
    sfRenderWindow_destroy(ventana_inicio->ventana_inicio);

    free(ventana_inicio);

    printf("Memoria liberada de la ventana de inicio");
}
