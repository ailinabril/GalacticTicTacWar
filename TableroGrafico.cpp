#include "TableroGrafico.h"
#include <iostream>

using namespace std;

TableroGrafico::TableroGrafico() //contructor
{
	// TURNOS
	_esTurnoHumano = true;
	_juegoTerminado = false;
	_cpuPensando = false;

	// VICTORIAS
	_victoriasHumanos = 0;
	_victoriasAliens = 0;


	// SELECCION
	_hayFichaSeleccionada = false;
	_filaSeleccionada = -1;
	_columnaSeleccionada = -1;

	// OBJETO
	_objetoSeleccionado = 0;

	// Vero
	_veroYaAparecio = false;
	_mostrarVero = false;
	_contadorVero = 0;

	if (!_texturaVero.loadFromFile("Vero.png")){
		cout << "ERROR Vero" << endl;
	}
	_spriteVero =new sf::Sprite(_texturaVero);
	_spriteVero->setPosition(sf::Vector2f(900.f,500.f));
	_spriteVero->setScale(sf::Vector2f(0.3f,0.3f));


	// TABLERO VACIO
	_tablero.Inicializar();

	//POSICION TABLERO
	float posicionInicialX = 390.f;
	float posicionInicialY = 140.f;
	float anchoCasilla = 169.f;
	float altoCasilla = 135.f;

	//CREAR CASILLAS
	for (int fila = 0; fila < 3; fila++)
	{
		for (int columna = 0; columna < 3; columna++)
		{
			_cuadradosDelTablero[fila][columna].setSize(sf::Vector2f(anchoCasilla - 5.f,altoCasilla - 5.f));
			_cuadradosDelTablero[fila][columna].setPosition(sf::Vector2f(posicionInicialX + columna * anchoCasilla,posicionInicialY + fila * altoCasilla));
			_cuadradosDelTablero[fila][columna].setFillColor(sf::Color::Transparent); // relleno de los cuadros
			_cuadradosDelTablero[fila][columna].setOutlineThickness(1.f);
			_cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Cyan); // contorno de los cuadros
		}
	}

	//FONDO

	if (!_texturaFondo.loadFromFile("fondo3.png"))
	{
		cout << "ERROR FONDO" << endl;
	}

	_imagenDeFondo = new sf::Sprite(_texturaFondo);

	//NAVE

	if (!_texturaNave.loadFromFile("nave.png"))
	{
		cout << "ERROR NAVE" << endl;
	}

	// IMAGENES DEL RIVAL
	_texturaAlienNormal.loadFromFile("marciano.png");
	_texturaBossKloster.loadFromFile("klosterFinalBoss.png");

	// CREAR SPRITE DEL RIVAL
	_spriteRival = new sf::Sprite(_texturaAlienNormal);
	_naveEspacial = new sf::Sprite(_texturaNave);
	_posicionNaveX = 150.f;
	_naveEspacial->setPosition(sf::Vector2f(_posicionNaveX,40.f));
	_naveEspacial->setScale(sf::Vector2f(0.40f,0.40f));

	// FUENTE
	if (!_fuente.openFromFile("Orbitron-Regular.ttf"))
	{
		cout << "ERROR FUENTE" << endl;
	}

	// TEXTO GANADOR
	_textoGanador =new sf::Text(_fuente,"",40);
	_textoGanador->setFillColor(sf::Color::Green);
	_textoGanador->setPosition(sf::Vector2f(400.f,560.f));
	_textoVictoriasHumanos =new sf::Text(_fuente);
	_textoVictoriasAliens =new sf::Text(_fuente);
	_textoVictoriasHumanos->setCharacterSize(24);
	_textoVictoriasAliens->setCharacterSize(24);
	_textoVictoriasHumanos->setPosition(sf::Vector2f(260.f,510.f));
	_textoVictoriasAliens->setPosition(sf::Vector2f(1165.f,515.f));

	// ENERGIA HUMANO
	_fondoBarraEnergiaHumano.setSize(sf::Vector2f(220.f,24.f));
	_fondoBarraEnergiaHumano.setFillColor(sf::Color(0,0,0));// el setfillcolor establece el color de relleno de las figura que dibujo

	//_fondoBarraEnergiaHumano.setPosition(sf::Vector2f(40.f,592.f));//el setposition ubica un objeto en una posición determinada de la ventana
	_barraEnergiaHumano.setSize(sf::Vector2f(210.f,14.f)); //el setsize cambiar el tamaño de un objeto
	_barraEnergiaHumano.setFillColor(sf::Color::Green);
	_barraEnergiaHumano.setPosition(sf::Vector2f(80.f,600.f)); //donde se ubica la barra verde de la energia

	// ENERGIA ALIEN
	_fondoBarraEnergiaAlien.setSize(sf::Vector2f(220.f,24.f));
	_fondoBarraEnergiaAlien.setFillColor(sf::Color(40,40,40));
	_fondoBarraEnergiaAlien.setPosition(sf::Vector2f(1600.f,400.f));
	_barraEnergiaAlien.setPosition(sf::Vector2f(2000.f,592.f));
	_barraEnergiaAlien.setSize(sf::Vector2f(210.f,14.f));
	_barraEnergiaAlien.setFillColor(sf::Color::Green);
	_barraEnergiaAlien.setPosition(sf::Vector2f(985.f,605.f));

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
	_marcoBombaAlien.setOutlineColor(sf::Color::Transparent); // establece el color del borde (contorno) de una figura
	_marcoMinaAlien.setSize(sf::Vector2f(220.f,60.f));
	_marcoMinaAlien.setPosition(sf::Vector2f(1040.f,335.f));
	_marcoMinaAlien.setFillColor(sf::Color(0,0,0,0));
	_marcoMinaAlien.setOutlineThickness(2.f);
	_marcoMinaAlien.setOutlineColor(sf::Color::Transparent);
	_marcoTorreAlien.setSize(sf::Vector2f(220.f,60.f));
	_marcoTorreAlien.setPosition(sf::Vector2f(1040.f,405.f));
	_marcoTorreAlien.setFillColor(sf::Color(0,0,0,0));
	_marcoTorreAlien.setOutlineThickness(2.f);
	_marcoTorreAlien.setOutlineColor(sf::Color::Transparent);

	// POSICIONES HUMANO
	_spriteBombaHumano->setPosition(sf::Vector2f(15.f,250.f));
	_spriteBombaHumano->setColor(sf::Color(255,255,255,0));
	_spriteMinaHumano->setPosition(sf::Vector2f(-20.f,315.f));
	_spriteMinaHumano->setColor(sf::Color(255,255,255,0));
	_spriteTorreHumano->setPosition(sf::Vector2f(-20.f,395.f));
	_spriteTorreHumano->setColor(sf::Color(255,255,255,0));

	// POSICIONES ALIEN
	_spriteBombaAlien->setPosition(sf::Vector2f(1000.f,250.f));
	_spriteBombaAlien->setColor(sf::Color(255,255,255,0)); // 0 es transparente --> ,255) 100% visible
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
			sf::Vector2f posicionCuadrado = // sf::Vector2f es una estructura de sfml que almacena una posicion bidimensional usando 2 numeros tipo float
				_cuadradosDelTablero[fila][columna].getPosition();
				_imagenesHumanos[fila][columna]->setPosition(sf::Vector2f(posicionCuadrado.x -20.f,posicionCuadrado.y -10.f));
				_imagenesAliens[fila][columna]->setPosition(sf::Vector2f(posicionCuadrado.x -2.f,posicionCuadrado.y - 0.f));
		}
	}
}

