#pragma once
#include <SFML/Graphics.hpp>

class Turnos {
private:
    int _turnoActual;
    char _jugadorActual;

public:
    //constructores
    Turnos();

    void siguienteTurno();
    void actualizar();
    void dibujar(sf::RenderWindow &ventana);

    int getTurnoActual();
    char getJugadorActual();

};
