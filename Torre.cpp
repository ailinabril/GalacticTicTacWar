#include "Torre.h"

#include <iostream>

using namespace std;

Torre::Torre():ObjetoEspecial(30,"TORRE")
{
     if (!_textura.loadFromFile("torre.png"))
    {
        cout << "ERROR TORRE" << endl;
    }

    _sprite = new sf::Sprite(_textura);

    _sprite->setScale(sf::Vector2f(0.18f,0.18f));
}


bool Torre::aplicarEfecto(Tablero &tablero,int fila,int columna,char simboloJugador)
{
    cout << "TORRE ACTIVADA" << endl;

    return true;
}

void Torre::dibujar(sf::RenderWindow &ventana)
{
    ventana.draw(*_sprite);
}


void Torre::setPosicion(float x,float y)
{
    _sprite->setPosition(sf::Vector2f(x,y));
};
