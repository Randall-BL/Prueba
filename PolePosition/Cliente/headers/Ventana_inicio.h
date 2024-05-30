//
// Created by Yonathan Monge on 19/5/2024.
//

#ifndef VENTANA_INICIO_H
#define VENTANA_INICIO_H
#include <winsock2.h>
#include <SFML/Graphics.h> //incluimos la libreria de SFML

typedef struct {
    sfRenderWindow* ventana_inicio;  //ventana de inicio
    sfEvent events; //evento de la ventana

    sfSprite *sprt_carros; //sprite de los carros

    sfRectangleShape *btn_selec_carroR; //boton de seleccionar el carro
    sfRectangleShape *btn_selec_carroA; //boton de seleccionar el carro
    sfRectangleShape *btn_selec_carroM; //boton de seleccionar el carro
    sfRectangleShape *btn_selec_carroB; //boton de seleccionar el carro
    sfRectangleShape *btn_inicio_partida; //boton de inicio de partida
}Ventana_inicio;

Ventana_inicio* crearVentanaInicio(); //creamos la ventana de inicio
void Eventos(Ventana_inicio* ventana_inicio); //manejamos los eventos de la ventana de inicio
void Ciclar(Ventana_inicio* ventana_inicio); //ciclamos la ventana de inicio (aqui van los metodos de renderizado y eventos es decir, bucle de la ventana )
void Renderizar(Ventana_inicio* ventana_inicio); //renderizamos la ventana de inicio
//mas metodos aqui:

#endif //VENTANA_INICIO_H