#include "Turnos.h"
#include <SFML/Graphics.hpp>

using namespace std;

Turnos::Turnos(){
    _turnoActual = 1;
    _jugadorActual = 'H';
}

void Turnos::siguienteTurno(){
    if(_jugadorActual == 'H'){
        _jugadorActual = 'A';
    }
    else {
        _jugadorActual = 'H';
    }

    _turnoActual++;
}

void Turnos::actualizar(){}

void Turnos::dibujar(sf::RenderWindow &ventana){}

int Turnos::getTurnoActual(){
    return _turnoActual;
}
char Turnos::getJugadorActual(){
    return _jugadorActual;
}
