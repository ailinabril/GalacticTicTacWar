#include "TableroGrafico.h"

#include <iostream>

using namespace std;

Tablero::Tablero()
{

    _esTurnoHumano = true;

    _juegoTerminado = false;

    /*   for (int fila = 0; fila < 3; fila++)
       {
           for (int columna = 0; columna < 3; columna++)
           {
               _contenidoDelTablero[fila][columna] = ' ';
           }
       }

       float posicionInicialX = 280.f;

       float posicionInicialY = 110.f;

       float anchoCasilla = 240.f;

       float altoCasilla = 110.f;

       for (int fila = 0; fila < 3; fila++)
       {
           for (int columna = 0; columna < 3; columna++)
           {
               _cuadradosDelTablero[fila][columna].setSize(sf::Vector2f(240.f,110.f));

               _cuadradosDelTablero[fila][columna].setPosition(sf::Vector2f(posicionInicialX + columna * anchoCasilla,posicionInicialY + fila * altoCasilla));

               _cuadradosDelTablero[fila][columna].setFillColor(sf::Color(255,0,0,100));
           }
       }

       */
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            _contenidoDelTablero[fila][columna]= ' ';
        }
    }


    float posicionInicialX = 305.f;  //posiicion y tanio

    float posicionInicialY = 110.f;

// Distancia entre casillas

    float anchoCasilla = 240.f;

    float altoCasilla = 120.f;

    for (int fila = 0; fila < 3; fila++)     //creamos la casilla
    {
        for (int columna = 0; columna < 3; columna++)
        {

            _cuadradosDelTablero[fila][columna]   //tamanio de la  casilla
            .setSize(sf::Vector2f( anchoCasilla - 10.f,altoCasilla - 10.f));

            _cuadradosDelTablero[fila][columna]  //posicion de la casilla
            .setPosition(sf::Vector2f(posicionInicialX + columna * anchoCasilla,posicionInicialY + fila * altoCasilla));

            _cuadradosDelTablero[fila][columna]  //color de la casilla
            .setFillColor(sf::Color::Transparent);


            _cuadradosDelTablero[fila][columna]  //borde de la casillas
            .setOutlineThickness(3.f);

            _cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Transparent);
        }
    }

    if (!_texturaFondo.loadFromFile("fondo.png"))
    {
        cout << "ERROR FONDO" << endl;
    }

    _imagenDeFondo.emplace(_texturaFondo);

    // CARGAR NAVE

    if (!_texturaNave.loadFromFile("nave.png"))
    {
        cout << "ERROR NAVE" << endl;
    }

    _naveEspacial.emplace(_texturaNave);

    _posicionNaveX = 150.f;

    _naveEspacial->setPosition(sf::Vector2f(_posicionNaveX,20.f));

    _fondoBarraEnergiaHumano.setSize(sf::Vector2f(260.f, 30.f));    // fondo de energia

    _fondoBarraEnergiaHumano.setFillColor(sf::Color(40,40,40));

    _fondoBarraEnergiaHumano.setPosition(sf::Vector2f(30.f, 30.f));

    _barraEnergiaHumano.setSize(sf::Vector2f(250.f, 20.f));     //barra de energia

    _barraEnergiaHumano.setFillColor(sf::Color::Cyan);

    _barraEnergiaHumano.setPosition(sf::Vector2f(35.f, 35.f));

    _fondoBarraEnergiaAlien.setSize(sf::Vector2f(260.f, 30.f));  //fondo de energia

    _fondoBarraEnergiaAlien.setFillColor(sf::Color(40,40,40));

    _fondoBarraEnergiaAlien.setPosition(sf::Vector2f(900.f, 30.f));

    _barraEnergiaAlien.setSize(sf::Vector2f(250.f, 20.f));

    _barraEnergiaAlien.setFillColor(sf::Color(0,255,120));

    _barraEnergiaAlien.setPosition(sf::Vector2f(905.f, 35.f));


    // CARGAR IMAGENES

    if (!_texturaHumano.loadFromFile("O.png"))
    {
        cout << "ERROR HUMANO" << endl;
    }

    if (!_texturaAlien.loadFromFile("X.png"))
    {
        cout << "ERROR ALIEN" << endl;
    }

    // CONFIGURAR IMAGENES

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            // IMAGEN HUMANO

            _imagenesHumanos[fila][columna].emplace(_texturaHumano);

            float escalaHumanoX =200.f /_texturaHumano.getSize().x;

            float escalaHumanoY =120.f /_texturaHumano.getSize().y;

            _imagenesHumanos[fila][columna]->setScale(sf::Vector2f(escalaHumanoX,escalaHumanoY));

            // CENTRAR HUMANO

            sf::Vector2f posicionCuadrado =_cuadradosDelTablero[fila][columna].getPosition();

            sf::Vector2f tamanioCuadrado =_cuadradosDelTablero[fila][columna].getSize();

            sf::FloatRect tamanioHumano =_imagenesHumanos[fila][columna]->getGlobalBounds();

            float posicionHumanoX =posicionCuadrado.x+(tamanioCuadrado.x / 2.f)-(tamanioHumano.size.x / 2.f)  ;

            float posicionHumanoY =posicionCuadrado.y+(tamanioCuadrado.y / 2.f)-(tamanioHumano.size.y / 2.f) + 10.f ;

            _imagenesHumanos[fila][columna]->setPosition(sf::Vector2f(posicionHumanoX,posicionHumanoY));

            // IMAGEN ALIEN

            _imagenesAliens[fila][columna].emplace(_texturaAlien);

            float escalaAlienX =155.f /_texturaAlien.getSize().x;

            float escalaAlienY =105.f /_texturaAlien.getSize().y;

            _imagenesAliens[fila][columna]->setScale(sf::Vector2f(escalaAlienX,escalaAlienY));

            // CENTRAR ALIEN

            sf::FloatRect tamanioAlien =_imagenesAliens[fila][columna]->getGlobalBounds();

            float posicionAlienX = posicionCuadrado.x +(tamanioCuadrado.x / 2.f)-(tamanioAlien.size.x / 2.f) ;

            float posicionAlienY = posicionCuadrado.y +(tamanioCuadrado.y / 2.f)-(tamanioAlien.size.y / 2.f) + 10.f;

            _imagenesAliens[fila][columna]->setPosition(sf::Vector2f( posicionAlienX,posicionAlienY));
        }
    }
}
// ACTUALIZAR

