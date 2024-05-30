//
// Created by Yonathan Monge on 23/5/2024.
//

#include "../headers/Jugador_2.h"

#include <stdlib.h>
#include <string.h>

//Variable global para almacenar la referencia del jugador
static Jugador_2* jugador_3_global = NULL;
Jugador_2 * crearJugador_2(char* ColorCarro) {
    jugador_3_global = (Jugador_2*)malloc(sizeof(Jugador_2));

    //textura del sprite
    char direccion_txtr2[]= "../Recursos/Jugador_prueba.png";
    sfTexture* txtr_jugador_2 = sfTexture_createFromFile(direccion_txtr2, NULL);

    //sprite
    sfSprite* sprt_jugador_2 = sfSprite_create();

    sfSprite_setTexture(sprt_jugador_2, txtr_jugador_2, sfTrue);
    sfSprite_setPosition(sprt_jugador_2, (sfVector2f){460, 925});
    sfSprite_setScale(sprt_jugador_2, (sfVector2f){2.0f, 2.0f});
    if (strstr(ColorCarro, "Red")) {
        sfSprite_setColor(sprt_jugador_2, sfRed);
    } else if (strstr(ColorCarro, "Blue")) {
        sfSprite_setColor(sprt_jugador_2, sfBlue);
    } else if (strstr(ColorCarro, "White")) {
        sfSprite_setColor(sprt_jugador_2, sfWhite);
    } else if (strstr(ColorCarro, "Purple")) {
        sfSprite_setColor(sprt_jugador_2, sfMagenta);
    }

    //punto de origen del sprite en el centro
    sfVector2u txtr_size = sfTexture_getSize(txtr_jugador_2);
    sfSprite_setOrigin(sprt_jugador_2, (sfVector2f){txtr_size.x / 2, txtr_size.y / 2});

    //Guardamos la referencia del sprite en la variable global
    jugador_3_global->sprt_jugador_2 = sprt_jugador_2;

    return  jugador_3_global;
}
//metodo que retorna el sprite del jugador 2 a la ventana que lo requiera
sfSprite * GetSpriteJugador_2() {
    if (jugador_3_global != NULL) {
        return jugador_3_global->sprt_jugador_2;
    }
    return NULL;
}

void MoverJugador_2(int num_direction) {
    if (jugador_3_global != NULL) {
        sfVector2f pos = sfSprite_getPosition(jugador_3_global->sprt_jugador_2);
        switch (num_direction) {
            case 5:
                pos.y -= 15;
            break;
            case 6:
                pos.y += 15;
            break;
            case 7:
                pos.x -= 15;
            break;
            case 8:
                pos.x += 15;
            break;
        }
        sfSprite_setPosition(jugador_3_global->sprt_jugador_2, pos);
    }
}
