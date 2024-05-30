//
// Created by Yonathan Monge on 23/5/2024.
//
#include "../headers/Jugador_1.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variable global para almacenar la referencia del jugador
static Jugador_1* jugador_1_global = NULL;

Jugador_1* crearJugador_1(char* ColorCarro) {
    jugador_1_global = (Jugador_1*)malloc(sizeof(Jugador_1));
    //creamos el sprite del jugador 1
    sfSprite* sprt_jugador_1 = sfSprite_create();

    char direccion_txtr1[]= "../Recursos/Jugador_prueba.png";
    sfTexture* txtr_jugador_1 = sfTexture_createFromFile(direccion_txtr1, NULL);

    // le damos la textura al sprite, posicion y punto de rotacion
    sfSprite_setTexture(sprt_jugador_1, txtr_jugador_1, sfTrue);
    sfSprite_setPosition(sprt_jugador_1, (sfVector2f){460, 925});
    sfSprite_setScale(sprt_jugador_1, (sfVector2f){2.0f, 2.0f});

    //dependiendo del color enviado del servidor se le asigna un color al sprite del carro
    if (strstr(ColorCarro, "Red")) {
        sfSprite_setColor(sprt_jugador_1, sfRed);
    } else if (strstr(ColorCarro, "Blue")) {
        sfSprite_setColor(sprt_jugador_1, sfBlue);
    } else if (strstr(ColorCarro, "White")) {
        sfSprite_setColor(sprt_jugador_1, sfWhite);
    } else if (strstr(ColorCarro, "Purple")) {
        sfSprite_setColor(sprt_jugador_1, sfMagenta);
    }

    //punto de origen del sprite en el centro
    sfVector2u txtr_size = sfTexture_getSize(txtr_jugador_1);
    sfSprite_setOrigin(sprt_jugador_1, (sfVector2f){txtr_size.x / 2, txtr_size.y / 2});

    //Guardamos la referencia del sprite en la variable global
    jugador_1_global->sprt_jugador_1 = sprt_jugador_1;

    return jugador_1_global;
}

sfSprite* GetSpriteJugador_1() {
    if (jugador_1_global != NULL) {
        return jugador_1_global->sprt_jugador_1;
    }
    return NULL;
}


void MoverJugador_1(int num_direction) {
    if (jugador_1_global != NULL) {
        sfVector2f pos = sfSprite_getPosition(jugador_1_global->sprt_jugador_1);
        switch (num_direction) {
            case 1:
                pos.y -= 15;
                break;
            case 2:
                pos.y += 15;
                break;
            case 3:
                pos.x -= 15;
                break;
            case 4:
                pos.x += 15;
                break;
        }
        sfSprite_setPosition(jugador_1_global->sprt_jugador_1, pos);
    }
}