void Tablero::actualizar()
{
    _posicionNaveX = 1.0f;

    if (_posicionNaveX < -300.f)
    {
        _posicionNaveX = 500.f;
    }

    if (_naveEspacial.has_value())
    {
        _naveEspacial->setPosition(sf::Vector2f(_posicionNaveX,30.f));

        float energiaActual = 3.f;     // energia temporal

        float energiaMaxima = 5.f;

        float porcentajeEnergia = energiaActual / energiaMaxima;

        _barraEnergiaHumano.setSize( sf::Vector2f(250.f * porcentajeEnergia, 20.f));

        float energiaAlien = 4.f;

        float porcentajeAlien = energiaAlien / energiaMaxima;

        _barraEnergiaAlien.setSize(sf::Vector2f(250.f * porcentajeAlien,20.f));

        _turnos.actualizar();
    }


}

void Tablero::dibujarTablero(sf::RenderWindow &ventana)
{

    // FONDO

    if (_imagenDeFondo.has_value())
    {
        ventana.draw (*_imagenDeFondo);
    }

    // NAVE

    if (_naveEspacial.has_value())
    {
        ventana.draw(*_naveEspacial);
    }

    ventana.draw(_fondoBarraEnergiaHumano);

    ventana.draw(_barraEnergiaHumano);

    ventana.draw(_fondoBarraEnergiaAlien);

    ventana.draw(_barraEnergiaAlien);

    _turnos.dibujar(ventana);

    // TABLERO

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            ventana.draw(_cuadradosDelTablero[fila][columna]);

            if (_hayFichaSeleccionada &&
                    fila == _filaSeleccionada &&
                    columna == _columnaSeleccionada)
            {
                _cuadradosDelTablero[fila][columna]
                .setOutlineColor(sf::Color::Green);
            }
            else
            {
                _cuadradosDelTablero[fila][columna]
                .setOutlineColor(sf::Color::Transparent);
            }

            if (_contenidoDelTablero[fila][columna] == 'X')
            {
                if (_imagenesHumanos[fila][columna])
                {
                    ventana.draw(
                        *_imagenesHumanos[fila][columna]
                    );
                }
            }

            if (_contenidoDelTablero[fila][columna] == 'O')       //alien
            {
                if (_imagenesAliens[fila][columna].has_value())
                {
                    ventana.draw(
                        *_imagenesAliens[fila][columna]
                    );
                }
            }
        }
    }
}
// CLICK DEL MOUSE

