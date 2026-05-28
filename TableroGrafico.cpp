#include "TableroGrafico.h"
#include <iostream>

using namespace std;

TableroGrafico::TableroGrafico() //contructor
{
    // TURNOS

    _esTurnoHumano = true;

    _juegoTerminado = false;

    // FICHAS

    _cantidadFichasHumano = 0;

    _cantidadFichasAlien = 0;

    // SELECCION

    _hayFichaSeleccionada = false;

    _filaSeleccionada = -1;

    _columnaSeleccionada = -1;

    // OBJETO

    _objetoSeleccionado = 0;

    // TABLERO VACIO

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            _contenidoDelTablero[fila][columna] = ' ';
        }
    }

    // POSICION TABLERO

    float posicionInicialX = 305.f;

    float posicionInicialY = 110.f;

    float anchoCasilla = 240.f;

    float altoCasilla = 120.f;

    // CREAR CASILLAS

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            _cuadradosDelTablero[fila][columna].setSize(sf::Vector2f(anchoCasilla - 10.f,altoCasilla - 10.f));

            _cuadradosDelTablero[fila][columna].setPosition(sf::Vector2f(posicionInicialX + columna * anchoCasilla,posicionInicialY + fila * altoCasilla));

            _cuadradosDelTablero[fila][columna].setFillColor(sf::Color::Transparent);

            _cuadradosDelTablero[fila][columna].setOutlineThickness(3.f);

            _cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Transparent);
        }
    }

    // FONDO

    if (!_texturaFondo.loadFromFile("fondo.png"))
    {
        cout << "ERROR FONDO" << endl;
    }

    _imagenDeFondo = new sf::Sprite(_texturaFondo);

    // NAVE

    if (!_texturaNave.loadFromFile("nave.png"))
    {
        cout << "ERROR NAVE" << endl;
    }

    _naveEspacial =new sf::Sprite(_texturaNave);

    _posicionNaveX = 150.f;


    _naveEspacial->setPosition(sf::Vector2f(_posicionNaveX,40.f));

    _naveEspacial->setScale(sf::Vector2f(0.40f,0.40f));

    // FUENTE

    if (!_fuente.openFromFile("Orbitron-Regular.ttf"))
    {
        cout << "ERROR FUENTE" << endl;
    }

    // TEXTO GANADOR

  _textoGanador =new sf::Text(_fuente,"",55);

_textoGanador->setFillColor(sf::Color::Cyan);

_textoGanador->setPosition(sf::Vector2f(320.f,500.f));

    // ENERGIA HUMANO

    _fondoBarraEnergiaHumano.setSize(sf::Vector2f(220.f,24.f));

    _fondoBarraEnergiaHumano.setFillColor(sf::Color(40,40,40));

    _fondoBarraEnergiaHumano.setPosition(sf::Vector2f( 40.f,640.f));

    _barraEnergiaHumano.setSize(sf::Vector2f(210.f,14.f));

    _barraEnergiaHumano.setFillColor(sf::Color::Green);

    _barraEnergiaHumano.setPosition(sf::Vector2f(45.f,645.f));

    // ENERGIA ALIEN

    _fondoBarraEnergiaAlien.setSize(sf::Vector2f(220.f,24.f));

    _fondoBarraEnergiaAlien.setFillColor(sf::Color(40,40,40));

    _fondoBarraEnergiaAlien.setPosition(sf::Vector2f(1010.f,640.f));

    _barraEnergiaAlien.setSize(sf::Vector2f(210.f,14.f));

    _barraEnergiaAlien.setFillColor(sf::Color::Green);

    _barraEnergiaAlien.setPosition(sf::Vector2f(1015.f,645.f));

    // HUMANO

    if (!_texturaHumano.loadFromFile("O.png"))
    {
        cout << "ERROR HUMANO" << endl;
    }

    // ALIEN

    if (!_texturaAlien.loadFromFile("X.png"))
    {
        cout << "ERROR ALIEN" << endl;
    }

    // BOMBA

    if (!_texturaBomba.loadFromFile("bomba.png"))
    {
        cout << "ERROR BOMBA" << endl;
    }

    // MINA

    if (!_texturaMina.loadFromFile("mina.png"))
    {
        cout << "ERROR MINA" << endl;
    }

    // TORRE

    if (!_texturaTorre.loadFromFile("torre.png"))
    {
        cout << "ERROR TORRE" << endl;
    }

    // OBJETOS HUMANO

    _spriteBombaHumano =
        new sf::Sprite(_texturaBomba);

    _spriteMinaHumano =new sf::Sprite(_texturaMina);

    _spriteTorreHumano = new sf::Sprite(_texturaTorre);

    // OBJETOS ALIEN

    _spriteBombaAlien = new sf::Sprite(_texturaBomba);

    _spriteMinaAlien = new sf::Sprite(_texturaMina);

    _spriteTorreAlien = new sf::Sprite(_texturaTorre);

    // POSICIONES HUMANO

    _spriteBombaHumano->setPosition(sf::Vector2f(40.f,250.f));

    _spriteMinaHumano->setPosition(sf::Vector2f(40.f,360.f));

    _spriteTorreHumano->setPosition(sf::Vector2f(40.f,470.f));

    // POSICIONES ALIEN

    _spriteBombaAlien->setPosition(sf::Vector2f(1110.f,250.f));

    _spriteMinaAlien->setPosition(sf::Vector2f(1110.f,360.f));

    _spriteTorreAlien->setPosition(sf::Vector2f(1110.f,470.f));

    // ESCALAS

    _spriteBombaHumano->setScale(sf::Vector2f(0.06f,0.06f));

    _spriteMinaHumano->setScale(sf::Vector2f(0.06f,0.06f));

    _spriteTorreHumano->setScale(sf::Vector2f(0.06f,0.06f));

    _spriteBombaAlien->setScale(sf::Vector2f(0.06f,0.06f));

    _spriteMinaAlien->setScale(sf::Vector2f(0.06f,0.06f));

    _spriteTorreAlien->setScale(sf::Vector2f(0.06f,0.06f));

    // PERSONAJES

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            // HUMANOS

            _imagenesHumanos[fila][columna] = new sf::Sprite(_texturaHumano);

            _imagenesHumanos[fila][columna]->setScale(sf::Vector2f(0.14,0.14));

            // ALIENS

            _imagenesAliens[fila][columna] = new sf::Sprite(_texturaAlien);

            _imagenesAliens[fila][columna]->setScale(sf::Vector2f(0.12,0.12));

            // POSICION

            sf::Vector2f posicionCuadrado =

                _cuadradosDelTablero[fila][columna].getPosition();

            _imagenesHumanos[fila][columna]->setPosition(sf::Vector2f(posicionCuadrado.x + 5.f,posicionCuadrado.y - 12.f));

            _imagenesAliens[fila][columna]->setPosition(sf::Vector2f(posicionCuadrado.x + 10.f,posicionCuadrado.y - 0.f));
        }
    }
}

