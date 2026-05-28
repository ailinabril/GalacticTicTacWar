#pragma once

#include <SFML/Graphics.hpp>

#include "Tablero.h"
#include "Turnos.h"

class TableroGrafico
{
private:

    // LOGICA

    Tablero _tablero;

    Turnos _turnos;

    // TABLERO

    char _contenidoDelTablero[3][3];

    sf::RectangleShape _cuadradosDelTablero[3][3];

    // TEXTURAS

    sf::Texture _texturaFondo;

    sf::Texture _texturaNave;

    sf::Texture _texturaHumano;

    sf::Texture _texturaAlien;

    sf::Texture _texturaBomba;

    sf::Texture _texturaMina;

    sf::Texture _texturaTorre;

    // SPRITES PRINCIPALES

    sf::Sprite *_imagenDeFondo;

    sf::Sprite *_naveEspacial;

    // PERSONAJES

    sf::Sprite *_imagenesHumanos[3][3];

    sf::Sprite *_imagenesAliens[3][3];

    // OBJETOS HUMANO

    sf::Sprite *_spriteBombaHumano;

    sf::Sprite *_spriteMinaHumano;

    sf::Sprite *_spriteTorreHumano;

    // OBJETOS ALIEN

    sf::Sprite *_spriteBombaAlien;

    sf::Sprite *_spriteMinaAlien;

    sf::Sprite *_spriteTorreAlien;

    // TURNOS

    bool _esTurnoHumano;

    bool _juegoTerminado;

    // CANTIDAD FICHAS

    int _cantidadFichasHumano;

    int _cantidadFichasAlien;

    // SELECCION

    bool _hayFichaSeleccionada;

    int _filaSeleccionada;

    int _columnaSeleccionada;

    // NAVE

    float _posicionNaveX;

    // ENERGIA

    sf::RectangleShape _barraEnergiaHumano;

    sf::RectangleShape _fondoBarraEnergiaHumano;

    sf::RectangleShape _barraEnergiaAlien;

    sf::RectangleShape _fondoBarraEnergiaAlien;

    sf::Font _fuente;

    sf::Text *_textoGanador;

    // OBJETO

    int _objetoSeleccionado;

public:

    // CONSTRUCTOR

    TableroGrafico();

    // ACTUALIZAR

    void actualizar();

    // DIBUJAR

    void dibujarTablero(
        sf::RenderWindow &ventana
    );

    // CLICK MOUSE

    void procesarClickDelMouse(
        const sf::Event &evento,
        sf::RenderWindow &ventana
    );

    // VICTORIA

    bool verificarVictoria(
        char simboloJugador
    );

    // TABLERO LLENO

    bool tableroLleno();

    // REINICIAR

    void reiniciarTablero();

    // DESTRUCTOR

    ~TableroGrafico();
};
