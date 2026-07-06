#pragma once
#include <SFML/Graphics.hpp>

class Turnos {
private:
    int _turnoActual;
    char _jugadorActual;
    sf::Font _fuente;
    sf::Text *_textoTurno;

public:
    //constructores
    Turnos();

    void siguienteTurno();
    void dibujar(sf::RenderWindow &ventana);

    int getTurnoActual();
    char getJugadorActual();
    ~Turnos();

};
