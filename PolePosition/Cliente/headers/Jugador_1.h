//
// Created by Yonathan Monge on 23/5/2024.
//

#ifndef JUGADOR_PRUEBA_H
#define JUGADOR_PRUEBA_H

#include <SFML/Graphics.h>

typedef struct {
    sfSprite* sprt_jugador_1;
    sfTexture* txtr_jugador;
}Jugador_1;

Jugador_1* crearJugador_1(char* ColorCarro); //constructor del jugador
sfSprite* GetSpriteJugador_1(); //obtenemos el sprite del jugador
void MoverJugador_1(int num_direction); //movemos al jugador

#endif //JUGADOR_PRUEBA_H