void TableroGrafico::actualizar() //actualizar tablero
{
	_posicionNaveX += 0.01f;

	if (_posicionNaveX > 540.f)
	{
		_posicionNaveX = 150.f;
	}

	if (_klosterCode.EstaActivado())
	{
		_spriteRival->setTexture(_texturaBossKloster);
	}
	else
	{
		_spriteRival->setTexture(_texturaAlienNormal);
	}

	_spriteRival->setPosition(sf::Vector2f(970.f,35.f));
	_spriteRival->setScale(sf::Vector2f(0.18f,0.18f));
	_naveEspacial->setPosition(sf::Vector2f(_posicionNaveX,40.f));

	_turnos.actualizar();

	// APARICION ALEATORIA DEL Vero
	if (!_veroYaAparecio)  // verfico que vero no haya aparecido
	{
		int numeroRandom = rand() % 30000;

		if (numeroRandom == 1)
		{
			_mostrarVero = true; // activvo una bandera para indicar que vero debe mostrarse en pantalla
			_contadorVero = 6000; // tiempo que permanece en pantalla
			_veroYaAparecio = true; // impido que vuelva activarse de nuevo la aparicion de vero
		}
	}

	if (_mostrarVero) // si aparece vero
	{
		_contadorVero--; // si aparecio voy descontando en 1

		if (_contadorVero <= 0) // verifico si el tiempo asignado termino
		{
			_mostrarVero = false; // cuando llega a 0 dejo de mostrar a vero
		}

	}

	//pausa de la IA
	if (_cpuPensando){

    if (_relojCPU.getElapsedTime().asSeconds() >= 1.5f){
        turnoCPU();

        _cpuPensando = false;
     }
   }
}