void TableroGrafico::actualizar() //actualizar tablero
{
    _posicionNaveX += 0.1f;

    if (_posicionNaveX > 520.f)
    {
        _posicionNaveX = 350.f;
    }

    _naveEspacial->setPosition(sf::Vector2f(_posicionNaveX,40.f));

    _turnos.actualizar();
}

void TableroGrafico::dibujarTablero( //dibujar
    sf::RenderWindow &ventana
)
{
    ventana.draw(*_imagenDeFondo);

    ventana.draw(*_naveEspacial);

    ventana.draw(_fondoBarraEnergiaHumano);

    ventana.draw(_barraEnergiaHumano);

    ventana.draw(_fondoBarraEnergiaAlien);

    ventana.draw(_barraEnergiaAlien);

    // OBJETOS HUMANO

    ventana.draw(*_spriteBombaHumano);

    ventana.draw(*_spriteMinaHumano);

    ventana.draw(*_spriteTorreHumano);

    // OBJETOS ALIEN

    ventana.draw(*_spriteBombaAlien);

    ventana.draw(*_spriteMinaAlien);

    ventana.draw(*_spriteTorreAlien);

    // TURNOS

    _turnos.dibujar(ventana);

    // TABLERO

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            ventana.draw(_cuadradosDelTablero[fila][columna]);

            if (_hayFichaSeleccionada && fila == _filaSeleccionada && columna == _columnaSeleccionada)
            {
                _cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Green);
            }
            else
            {
                _cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Transparent);
            }

            // HUMANOS

            if (_contenidoDelTablero[fila][columna] == 'X')
            {
                ventana.draw(*_imagenesHumanos[fila][columna]);
            }

            // ALIENS

            if (_contenidoDelTablero[fila][columna] == 'O')
            {
                ventana.draw(*_imagenesAliens[fila][columna]);
            }
        }
        if (_juegoTerminado)
{
    ventana.draw(*_textoGanador);
}
    }
}
void TableroGrafico::procesarClickDelMouse(
    const sf::Event &evento,
    sf::RenderWindow &ventana
)
{
    if (_juegoTerminado)
    {
        return;
    }

    if (const auto *clickMouse =evento.getIf<sf::Event::MouseButtonPressed>())
    {
        sf::Vector2f posicionClick(
            static_cast<float>(clickMouse->position.x),
            static_cast<float>(clickMouse->position.y)
        );

        // RECORRER TABLERO

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                sf::FloatRect areaCasilla =
                    _cuadradosDelTablero[fila][columna].getGlobalBounds();

                if (areaCasilla.contains(posicionClick))
                {
                    if (_esTurnoHumano)
                    {

                        if (_cantidadFichasHumano < 3)
                        {
                            if (_contenidoDelTablero[fila][columna] == ' ')
                            {
                                _contenidoDelTablero[fila][columna] = 'X';

                                _cantidadFichasHumano++;

                                _esTurnoHumano = false;

                                _turnos.siguienteTurno();
                            }
                        }

                        // MOVER FICHAS

                        else
                        {
                            // SELECCIONAR

                            if (!_hayFichaSeleccionada)
                            {
                                if (_contenidoDelTablero[fila][columna] == 'X')
                                {
                                    _hayFichaSeleccionada = true;

                                    _filaSeleccionada = fila;

                                    _columnaSeleccionada = columna;
                                }
                            }

                            // MOVER

                            else
                            {
                                if (_contenidoDelTablero[fila][columna] == ' ')
                                {
                                    _contenidoDelTablero[_filaSeleccionada][_columnaSeleccionada] = ' ';

                                    _contenidoDelTablero[fila][columna] = 'X';

                                    _hayFichaSeleccionada = false;

                                    _filaSeleccionada = -1;

                                    _columnaSeleccionada = -1;

                                    _esTurnoHumano = false;

                                    _turnos.siguienteTurno();
                                }
                            }
                        }
                    }

                    else
                    {

                        if (_cantidadFichasAlien < 3)
                        {
                            if (_contenidoDelTablero[fila][columna] == ' ')
                            {
                                _contenidoDelTablero[fila][columna] = 'O';

                                _cantidadFichasAlien++;

                                _esTurnoHumano = true;

                                _turnos.siguienteTurno();
                            }
                        }

                        else
                        {
                            if (!_hayFichaSeleccionada)
                            {
                                if (_contenidoDelTablero[fila][columna] == 'O')
                                {
                                    _hayFichaSeleccionada = true;

                                    _filaSeleccionada = fila;

                                    _columnaSeleccionada = columna;
                                }
                            }
                            else
                            {
                                if (_contenidoDelTablero[fila][columna] == ' ')
                                {
                                    _contenidoDelTablero[_filaSeleccionada][_columnaSeleccionada] = ' ';

                                    _contenidoDelTablero[fila][columna] = 'O';

                                    _hayFichaSeleccionada = false;

                                    _filaSeleccionada = -1;

                                    _columnaSeleccionada = -1;

                                    _esTurnoHumano = true;

                                    _turnos.siguienteTurno();
                                }
                            }
                        }
                    }
                    if (verificarVictoria('X'))
                    {
                     _textoGanador->setString("GANARON HUMANOS");
                        _juegoTerminado = true;
                    }

                    if (verificarVictoria('O'))
                    {
                       _textoGanador->setString("GANARON ALIENS");
                        _juegoTerminado = true;
                    }

                    return;
                }
            }
        }
    }
}

