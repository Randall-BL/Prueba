//
// Created by Yonathan Monge on 29/5/2024.
//

#ifndef MAPA_3_H
#define MAPA_3_H
#include <SFML/Graphics.h>

// Estructura para las líneas del mapa
typedef struct {
    float x, z; // centro de las lineas
    float X, Y, W; // coordenadas de la pantala
    float curve, spriteX, clip, scale;
    sfSprite* sprite;
} Line_3;

// Funciones
void drawQuad_3(sfRenderWindow* w, sfColor c, int x1, int y1, int w1, int x2, int y2, int w2);
void project_3(Line_3* line, int camX, int camY, int camZ);
void drawSprite_3(Line_3* line, sfRenderWindow* app);
void Ejecutar_Mapa3(sfRenderWindow* ventana_juego);

#endif //MAPA_3_H
