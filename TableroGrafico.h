#pragma once

#include <SFML/Graphics.hpp>
#include "Tablero.h"
#include "Turnos.h"
#include <optional>

class TableroGrafico
{
private:

    Tablero _tablero;

    Turnos _turnos;

    char _contenidoDelTablero[3][3];

    sf::RectangleShape _cuadradosDelTablero[3][3];

    sf::Texture _texturaFondo;

    sf::Texture _texturaNave;

    sf::Texture _texturaHumano;

    sf::Texture _texturaAlien;

    std::optional<sf::Sprite> _imagenDeFondo;  //sprites del juego

    std::optional<sf::Sprite> _naveEspacial;

    std::optional<sf::Sprite> _imagenesHumanos[3][3];

    std::optional<sf::Sprite> _imagenesAliens[3][3];

    bool _esTurnoHumano;

    bool _juegoTerminado;

    int _cantidadFichasHumano;

    int _cantidadFichasAlien;

// ficha seleccionada para mover

    bool _hayFichaSeleccionada;

    int _filaSeleccionada;

    int _columnaSeleccionada;

    float _posicionNaveX;  // movimiento de la nave

    sf::RectangleShape _barraEnergiaHumano;    // barra de energia humana

    sf::RectangleShape _fondoBarraEnergiaHumano;   // fondo de energia

    sf::RectangleShape _barraEnergiaAlien;

    sf::RectangleShape _fondoBarraEnergiaAlien;

public:

    Tablero();

    void actualizar();

    void dibujarTablero(sf::RenderWindow &ventana);

    void procesarClickDelMouse(const sf::Event &evento,sf::RenderWindow &ventana);

    bool verificarVictoria(char simboloJugador);

    bool tableroLleno();

    void reiniciarTablero();
};