bool TableroGrafico::verificarVictoria(
    char simboloJugador
)
{
    // FILAS

    for (int fila = 0; fila < 3; fila++)
    {
        if (_contenidoDelTablero[fila][0] == simboloJugador && _contenidoDelTablero[fila][1] == simboloJugador && _contenidoDelTablero[fila][2] == simboloJugador)
        {
            return true;
        }
    }

    // COLUMNAS

    for (int columna = 0; columna < 3; columna++)
    {
        if (_contenidoDelTablero[0][columna] == simboloJugador && _contenidoDelTablero[1][columna] == simboloJugador && _contenidoDelTablero[2][columna] == simboloJugador)
        {
            return true;
        }
    }

    // DIAGONAL PRINCIPAL

    if (_contenidoDelTablero[0][0] == simboloJugador && _contenidoDelTablero[1][1] == simboloJugador && _contenidoDelTablero[2][2] == simboloJugador)
    {
        return true;
    }

    // DIAGONAL SECUNDARIA

    if (_contenidoDelTablero[0][2] == simboloJugador && _contenidoDelTablero[1][1] == simboloJugador && _contenidoDelTablero[2][0] == simboloJugador)
    {
        return true;
    }

    return false;
}

bool TableroGrafico::tableroLleno() //tablero lleno
{
    return false;
}

void TableroGrafico::reiniciarTablero() //reiniciar
{
}

TableroGrafico::~TableroGrafico()
{
    delete _imagenDeFondo;

    delete _naveEspacial;

    delete _textoGanador;

    delete _spriteBombaHumano;

    delete _spriteMinaHumano;

    delete _spriteTorreHumano;

    delete _spriteBombaAlien;

    delete _spriteMinaAlien;

    delete _spriteTorreAlien;

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            delete _imagenesHumanos[fila][columna];

            delete _imagenesAliens[fila][columna];
        }
    }
}
