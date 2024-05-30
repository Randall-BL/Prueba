//
// Created by Yonathan Monge on 21/5/2024.
//

#ifndef VENTANA_JUEGO_H
#define VENTANA_JUEGO_H

#include <stdlib.h>
#include <SFML/Graphics.h>


///estructura de la ventana de juego///
typedef struct{
    sfRenderWindow* ventana_juego;  //ventana de juego
    sfEvent events; //evento de la ventana

    sfRectangleShape *linea1; //linea que divide la pantalla
    sfRectangleShape *linea2; //linea que divide la pantalla

    sfView *vista_jgdr1; //vista del jugador 1
    sfView *vista_jgdr2; //vista del jugador 2
    sfView *vista_jgdr3; //vista del jugador 3

    sfTexture* txtr_fondo; //textura del fondo
    sfSprite* sprt_fondo; //sprite del fondo

} Ventana_juego;
///////////////////////////////////////

/// metodos de la ventana de juego///
Ventana_juego* crearVentanaJuego(char* ColorCarro); //creamos la ventana de juego
void Eventos_Vtn_Juego(Ventana_juego* ventana_juego); //manejamos los eventos de la ventana de juego
void Ciclar_Vtn_Juego(Ventana_juego* ventana_juego); //ciclamos la ventana de juego
void Renderizar_Vtn_Juego(Ventana_juego *ventana_juego); //renderizamos la ventana de juego
/////////////////////

#endif //VENTANA_JUEGO_H
