//
// Created by Yonathan Monge on 29/5/2024.
//

#include "../headers/Mapa_1.h"
#include <math.h>
#include <stdio.h>

int width_1 = 980;
int height_1 = 1020;
int roadW_1 = 2000;
int segL_1 = 200; // segment length
float camD_1 = 0.84; // camera depth

// Función para dibujar un cuadrado
void drawQuad_1(sfRenderWindow* w, sfColor c, int x1, int y1, int w1, int x2, int y2, int w2) {
    sfVertexArray* quad = sfVertexArray_create();
    sfVertex v1 = { { x1 - w1, y1 }, c, { 0, 0 } };
    sfVertex v2 = { { x2 - w2, y2 }, c, { 0, 0 } };
    sfVertex v3 = { { x2 + w2, y2 }, c, { 0, 0 } };
    sfVertex v4 = { { x1 + w1, y1 }, c, { 0, 0 } };
    sfVertexArray_append(quad, v1);
    sfVertexArray_append(quad, v2);
    sfVertexArray_append(quad, v3);
    sfVertexArray_append(quad, v4);
    sfVertexArray_setPrimitiveType(quad, sfQuads);
    sfRenderWindow_drawVertexArray(w, quad, NULL);
    sfVertexArray_destroy(quad);
}

// Función para proyectar una línea en coordenadas de pantalla
void project_1(Line_1* line, int camX, int camY, int camZ) {
    line->scale = camD_1 / (line->z - camZ);
    line->X = (1 + line->scale * (line->x - camX)) * width_1 / 2;
    line->Y = (1 - line->scale * (0 - camY)) * height_1 / 2;
    line->W = line->scale * roadW_1 * width_1 / 2;
}

// Función para dibujar un sprite en una línea
void drawSprite_1(Line_1* line, sfRenderWindow* app) {
    if (!line->sprite) return;

    sfSprite* s = line->sprite;
    sfFloatRect spriteBounds = sfSprite_getLocalBounds(s);
    int w = spriteBounds.width;
    int h = spriteBounds.height;

    float destX = line->X + line->scale * line->spriteX * width_1 / 2;
    float destY = line->Y + 4;
    float destW = w * line->W / 266;
    float destH = h * line->W / 266;

    destX += destW * line->spriteX;
    destY += destH * (-1);

    float clipH = destY + destH - line->clip;
    if (clipH < 0) clipH = 0;
    if (clipH >= destH) return;

    sfSprite_setScale(s, (sfVector2f){ destW / w, destH / h });
    sfSprite_setPosition(s, (sfVector2f){ destX, destY });
    sfRenderWindow_drawSprite(app, s, NULL);
}

