//
// Created by Yonathan Monge on 23/5/2024.
//

#ifndef JUGADOR_2_H
#define JUGADOR_2_H

#include <SFML/Graphics.h>

//Estructura del jugador
typedef struct {
    sfSprite* sprt_jugador_2;
    sfTexture* txtr_jugador;
}Jugador_2;
//Metodos del jugador 2
Jugador_2* crearJugador_2(char* ColorCarro); //constructor del jugador 2
sfSprite* GetSpriteJugador_2(); //obtenemos el sprite del jugador 2
void MoverJugador_2(int num_direction); //movemos al jugador 2


#endif //JUGADOR_2_H
