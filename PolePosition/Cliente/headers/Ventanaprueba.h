#ifndef VENTANAPRUEBA_H
#define VENTANAPRUEBA_H

#include <SFML/Graphics.h>
#include <math.h>

// Definiciones para compensar la falta de stdbool.h
typedef int bool;
#define true 1
#define false 0


#define PI 3.14159265358979323846
#define NUM_RAYS 60
#define FOV (PI / 3)  // Campo de visión de 60 grados
#define MAX_DEPTH 20  // Máxima profundidad de visión
#define MAX_WIDTH 200
#define MAX_HEIGHT 200

typedef struct {
    sfRenderWindow* ventana;
    sfColor color;
    sfEvent evento;
    char mapa[MAX_HEIGHT][MAX_WIDTH];
    float carroX, carroY; // Coordenadas del carro en el mapa
    float playerAngle;  // Ángulo de visión del jugador
} VentanaPrueba;

VentanaPrueba* crearVentanaPrueba(sfColor);
void ciclarVentana(VentanaPrueba* ventana);
void manejarEventos(VentanaPrueba* ventana);
void renderizar(VentanaPrueba* ventana);
void cargarMapa(VentanaPrueba* ventana, const char* nombreArchivo);
void castRays(sfRenderWindow* window, VentanaPrueba* game); // Función de raycasting
void renderCarro(VentanaPrueba* ventana); // Función para renderizar el carro
void renderMinimap(VentanaPrueba* ventana); // Función para renderizar el minimapa

#endif // VENTANAPRUEBA_H