void TableroGrafico::turnoCPU(){
    _juego.TurnoIA(_tablero);
    _esTurnoHumano = true;
    _turnos.siguienteTurno();
}


void TableroGrafico::dibujarTablero(sf::RenderWindow &ventana)
{
	ventana.draw(*_imagenDeFondo);
	ventana.draw(*_spriteRival);
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
	ventana.draw(*_textoVictoriasHumanos);
	ventana.draw(*_textoVictoriasAliens);

	if (_mostrarVero)
	{
		ventana.draw(*_spriteVero);
	}

	// OBJETOS HUMANO
	ventana.draw(*_spriteBombaHumano);
	ventana.draw(*_spriteMinaHumano);
	ventana.draw(*_spriteTorreHumano);

	// OBJETOS ALIEN
	ventana.draw(*_spriteBombaAlien);
	ventana.draw(*_spriteMinaAlien);
	ventana.draw(*_spriteTorreAlien);

	// TURNOS
	if (!_juegoTerminado)
	{
		_turnos.dibujar(ventana);
	}

	// TABLERO
	for (int fila = 0; fila < 3; fila++)
	{
		for (int columna = 0; columna < 3; columna++)
		{
			ventana.draw(_cuadradosDelTablero[fila][columna]); //dibuja el cuadrado correspondiente a la posicion del tablero

			if (_hayFichaSeleccionada && fila == _filaSeleccionada && columna == _columnaSeleccionada) // aca verifico 2 condiciones que exista una ficha seleccionada y que la posicion que esttoy recorriendo coincida con la posicion guardada como seleccionada
			{
				_cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Green); // si ambas son verdaderas se pone el borde de color verde
			}
			else
			{
				_cuadradosDelTablero[fila][columna].setOutlineColor(sf::Color::Transparent); // si no hay ficha dentro de la misma el borde del cuadro seleccionado es transparente
			}

			// HUMANOS
			if (_tablero.getCasillero(fila, columna) == 'X')
			{
				ventana.draw(*_imagenesHumanos[fila][columna]);
			}

			// ALIENS
			if (_tablero.getCasillero(fila, columna) == 'O')  // verifico si la casilla del tablero contiene "O"
			{
				ventana.draw(*_imagenesAliens[fila][columna]); // si se cumple dibujo la ficha de aliens
			}
		}

		if (_juegoTerminado) //
		{
			ventana.draw(*_textoGanador);
		}
	}
}
void TableroGrafico::procesarClickDelMouse(
    const sf::Event &evento,
    sf::RenderWindow &ventana)
{
    if (_juegoTerminado)
    {
        return;
    }

    if (!_esTurnoHumano)
    {
        return;
    }

    if (const auto *clickMouse = evento.getIf<sf::Event::MouseButtonPressed>())
    {
        sf::Vector2f posicionClick(
            static_cast<float>(clickMouse->position.x),
            static_cast<float>(clickMouse->position.y));

        for (int fila = 0; fila < 3; fila++)
        {
            for (int columna = 0; columna < 3; columna++)
            {
                sf::FloatRect areaCasilla =
                    _cuadradosDelTablero[fila][columna].getGlobalBounds();

                if (areaCasilla.contains(posicionClick))
                {
                    // COLOCAR FICHAS
                    if(_juego.getCantidadFichasJugador() < 3){
                        //intentar colocar una ficha en la posicion seleccionada
                        if(_juego.ColocarFicha(_tablero, fila, columna)){

                            //finaliza el turno del jugador
                            _esTurnoHumano = false;

                            //pasamos al siguiente turno
                            _turnos.siguienteTurno();

                            //inicia el tiempo de espera para que juegue la IA
                            _cpuPensando = true;
                            _relojCPU.restart(); //reinicia un cronometro SFML
                        }
                    }
                    // MOVER FICHAS
                    else
                    {
                        // SELECCIONAR
                        if (!_hayFichaSeleccionada)
                        {
                            if (_tablero.getCasillero(fila, columna) == 'X')
                            {
                                _hayFichaSeleccionada = true;
                                _filaSeleccionada = fila;
                                _columnaSeleccionada = columna;
                            }
                        }
                        // MOVER
                        else{
                            //intentamos mover la ficha a la posicion seleccionada
                            if(_juego.MoverFicha(_tablero, _filaSeleccionada, _columnaSeleccionada, fila, columna)){
                                //deseleccionamos la ficha
                                _hayFichaSeleccionada = false;
                                _filaSeleccionada = -1;
                                _columnaSeleccionada = -1;

                                //finaliza el turno del jugador
                                _esTurnoHumano = false;

                                //pasa al siguiente turno
                                _turnos.siguienteTurno();

                                //sigue la IA
                                turnoCPU();
                            }
                        }
                    }

                    // VERIFICAR VICTORIA HUMANO
                    if (_tablero.HayGanador('X'))
                    {
                        _textoGanador->setString("GANARON HUMANOS");
                        _juegoTerminado = true;
                        _victoriasHumanos++;
                        _textoVictoriasHumanos->setString(
                            " " + std::to_string(_victoriasHumanos));
                    }

                    // VERIFICAR VICTORIA CPU
                    if (_tablero.HayGanador('O'))
                    {
                        _textoGanador->setString("GANARON LOS ALIENS");
                        _juegoTerminado = true;
                        _victoriasAliens++;
                        _textoVictoriasAliens->setString(
                            " " + std::to_string(_victoriasAliens));
                    }

                    return;
                }
            }
        }
    }
}

void TableroGrafico::procesarLetraKloster(char letra)
{
    _klosterCode.ProcesarLetra(letra);
}

TableroGrafico::~TableroGrafico()
{
	delete _spriteRival;
	delete _imagenDeFondo;
	delete _naveEspacial;
	delete _textoGanador;
	delete _spriteBombaHumano;
	delete _spriteMinaHumano;
	delete _spriteTorreHumano;
	delete _spriteBombaAlien;
	delete _spriteMinaAlien;
	delete _spriteTorreAlien;
	delete _spriteVero;

	for (int fila = 0; fila < 3; fila++)
	{
		for (int columna = 0; columna < 3; columna++)
		{
			delete _imagenesHumanos[fila][columna];
			delete _imagenesAliens[fila][columna];
		}
	}
}
