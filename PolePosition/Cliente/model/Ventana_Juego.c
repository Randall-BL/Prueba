//
// Created by Yonathan Monge on 21/5/2024.
//
#include <stdio.h>
#include "../headers/Ventana_Juego.h"
#include "../headers/Mapa_1.h"
#include "../headers/Mapa_2.h"
#include <math.h>

#include "../headers/Jugador_1.h"
#include "../headers/Jugador_2.h"
#include "../headers/Jugador_3.h"
#include "../headers/Mapa_3.h"


Ventana_juego* crearVentanaJuego(char* ColorCarro) {

    Ventana_juego* ventana_juego = (Ventana_juego*)malloc(sizeof(Ventana_juego));

    sfVideoMode mode = sfVideoMode_getDesktopMode();
    char title[32]; // char para el titulo de la ventana del juego
    sprintf(title, "PolePositionRetro");

    ///PARA SALIRSE DE LA VENTANA HAY QUE PRESIONAR LA TECLA ESCAPE
    ventana_juego->ventana_juego = sfRenderWindow_create(mode, title, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(ventana_juego->ventana_juego, 60);

    //inicializamos las lineas que dividen la pantalla
    ventana_juego->linea1 = sfRectangleShape_create();
    sfRectangleShape_setSize(ventana_juego->linea1, (sfVector2f){1, mode.height});
    sfRectangleShape_setFillColor(ventana_juego->linea1, sfWhite);
    sfRectangleShape_setPosition(ventana_juego->linea1, (sfVector2f){(mode.width/3), 0});

    ventana_juego->linea2 = sfRectangleShape_create();
    sfRectangleShape_setSize(ventana_juego->linea2, (sfVector2f){1, mode.height});
    sfRectangleShape_setFillColor(ventana_juego->linea2, sfWhite);
    sfRectangleShape_setPosition(ventana_juego->linea2, (sfVector2f){(mode.width /3)+(mode.width/3), 0});

    //inicializamos las vistas de los jugadores
    ventana_juego->vista_jgdr1 = sfView_create();
    ventana_juego->vista_jgdr2 = sfView_create();
    ventana_juego->vista_jgdr3 = sfView_create();

    //le damos el tamano a las vistas
    sfVector2f size = {mode.width/3, mode.height};   //tamano de la tercera parte de la ventana
    printf("x: %f, y: %f\n", size.x, size.y);
    sfView_setSize(ventana_juego->vista_jgdr1, size);
    sfView_setSize(ventana_juego->vista_jgdr2, size);
    sfView_setSize(ventana_juego->vista_jgdr3, size);

    //colocamos las vistas en su lugar correspondiente
    sfView_setViewport(ventana_juego->vista_jgdr1, (sfFloatRect){0.0f, 0.0f, 1.0f/3.0f, 1.0});
    sfView_setViewport(ventana_juego->vista_jgdr2, (sfFloatRect){1.0f/3.0f, 0.0f, 1.0f/3.0f, 1.0});
    sfView_setViewport(ventana_juego->vista_jgdr3, (sfFloatRect){2.0f/3.0f, 0.0f, 1.0f/3.0f, 1.0});

    //inicializamos el fondo de los mapas

    char direccion_txtr_fondo[]= "../Recursos/fondo.png";
    ventana_juego->txtr_fondo = sfTexture_createFromFile(direccion_txtr_fondo, NULL);

    ventana_juego-> sprt_fondo = sfSprite_create();
    sfSprite_setTexture(ventana_juego-> sprt_fondo,ventana_juego-> txtr_fondo, sfTrue);
    sfSprite_setPosition(ventana_juego-> sprt_fondo, (sfVector2f){0, -40});
    sfSprite_setScale(ventana_juego-> sprt_fondo, (sfVector2f){0.31f, 0.31f});

    //creamos los jugadoes
    crearJugador_1(ColorCarro);
    crearJugador_2(ColorCarro);
    crearJugador_3(ColorCarro);

    Ciclar_Vtn_Juego(ventana_juego);

    return ventana_juego;
}

void Eventos_Vtn_Juego(Ventana_juego *ventana_juego) {
    while (sfRenderWindow_pollEvent(ventana_juego->ventana_juego, &ventana_juego->events)) {
        if (ventana_juego->events.type == sfEvtClosed) {
            sfRenderWindow_close(ventana_juego->ventana_juego);
        }
    }
}

void Renderizar_Vtn_Juego(Ventana_juego *ventana_juego) {
    sfRenderWindow_clear(ventana_juego->ventana_juego, sfBlack);

    // View del jugador 1
    sfRenderWindow_setView(ventana_juego->ventana_juego, ventana_juego->vista_jgdr1);
    // Aqui va "Ejecutar_Mapa1(Ventana_juego* ventana_juego)"
    sfRenderWindow_drawSprite(ventana_juego->ventana_juego, ventana_juego->sprt_fondo, NULL);  //muestra un fondo en la ventana
    Ejecutar_Mapa1(ventana_juego->ventana_juego);
    // View del jugador 2
    sfRenderWindow_setView(ventana_juego->ventana_juego, ventana_juego->vista_jgdr2);
    Ejecutar_Mapa2(ventana_juego->ventana_juego);
    sfRenderWindow_drawSprite(ventana_juego->ventana_juego, ventana_juego->sprt_fondo, NULL);  //muestra un fondo en la ventana


    // View del jugador 3
    sfRenderWindow_setView(ventana_juego->ventana_juego, ventana_juego->vista_jgdr3);
    Ejecutar_Mapa3(ventana_juego->ventana_juego);
    sfRenderWindow_drawSprite(ventana_juego->ventana_juego, ventana_juego->sprt_fondo, NULL);  //muestra un fondo en la ventana


    // Restablecer el view para dibujar en toda la ventana
    sfRenderWindow_setView(ventana_juego->ventana_juego, sfRenderWindow_getDefaultView(ventana_juego->ventana_juego));

    // Dibujar las líneas divisorias
    sfRenderWindow_drawRectangleShape(ventana_juego->ventana_juego, ventana_juego->linea1, NULL);
    sfRenderWindow_drawRectangleShape(ventana_juego->ventana_juego, ventana_juego->linea2, NULL);

    sfRenderWindow_display(ventana_juego->ventana_juego);
}

void Ciclar_Vtn_Juego(Ventana_juego *ventana_juego) {
    while (sfRenderWindow_isOpen(ventana_juego->ventana_juego)) {
        Eventos_Vtn_Juego(ventana_juego);

        Renderizar_Vtn_Juego(ventana_juego);

    }

    // Liberación de memoria

    sfRectangleShape_destroy(ventana_juego->linea1);
    sfRectangleShape_destroy(ventana_juego->linea2);

    sfSprite_destroy(GetSpriteJugador_1());

    sfView_destroy(ventana_juego->vista_jgdr1);
    sfView_destroy(ventana_juego->vista_jgdr2);
    sfView_destroy(ventana_juego->vista_jgdr3);

    sfRenderWindow_destroy(ventana_juego->ventana_juego);
    free(ventana_juego);
    printf("Se liberó la memoria de la ventana de juego\n");

}