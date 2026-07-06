#include "Turnos.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

Turnos::Turnos(){
    _turnoActual = 1;
    _jugadorActual = 'X';
     if (!_fuente.openFromFile("Orbitron-Regular.ttf"))
    {
        cout << "ERROR FUENTE TURNOS" << endl;
    }

    // TEXTO
    _textoTurno =new sf::Text(_fuente,"        HUMANOS",25);
    _textoTurno->setFillColor(sf::Color::Cyan);
    _textoTurno->setPosition(sf::Vector2f(500.f,640.f));
}

void Turnos::siguienteTurno()
{
    _turnoActual++;

    if (_jugadorActual == 'X')
    {
        _jugadorActual = 'O';
        _textoTurno->setString("        HUMANOS");
        _textoTurno->setFillColor(sf::Color::Cyan);
    }
    else
    {
        _jugadorActual = 'X';
        _textoTurno->setString("          ALIENS");
        _textoTurno->setFillColor(sf::Color::Green);
    }
}

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
