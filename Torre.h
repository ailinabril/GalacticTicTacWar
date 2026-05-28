#pragma once
#include "ObjetoEspecial.h"
#include <SFML/Graphics.hpp>

class Torre : public ObjetoEspecial{
private:
    sf::Texture _textura;

    sf::Sprite *_sprite;


public:

    //constructores


    Torre(); //constructor por defecto

    //polimorfismo dinamico
    //sobre escribe el metodo del padre
    bool aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador) override;
    //aplica el efecto de la torre en la posición indicada, bloqueando esa casilla para ambos jugadores

     void dibujar(sf::RenderWindow &ventana);

    // POSICION

    void setPosicion(float x,float y);
};
