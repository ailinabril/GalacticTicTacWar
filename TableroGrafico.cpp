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

    float posicionInicialX = 380.f;

    float posicionInicialY = 140.f;

    float anchoCasilla = 180.f;

    float altoCasilla = 120.f;

    // CREAR CASILLAS

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            _cuadradosDelTablero[fila][columna].setSize(sf::Vector2f(anchoCasilla - 5.f,altoCasilla - 5.f));

            _cuadradosDelTablero[fila][columna].setPosition(sf::Vector2f(posicionInicialX + columna * anchoCasilla,posicionInicialY + fila * altoCasilla));

            _cuadradosDelTablero[fila][columna].setFillColor(sf::Color::Transparent);

            _cuadradosDelTablero[fila][columna].setOutlineThickness(1.f);

            _cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Transparent);
        }
    }

    // FONDO

    if (!_texturaFondo.loadFromFile("fondo2.png"))
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

    _fondoBarraEnergiaHumano.setFillColor(sf::Color(0,0,0));// el setfillcolor establece el color de relleno de las figura que dibujo

    _fondoBarraEnergiaHumano.setPosition(sf::Vector2f(40.f,790.f));//el setposition ubica un objeto en una posición determinada de la ventana

    _barraEnergiaHumano.setPosition(sf::Vector2f(500.f,400.f));

    _barraEnergiaHumano.setSize(sf::Vector2f(210.f,14.f)); //el setsize cambiar el tamaño de un objeto

    _barraEnergiaHumano.setFillColor(sf::Color::Green);

    _barraEnergiaHumano.setPosition(sf::Vector2f(45.f,645.f));

    // ENERGIA ALIEN

    _fondoBarraEnergiaAlien.setSize(sf::Vector2f(220.f,24.f));

    _fondoBarraEnergiaAlien.setFillColor(sf::Color(40,40,40));

    _fondoBarraEnergiaAlien.setPosition(sf::Vector2f(1600.f,400.f));

    _barraEnergiaAlien.setPosition(sf::Vector2f(2000.f,400.f));

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

    _marcoBombaHumano.setSize(sf::Vector2f(220.f,60.f));

    _marcoBombaHumano.setPosition(sf::Vector2f(20.f,265.f));

    _marcoBombaHumano.setFillColor(sf::Color(0,0,0,0));

    _marcoBombaHumano.setOutlineThickness(2.f);

    _marcoBombaHumano.setOutlineColor(sf::Color::Transparent);

    _marcoMinaHumano.setSize(sf::Vector2f(220.f,60.f));

    _marcoMinaHumano.setPosition(sf::Vector2f(20.f,335.f));

    _marcoMinaHumano.setFillColor(sf::Color(0,0,0,0));

    _marcoMinaHumano.setOutlineThickness(2.f);

    _marcoMinaHumano.setOutlineColor(sf::Color::Transparent); // para que sea visible el rectangulo en cyan sino Transparent

    _marcoTorreHumano.setSize(sf::Vector2f(220.f,60.f));

    _marcoTorreHumano.setPosition(sf::Vector2f(20.f,405.f));

    _marcoTorreHumano.setFillColor(sf::Color(0,0,0,0));

    _marcoTorreHumano.setOutlineThickness(2.f); //dibuja un marco verde de 2 píxeles alrededor de _marcoTorreHumano.

    _marcoTorreHumano.setOutlineColor(sf::Color::Transparent);

    _spriteBombaHumano =new sf::Sprite(_texturaBomba);

    _spriteMinaHumano =new sf::Sprite(_texturaMina);

    _spriteTorreHumano = new sf::Sprite(_texturaTorre);

    // OBJETOS ALIEN

    _spriteBombaAlien = new sf::Sprite(_texturaBomba);

    _spriteMinaAlien = new sf::Sprite(_texturaMina);

    _spriteTorreAlien = new sf::Sprite(_texturaTorre);

    _marcoBombaAlien.setSize(sf::Vector2f(220.f,60.f));

    _marcoBombaAlien.setPosition(sf::Vector2f(1040.f,265.f));

    _marcoBombaAlien.setFillColor(sf::Color(0,0,0,0));

    _marcoBombaAlien.setOutlineThickness(2.f);

    _marcoBombaAlien.setOutlineColor(sf::Color::Green); // establece el color del borde (contorno) de una figura

    _marcoMinaAlien.setSize(sf::Vector2f(220.f,60.f));

    _marcoMinaAlien.setPosition(sf::Vector2f(1040.f,335.f));

    _marcoMinaAlien.setFillColor(sf::Color(0,0,0,120));

    _marcoMinaAlien.setOutlineThickness(2.f);

    _marcoMinaAlien.setOutlineColor(sf::Color::Green);

    _marcoTorreAlien.setSize(sf::Vector2f(220.f,60.f));

    _marcoTorreAlien.setPosition(sf::Vector2f(1040.f,405.f));

    _marcoTorreAlien.setFillColor(sf::Color(0,0,0,120));

    _marcoTorreAlien.setOutlineThickness(2.f);

    _marcoTorreAlien.setOutlineColor(sf::Color::Green);

    // POSICIONES HUMANO

    _spriteBombaHumano->setPosition(sf::Vector2f(15.f,250.f));

    _spriteBombaHumano->setColor(sf::Color(255,255,255,0));

    _spriteMinaHumano->setPosition(sf::Vector2f(-20.f,315.f));

    _spriteMinaHumano->setColor(sf::Color(255,255,255,0));

    _spriteTorreHumano->setPosition(sf::Vector2f(-20.f,395.f));

    _spriteTorreHumano->setColor(sf::Color(255,255,255,0));

    // POSICIONES ALIEN

    _spriteBombaAlien->setPosition(sf::Vector2f(1000.f,250.f));

    _spriteBombaAlien->setColor(sf::Color(255,255,255,0));

    _spriteMinaAlien->setPosition(sf::Vector2f(1000.f,315.f));

    _spriteMinaAlien->setColor(sf::Color(255,255,255,0));

    _spriteTorreAlien->setPosition(sf::Vector2f(960.f,395.f));

    _spriteTorreAlien->setColor(sf::Color(255,255,255,0));


    // ESCALAS

    _spriteBombaHumano->setScale(sf::Vector2f(0.1f,0.1f));

    _spriteMinaHumano->setScale(sf::Vector2f(0.1f,0.1f));

    _spriteTorreHumano->setScale(sf::Vector2f(0.1f,0.1f));

    _spriteBombaAlien->setScale(sf::Vector2f(0.1f,0.1f));

    _spriteMinaAlien->setScale(sf::Vector2f(0.1f,0.1f));

    _spriteTorreAlien->setScale(sf::Vector2f(0.1f,0.1f));

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

            _imagenesHumanos[fila][columna]->setPosition(sf::Vector2f(posicionCuadrado.x -20.f,posicionCuadrado.y -10.f));

            _imagenesAliens[fila][columna]->setPosition(sf::Vector2f(posicionCuadrado.x -2.f,posicionCuadrado.y - 0.f));
        }
    }
}

void TableroGrafico::actualizar() //actualizar tablero
{
    _posicionNaveX += 0.01f;

    if (_posicionNaveX > 25.f)
    {
        _posicionNaveX = 1040.f;
    }

    _naveEspacial->setPosition(sf::Vector2f(_posicionNaveX,40.f));

    _turnos.actualizar();
}

void TableroGrafico::dibujarTablero( //dibujar
    sf::RenderWindow &ventana)
{
    ventana.draw(*_imagenDeFondo);

    ventana.draw(*_naveEspacial);

    ventana.draw(_fondoBarraEnergiaHumano);

    ventana.draw(_barraEnergiaHumano);

    ventana.draw(_fondoBarraEnergiaAlien);

    ventana.draw(_barraEnergiaAlien);

    ventana.draw(_marcoBombaHumano);

    ventana.draw(_marcoMinaHumano);

    ventana.draw(_marcoTorreHumano);

    ventana.draw(_marcoBombaAlien);

    ventana.draw(_marcoMinaAlien);

    ventana.draw(_marcoTorreAlien);

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
    const sf::Event &evento,sf::RenderWindow &ventana)
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