// Función para ejecutar el Mapa 1
void Ejecutar_Mapa1(sfRenderWindow* ventana_juego) {
    static sfTexture* t = NULL;
    static sfSprite* Jugador_1 = NULL;
    static sfSprite* Jugador_2 = NULL;
    static sfSprite* Jugador_3 = NULL;
    static Line_1 lines[1600];
    static int initialized = 0;
    static int spriteSegment1 = 7;
    static int spriteSegment2 = 7;
    static int spriteSegment3 = 7;
    static int N = 1600;
    static float playerX = 0;
    static int pos = 0;
    static int H = 1500;

    // Inicializar recursos una sola vez
    if (!initialized) {
        t = sfTexture_createFromFile("../Recursos/Jugador_prueba.png", NULL);

        Jugador_1 = sfSprite_create();
        sfSprite_setTexture(Jugador_1, t, sfTrue);
        sfFloatRect spriteBounds1 = sfSprite_getLocalBounds(Jugador_1);
        sfSprite_setOrigin(Jugador_1, (sfVector2f){ spriteBounds1.width / 2, spriteBounds1.height / 2 });

        Jugador_2 = sfSprite_create();
        sfSprite_setTexture(Jugador_2, t, sfTrue);
        sfFloatRect spriteBounds2 = sfSprite_getLocalBounds(Jugador_2);
        sfSprite_setOrigin(Jugador_2, (sfVector2f){ spriteBounds2.width / 2, spriteBounds2.height / 2 });

        Jugador_3 = sfSprite_create();
        sfSprite_setTexture(Jugador_3, t, sfTrue);
        sfFloatRect spriteBounds3 = sfSprite_getLocalBounds(Jugador_3);
        sfSprite_setOrigin(Jugador_3, (sfVector2f){ spriteBounds3.width / 2, spriteBounds3.height / 2 });

        for (int i = 0; i < 1600; i++) {
            lines[i].x = 0;
            lines[i].z = i * segL_1;
            lines[i].spriteX = 0;
            lines[i].curve = 0;
            lines[i].sprite = NULL;
            if (i > 300 && i < 700) lines[i].curve = 0.5;
            if (i > 1100) lines[i].curve = -0.7;
        }
        lines[spriteSegment1].sprite = Jugador_1; // Inicializa el sprite del jugador 1
        lines[spriteSegment1].spriteX = -0.5;

        lines[spriteSegment2].sprite = Jugador_2; // Inicializa el sprite del jugador 2
        lines[spriteSegment2].spriteX = -0.5;

        lines[spriteSegment3].sprite = Jugador_3; // Inicializa el sprite del jugador 3
        lines[spriteSegment3].spriteX = -0.5;

        initialized = 1;
    }

    int speed = 0;

    // Movimiento del Jugador 1
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        if (playerX < 0.9) playerX += 0.08;
    }
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        if (playerX > -0.9) playerX -= 0.08;
    }
    if (sfKeyboard_isKeyPressed(sfKeyW)) speed = 200;
    if (sfKeyboard_isKeyPressed(sfKeyS)) speed = -200;

    float currentSpriteX1 = lines[spriteSegment1].spriteX;
    float currentSpriteX2 = lines[spriteSegment2].spriteX;
    float currentSpriteX3 = lines[spriteSegment3].spriteX;

    // Mover el sprite del Jugador 1 hacia adelante o hacia atrás en respuesta a las teclas "W" y "S"
    if (sfKeyboard_isKeyPressed(sfKeyW)) {
        lines[spriteSegment1].sprite = NULL;
        spriteSegment1++;
        if (spriteSegment1 >= N) spriteSegment1 = 0;
        lines[spriteSegment1].sprite = Jugador_1;
        lines[spriteSegment1].spriteX = currentSpriteX1;
    }

    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        lines[spriteSegment1].sprite = NULL;
        spriteSegment1--;
        if (spriteSegment1 < 0) spriteSegment1 = N - 1;
        lines[spriteSegment1].sprite = Jugador_1;
        lines[spriteSegment1].spriteX = currentSpriteX1;
    }

    // Mover el sprite del Jugador 2 hacia adelante o hacia atrás en respuesta a las teclas "Up" y "Down"
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        lines[spriteSegment2].sprite = NULL;
        spriteSegment2++;
        if (spriteSegment2 >= N) spriteSegment2 = 0;
        lines[spriteSegment2].sprite = Jugador_2;
        lines[spriteSegment2].spriteX = currentSpriteX2;
    }

    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        lines[spriteSegment2].sprite = NULL;
        spriteSegment2--;
        if (spriteSegment2 < 0) spriteSegment2 = N - 1;
        lines[spriteSegment2].sprite = Jugador_2;
        lines[spriteSegment2].spriteX = currentSpriteX2;
    }

    // Mover el sprite del Jugador 3 hacia adelante o hacia atrás en respuesta a las teclas "I" y "K"
    if (sfKeyboard_isKeyPressed(sfKeyI)) {
        lines[spriteSegment3].sprite = NULL;
        spriteSegment3++;
        if (spriteSegment3 >= N) spriteSegment3 = 0;
        lines[spriteSegment3].sprite = Jugador_3;
        lines[spriteSegment3].spriteX = currentSpriteX3;
    }

    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        lines[spriteSegment3].sprite = NULL;
        spriteSegment3--;
        if (spriteSegment3 < 0) spriteSegment3 = N - 1;
        lines[spriteSegment3].sprite = Jugador_3;
        lines[spriteSegment3].spriteX = currentSpriteX3;
    }

    // Mover los sprites hacia la izquierda o derecha
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        lines[spriteSegment1].spriteX -= 0.4;
        if (lines[spriteSegment1].spriteX < -4.5) lines[spriteSegment1].spriteX = -4.5;
    }

    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        lines[spriteSegment1].spriteX += 0.4;
        if (lines[spriteSegment1].spriteX > 4.5) lines[spriteSegment1].spriteX = 4.5;
    }

    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        lines[spriteSegment2].spriteX -= 0.4;
        if (lines[spriteSegment2].spriteX < -4.5) lines[spriteSegment2].spriteX = -4.5;
    }

    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        lines[spriteSegment2].spriteX += 0.4;
        if (lines[spriteSegment2].spriteX > 4.5) lines[spriteSegment2].spriteX = 4.5;
    }

    if (sfKeyboard_isKeyPressed(sfKeyJ)) {
        lines[spriteSegment3].spriteX -= 0.4;
        if (lines[spriteSegment3].spriteX < -4.5) lines[spriteSegment3].spriteX = -4.5;
    }

    if (sfKeyboard_isKeyPressed(sfKeyL)) {
        lines[spriteSegment3].spriteX += 0.4;
        if (lines[spriteSegment3].spriteX > 4.5) lines[spriteSegment3].spriteX = 4.5;
    }

    if (sfKeyboard_isKeyPressed(sfKeyTab)) speed *= 3;

    pos += speed;
    while (pos >= N * segL_1) pos -= N * segL_1;
    while (pos < 0) pos += N * segL_1;

    int startPos = pos / segL_1;
    int camH = H;

    int maxy = height_1;
    float x = 0, dx = 0;

    // Dibujar la carretera
    for (int n = startPos; n < startPos + 300; n++) {
        Line_1* l = &lines[n % N];
        project_1(l, playerX * roadW_1 - x, camH, startPos * segL_1 - (n >= N ? N * segL_1 : 0));
        x += dx;
        dx += l->curve;

        l->clip = maxy;
        if (l->Y >= maxy) continue;
        maxy = l->Y;

        sfColor grass = (n / 3) % 2 ? sfColor_fromRGB(16, 200, 16) : sfColor_fromRGB(0, 154, 0);
        sfColor rumble = (n / 3) % 2 ? sfColor_fromRGB(255, 255, 255) : sfColor_fromRGB(0, 0, 0);
        sfColor road = (n / 3) % 2 ? sfColor_fromRGB(107, 107, 107) : sfColor_fromRGB(105, 105, 105);

        Line_1* p = &lines[(n - 1) % N];
        drawQuad_1(ventana_juego, grass, 0, p->Y, width_1, 0, l->Y, width_1);
        drawQuad_1(ventana_juego, rumble, p->X, p->Y, p->W * 1.2, l->X, l->Y, l->W * 1.2);
        drawQuad_1(ventana_juego, road, p->X, p->Y, p->W, l->X, l->Y, l->W);
    }

    // Dibujar los objetos únicos (sprites)
    drawSprite_1(&lines[spriteSegment1], ventana_juego);
    drawSprite_1(&lines[spriteSegment2], ventana_juego);
    drawSprite_1(&lines[spriteSegment3], ventana_juego);

}