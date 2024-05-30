//
// Created by Yonathan Monge on 27/5/2024.
//

#ifndef JUGADOR_3_H
#define JUGADOR_3_H

#include <SFML/Graphics.h>

//Estructura del jugador
typedef struct {
    sfSprite* sprt_jugador_3;
    sfTexture* txtr_jugador;
}Jugador_3;
//Metodos del jugador 2
Jugador_3* crearJugador_3(char* ColorCarro); //constructor del jugador 2
sfSprite* GetSpriteJugador_3(); //obtenemos el sprite del jugador 2
void MoverJugador_3(int num_direction); //movemos al jugador 2


#endif //JUGADOR_3_H
