#include "Turnos.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Turnos::Turnos(){
    _turnoActual = 1;
    _jugadorActual = 'H';
     if (!_fuente.openFromFile("Orbitron-Regular.ttf"))
    {
        cout << "ERROR FUENTE TURNOS" << endl;
    }

    // TEXTO

    _textoTurno =new sf::Text(_fuente,"TURNO HUMANOS",25);

    _textoTurno->setFillColor(sf::Color::Cyan);

    _textoTurno->setPosition(sf::Vector2f(520.f,620.f));
}

void Turnos::siguienteTurno()
{
    _turnoActual++;

    if (_jugadorActual == 'X')
    {
        _jugadorActual = 'O';

        _textoTurno->setString("TURNO HUMANOS");

        _textoTurno->setFillColor(sf::Color::Cyan);
    }
    else
    {
        _jugadorActual = 'X';

        _textoTurno->setString("TURNO ALIENS");

        _textoTurno->setFillColor(sf::Color(180,0,255));
    }
}

void Turnos::actualizar(){}

void Turnos::dibujar(sf::RenderWindow &ventana){
 ventana.draw(*_textoTurno);
 }

int Turnos::getTurnoActual(){
    return _turnoActual;
}
char Turnos::getJugadorActual(){
    return _jugadorActual;
}

Turnos::~Turnos()
{
    delete _textoTurno;
}