void Tablero::procesarClickDelMouse(
    const sf::Event &evento,
    sf::RenderWindow &ventana
)
{
    if (_juegoTerminado)
    {
        return;
    }

    if (const auto *clickMouse =
                evento.getIf<sf::Event::MouseButtonPressed>())
    {
        sf::Vector2f posicionClick(
            static_cast<float>(clickMouse->position.x),
            static_cast<float>(clickMouse->position.y)
        );

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                sf::FloatRect areaCasilla =
                    _cuadradosDelTablero[fila][columna]
                    .getGlobalBounds();

                if (areaCasilla.contains(posicionClick))
                {
//turno de humanos como el de aliens

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
                        else
                        {
                            if (!_hayFichaSeleccionada)
                            {
                                if (_contenidoDelTablero[fila][columna] == 'X')
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
                                }
                            }
                        }
                    }

                    if (verificarVictoria('X'))       // verificamos si alguien gana
                    {
                        cout << "GANARON HUMANOS" << endl;

                        _juegoTerminado = true;
                    }

                    if (verificarVictoria('O'))
                    {
                        cout << "GANARON ALIENS" << endl;

                        _juegoTerminado = true;
                    }

                    return;
                }
            }
        }
    }
}


bool Tablero::verificarVictoria(char simboloJugador)

{
    // FILAS

    for (int fila = 0; fila < 3; fila++)
    {
        if (_contenidoDelTablero[fila][0]== simboloJugador && _contenidoDelTablero[fila][1] == simboloJugador && _contenidoDelTablero[fila][2]== simboloJugador)
        {
            return true;
        }
    }

    // COLUMNAS

    for (int columna = 0; columna < 3; columna++)
    {
        if (_contenidoDelTablero[0][columna]== simboloJugador&&_contenidoDelTablero[1][columna]== simboloJugador&&_contenidoDelTablero[2][columna]== simboloJugador)
        {
            return true;
        }
    }

    // DIAGONAL PRINCIPAL

    if (_contenidoDelTablero[0][0]== simboloJugador&&_contenidoDelTablero[1][1] == simboloJugador &&_contenidoDelTablero[2][2]== simboloJugador)
    {
        return true;
    }

    // DIAGONAL SECUNDARIA

    if (_contenidoDelTablero[0][2]== simboloJugador && _contenidoDelTablero[1][1] == simboloJugador && _contenidoDelTablero[2][0]== simboloJugador)
    {
        return true;
    }

    return false;
}

bool Tablero::tableroLleno()
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            if (_contenidoDelTablero[fila][columna]== ' ')
            {
                return false;
            }
        }
    }

    return true;
}

void Tablero::reiniciarTablero()
{
    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            _contenidoDelTablero[fila][columna]= ' ';
        }
    }

    _esTurnoHumano = true;

    _juegoTerminado = false;

    _cantidadFichasHumano = 0;

    _cantidadFichasAlien = 0;

    _hayFichaSeleccionada = false;

    _filaSeleccionada = -1;

    _columnaSeleccionada = -1;
}
