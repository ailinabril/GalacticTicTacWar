#ifndef RANKINGGRAFICO_H_INCLUDED
#define RANKINGGRAFICO_H_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>
#include "ArchivoJugadores.h"

class RankingGrafico
{
private:
    // Archivo donde se almacenan los jugadores
    ArchivoJugadores _archivoJugadores;

    // Fuente utilizada para mostrar el ranking
    sf::Font _fuente;

public:
    // Constructor
    RankingGrafico();

    // Dibuja el ranking en la ventana
    void dibujar(sf::RenderWindow& ventana);
};
