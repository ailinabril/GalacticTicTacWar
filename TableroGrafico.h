#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "KlosterCode.h"
#include "Tablero.h"
#include "Turnos.h"
#include "Juego.h"

class TableroGrafico
{
private:
    // LOGICA
    Tablero _tablero;
    Turnos _turnos;
    Juego _juego;

    // TABLERO
    sf::RectangleShape _cuadradosDelTablero[3][3];

    // TEXTURAS
    Klostercode _klosterCode;
    sf::Texture _texturaFondo;
    sf::Texture _texturaNave;
    sf::Texture _texturaHumano;
    sf::Texture _texturaAlien;
    sf::Texture _texturaBomba;
    sf::Texture _texturaAlienNormal;
    sf::Texture _texturaBossKloster;
    sf::Sprite *_spriteRival;
    sf::Texture _texturaMina;
    sf::Texture _texturaTorre;

    // SPRITES PRINCIPALES
    sf::Sprite *_imagenDeFondo;
    sf::Sprite *_naveEspacial;

    // Vero Random
    sf::Texture _texturaVero;
    sf::Sprite *_spriteVero;

    bool _mostrarVero;
    int _contadorVero;
    bool _veroYaAparecio;

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

    // MARCOS OBJETOS HUMANO
    sf::RectangleShape _marcoBombaHumano;
    sf::RectangleShape _marcoMinaHumano;
    sf::RectangleShape _marcoTorreHumano;

    // MARCOS OBJETOS ALIEN
    sf::RectangleShape _marcoBombaAlien;
    sf::RectangleShape _marcoMinaAlien;
    sf::RectangleShape _marcoTorreAlien;

    // TURNOS
    bool _esTurnoHumano;
    bool _juegoTerminado;

    // VICTORIAS
    int _victoriasHumanos;
    int _victoriasAliens;

    sf::Text *_textoVictoriasHumanos;
    sf::Text *_textoVictoriasAliens;

    //------------------------------------------------------------
    // SERIE AL MEJOR DE TRES
    //------------------------------------------------------------
    int _numeroPartida;
    bool _serieTerminada;
    bool _esperandoVolverMenu;

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

    // COSTO DE ENERGIA OBJETOS HUMANO
    sf::Text *_textoCostoBombaHumano;
    sf::Text *_textoCostoMinaHumano;
    sf::Text *_textoCostoTorreHumano;

    // COSTO DE ENERGIA OBJETOS ALIEN
    sf::Text *_textoCostoBombaAlien;
    sf::Text *_textoCostoMinaAlien;
    sf::Text *_textoCostoTorreAlien;

    // OBJETO
    int _objetoSeleccionado;

    //"PENSAMIENTO" DE LA CPU
    bool _cpuPensando;
    sf::Clock _relojCPU;

public:
    // JUEGA LA CPU
    void turnoCPU();

    // CONSTRUCTOR
    TableroGrafico();

    // ACTUALIZAR
    void actualizar();

    // DIBUJAR
    void dibujarTablero(sf::RenderWindow &ventana);

    bool SerieTerminada() const;


    void ReiniciarSerie();

    // CLICK MOUSE
    void procesarClickDelMouse(const sf::Event &evento,sf::RenderWindow &ventana);

    // REINICIA EL TABLERO PARA LA SIGUIENTE PARTIDA

    void reiniciarPartida();

    // VICTORIA
    void procesarLetraKloster(char letra);

     //selecciona un objeto especial
    void SeleccionarObjeto(int objeto);

   //algo//
    void IniciarPartida(const char* nombre);


    // DESTRUCTOR
    ~TableroGrafico();


};
