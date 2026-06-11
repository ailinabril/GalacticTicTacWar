#pragma once
#include <iostream>
#include "Juego.h"
#include <SFML/Graphics.hpp>

class Menu {
private:
    Juego _juego;
    sf::Texture _texturaMenu;
    sf::Sprite *_spriteMenu;
    sf::Font _fuente;
    sf::Text *_textoReglas;


public:
    int procesarClick(sf::Vector2i mouse);
    void IniciarMenu();
    void MostrarOpciones();
    void LeerOpcion();
    void MostrarReglas();
    void MostrarRanking();
    Menu();
    void dibujar(sf::RenderWindow &ventana);
    void dibujarReglas(sf::RenderWindow &ventana);

};
