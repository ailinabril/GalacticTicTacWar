#pragma once

#include <SFML/Graphics.hpp>

#include "Juego.h"
#include "ArchivoJugadores.h"

class Menu
{
private:

    //------------------------------------------------------------
    // LÓGICA
    //------------------------------------------------------------
    Juego _juego;
    ArchivoJugadores _archivoJugadores;

    //------------------------------------------------------------
    // RECURSOS GRÁFICOS
    //------------------------------------------------------------
    sf::Texture _texturaMenu;
    sf::Sprite* _spriteMenu;

    sf::Font _fuente;

    //------------------------------------------------------------
    // TEXTOS
    //------------------------------------------------------------
    sf::Text* _textoReglas;
    sf::Text* _textoPantallaRanking;

public:

    //------------------------------------------------------------
    // CONSTRUCTOR
    //------------------------------------------------------------
    Menu();

    //------------------------------------------------------------
    // PROCESA LOS CLICS DEL MENÚ
    //------------------------------------------------------------
    int procesarClick(sf::Vector2i mouse);

    //------------------------------------------------------------
    // DIBUJA EL MENÚ PRINCIPAL
    //------------------------------------------------------------
    void dibujar(sf::RenderWindow& ventana);

    //------------------------------------------------------------
    // DIBUJA LA PANTALLA DE REGLAS
    //------------------------------------------------------------
    void dibujarReglas(sf::RenderWindow& ventana);

    //------------------------------------------------------------
    // DIBUJA LA PANTALLA DE RANKING
    //------------------------------------------------------------
    void dibujarRanking(sf::RenderWindow& ventana);
};
