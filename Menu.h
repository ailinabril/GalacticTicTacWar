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
    // RECURSOS GRAFICOS
    //------------------------------------------------------------
    sf::Texture _texturaMenu;
    sf::Texture _texturaContrato;
    sf::Texture _texturaRanking;
    sf::Texture _texturaReglas;

    sf::Sprite* _spriteMenu;
    sf::Sprite* _spriteContrato;
    sf::Sprite* _spriteRanking;
    sf::Sprite* _spriteReglas;

    sf::Font _fuente;

    //------------------------------------------------------------
    // TEXTOS
    //------------------------------------------------------------
    sf::Text* _textoReglas;
    sf::Text* _textoPantallaRanking;
    sf::Text* _textoBotonVolver;
    sf::Text* _textoContrato;

    //------------------------------------------------------------
    // NOMBRE DEL JUGADOR
    //------------------------------------------------------------
    char _nombreJugador[30];

    int _cantidadCaracteres;

    sf::Text* _textoNombreJugador;

    //------------------------------------------------------------
    // BOTON VOLVER
    //------------------------------------------------------------
    sf::RectangleShape _botonVolver;

public:

    //------------------------------------------------------------
    // CONSTRUCTOR
    //------------------------------------------------------------
    Menu();

    //------------------------------------------------------------
    // PROCESA LOS CLICS DEL MENÚ
    //------------------------------------------------------------
    int procesarClick(sf::Vector2i posicionMouse);

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

    //------------------------------------------------------------
    // DIBUJA LA PANTALLA DEL CONTRATO
    //------------------------------------------------------------
    void dibujarContrato(sf::RenderWindow& ventana);

    //------------------------------------------------------------
    // VERIFICA SI SE PRESIONÓ EL BOTÓN VOLVER
    //------------------------------------------------------------
    bool PresionoBotonVolver(sf::Vector2i posicionMouse);

    //------------------------------------------------------------
    // VERIFICA SI SE PRESIONÓ EL BOTÓN CONFIRMAR
    //------------------------------------------------------------
    bool PresionoBotonConfirmar(sf::Vector2i posicionMouse);


    //------------------------------------------------------------
    // AGREGA UNA LETRA AL NOMBRE DEL JUGADOR
    //------------------------------------------------------------
    void AgregarCaracter(char letra);

    //------------------------------------------------------------
    // BORRA EL ULTIMO CARACTER
    //------------------------------------------------------------
    void BorrarCaracter();

    //------------------------------------------------------------
    // DEVUELVE EL NOMBRE INGRESADO
    //------------------------------------------------------------
    const char* getNombreJugador();

    //------------------------------------------------------------
    // GUARDA EL JUGADOR DEL CONTRATO
    //------------------------------------------------------------
    void ConfirmarContrato();

};
