#include "Menu.h"

using namespace std;

//------------------------------------------------------------
// CONSTRUCTOR
//------------------------------------------------------------
Menu::Menu()
{
    //------------------------------------------------------------
    // CARGA DE IMAGENES
    //------------------------------------------------------------
    _texturaMenu.loadFromFile("menuPrincipal.png");
    _texturaContrato.loadFromFile("contrato.png");
    _texturaRanking.loadFromFile("ranking.png");
    _texturaReglas.loadFromFile("reglas.png");

    _spriteMenu = new sf::Sprite(_texturaMenu);
    _spriteContrato = new sf::Sprite(_texturaContrato);
    _spriteRanking = new sf::Sprite(_texturaRanking);
    _spriteReglas = new sf::Sprite(_texturaReglas);

    //------------------------------------------------------------
    // FUENTE
    //------------------------------------------------------------
    if (!_fuente.openFromFile("Orbitron-Regular.ttf"))
    {
        cout << "Error al cargar la fuente." << endl;
    }

    //------------------------------------------------------------
    // TEXTO DE REGLAS
    //------------------------------------------------------------
    _textoReglas = new sf::Text(_fuente);

    _textoReglas->setCharacterSize(18);
    _textoReglas->setFillColor(sf::Color::White);

    // Ajustar despues si hace falta
    _textoReglas->setPosition(sf::Vector2f(120.f, 130.f));

    //------------------------------------------------------------
    // TEXTO DEL RANKING
    //------------------------------------------------------------
    _textoPantallaRanking = new sf::Text(_fuente);

    _textoPantallaRanking->setCharacterSize(22);
    _textoPantallaRanking->setFillColor(sf::Color::White);

    // Ajustar despues segun el fondo
    _textoPantallaRanking->setPosition(sf::Vector2f(340.f, 180.f));

    //------------------------------------------------------------
    // TEXTO DEL CONTRATO
    //------------------------------------------------------------
    _textoContrato = new sf::Text(_fuente);

    _textoContrato->setCharacterSize(16);

    _textoContrato->setFillColor(sf::Color::White);

    _textoContrato->setPosition(
        sf::Vector2f(390.f, 180.f));
    //------------------------------------------------------------
    // NOMBRE DEL JUGADOR
    //------------------------------------------------------------
    _nombreJugador[0] = '\0';

    _cantidadCaracteres = 0;

    _textoNombreJugador = new sf::Text(_fuente);

    _textoNombreJugador->setCharacterSize(24);

    _textoNombreJugador->setFillColor(sf::Color::White);

    _textoNombreJugador->setPosition(
        sf::Vector2f(415.f, 555.f));


    //------------------------------------------------------------
    // BOTON VOLVER
    //------------------------------------------------------------
    _botonVolver.setSize(sf::Vector2f(180.f,60.f));

    _botonVolver.setPosition(
        sf::Vector2f(1030.f,640.f));

    // Invisible porque el dibujo ya esta en la imagen
    _botonVolver.setFillColor(sf::Color::Transparent);

    _botonVolver.setOutlineThickness(0.f);

    //------------------------------------------------------------
    // TEXTO DEL BOTON VOLVER
    //------------------------------------------------------------
    _textoBotonVolver = new sf::Text(_fuente);

    _textoBotonVolver->setString("");

    _textoBotonVolver->setCharacterSize(28);
}

//------------------------------------------------------------
// AGREGA UNA LETRA AL NOMBRE DEL JUGADOR
//------------------------------------------------------------
void Menu::AgregarCaracter(char letra)
{
    if (_cantidadCaracteres < 29)
    {
        _nombreJugador[_cantidadCaracteres] = letra;

        _cantidadCaracteres++;

        _nombreJugador[_cantidadCaracteres] = '\0';
    }
}
//------------------------------------------------------------
// BORRA EL ULTIMO CARACTER
//------------------------------------------------------------
void Menu::BorrarCaracter()
{
    if (_cantidadCaracteres > 0)
    {
        _cantidadCaracteres--;

        _nombreJugador[_cantidadCaracteres] = '\0';
    }
}

//------------------------------------------------------------
// DEVUELVE EL NOMBRE DEL JUGADOR
//------------------------------------------------------------
const char* Menu::getNombreJugador()
{
    return _nombreJugador;
}



//------------------------------------------------------------
// DIBUJA EL MENU PRINCIPAL
//------------------------------------------------------------
void Menu::dibujar(sf::RenderWindow &ventana)
{
    ventana.draw(*_spriteMenu);
}

//------------------------------------------------------------
// PROCESA LOS CLICS DEL MENU
//------------------------------------------------------------
int Menu::procesarClick(sf::Vector2i mouse)
{
    // JUGAR
    if (mouse.x >= 370 && mouse.x <= 910 &&
            mouse.y >= 245 && mouse.y <= 330)
    {
        return 1;
    }

    // RANKING
    if (mouse.x >= 370 && mouse.x <= 910 &&
            mouse.y >= 350 && mouse.y <= 435)
    {
        return 2;
    }

    // REGLAS
    if (mouse.x >= 370 && mouse.x <= 910 &&
            mouse.y >= 441 && mouse.y <= 540)
    {
        return 3;
    }

    // SALIR
    if (mouse.x >= 370 && mouse.x <= 910 &&
            mouse.y >= 560 && mouse.y <= 645)
    {
        return 0;
    }

    return -1;
}

//------------------------------------------------------------
// DIBUJA LA PANTALLA DE REGLAS
//------------------------------------------------------------
void Menu::dibujarReglas(sf::RenderWindow &ventana)
{
    //------------------------------------------------------------
    // FONDO
    //------------------------------------------------------------
    ventana.draw(*_spriteReglas);

    _textoReglas->setString(

        "Cada jugador contara con un maximo de 3 fichas dentro del tablero.\n\n"
        "Los jugadores jugaran por turnos alternados.\n\n"
        "Una vez colocadas las 3 fichas deberan mover una de ellas.\n\n"
        "Los objetos especiales consumen energia.\n\n"
        "Cada objeto especial solo puede utilizarse una vez.\n\n"
        "Solo puede existir una torre activa.\n\n"
        "La torre bloquea una casilla temporalmente.\n\n"
        "La bomba destruye una ficha enemiga.\n\n"
        "La mina energetica otorga energia adicional.\n\n"
        "Los objetos especiales no modifican la condicion de victoria.\n\n"
        "Gana quien forme una linea horizontal, vertical o diagonal.\n\n"
        "Si nadie gana luego de 20 movimientos,\n"
        "la partida finaliza en empate."
    );

    ventana.draw(*_textoReglas);
}
//------------------------------------------------------------
// DIBUJA LA PANTALLA DEL CONTRATO
//------------------------------------------------------------
void Menu::dibujarContrato(sf::RenderWindow &ventana)
{
    //------------------------------------------------------------
    // FONDO
    //------------------------------------------------------------
    ventana.draw(*_spriteContrato);

    //------------------------------------------------------------
    // TEXTO DEL CONTRATO
    //------------------------------------------------------------
    _textoContrato->setString(

        "Durante anos hemos observado cada uno de sus movimientos.\n\n"

        "Su inteligencia, estrategia y capacidad para enfrentar\n"
        "cualquier desafio lo convierten en un candidato ideal\n"
        "para la Resistencia Humana.\n\n"

        "La guerra contra los Aliens ha comenzado.\n"
        "Necesitamos comandantes capaces de cambiar\n"
        "el destino de la galaxia.\n\n"

        "Si acepta esta mision, su nombre quedara\n"
        "registrado en el Archivo Central de la\n"
        "Resistencia Humana.\n\n"

        "Ingrese su ID como firma para aceptar\n"
        "esta mision."
    );
    ventana.draw(*_textoContrato);

    //------------------------------------------------------------
    // MUESTRA EL NOMBRE DEL JUGADOR
    //------------------------------------------------------------
    _textoNombreJugador->setString(_nombreJugador);

    ventana.draw(*_textoNombreJugador);

}
    //------------------------------------------------------------
// CONFIRMA EL CONTRATO Y GUARDA EL JUGADOR
//------------------------------------------------------------
void Menu::ConfirmarContrato()
{
    //------------------------------------------------------------
    // SI NO SE INGRESO NOMBRE
    //------------------------------------------------------------
    if (_cantidadCaracteres == 0)
    {
        return;
    }

    //------------------------------------------------------------
    // CREA EL JUGADOR
    //------------------------------------------------------------
    Jugador jugador;

    jugador.setNombre(_nombreJugador);

    //------------------------------------------------------------
    // SI EL JUGADOR NO EXISTE LO GUARDA
    //------------------------------------------------------------
    if (!_archivoJugadores.BuscarJugador(_nombreJugador))
    {
        _archivoJugadores.GuardarJugador(jugador);
    }
}


//------------------------------------------------------------
// DIBUJA LA PANTALLA DEL RANKING
//------------------------------------------------------------
void Menu::dibujarRanking(sf::RenderWindow &ventana)
{
    //------------------------------------------------------------
    // DIBUJA EL FONDO
    //------------------------------------------------------------
    ventana.draw(*_spriteRanking);

    //------------------------------------------------------------
    // CANTIDAD DE JUGADORES
    //------------------------------------------------------------
    int cantidadJugadores;

    cantidadJugadores = _archivoJugadores.CantidadJugadores();

    //------------------------------------------------------------
    // POSICION VERTICAL DE LA PRIMERA FILA
    //------------------------------------------------------------
    int posicionY = 240;

    //------------------------------------------------------------
    // RECORRE TODOS LOS JUGADORES
    //------------------------------------------------------------
    for (int i = 0; i < cantidadJugadores; i++)
    {
        Jugador jugador;

        jugador = _archivoJugadores.LeerJugador(i);

        if (jugador.getEliminado() == false)
        {
            //------------------------------------------------------------
            // NOMBRE
            //------------------------------------------------------------
            _textoPantallaRanking->setPosition(
                sf::Vector2f(360.f, posicionY));

            _textoPantallaRanking->setString(
                jugador.getNombre());

            ventana.draw(*_textoPantallaRanking);

            //------------------------------------------------------------
            // VICTORIAS
            //------------------------------------------------------------
            _textoPantallaRanking->setPosition(
                sf::Vector2f(650.f, posicionY));

            _textoPantallaRanking->setString(
                to_string(jugador.getVictorias()));

            ventana.draw(*_textoPantallaRanking);

            //------------------------------------------------------------
            // EMPATES
            //------------------------------------------------------------
            _textoPantallaRanking->setPosition(
                sf::Vector2f(855.f, posicionY));

            _textoPantallaRanking->setString(
                to_string(jugador.getEmpates()));

            ventana.draw(*_textoPantallaRanking);

            //------------------------------------------------------------
            // DERROTAS
            //------------------------------------------------------------
            _textoPantallaRanking->setPosition(
                sf::Vector2f(1065.f, posicionY));

            _textoPantallaRanking->setString(
                to_string(jugador.getDerrotas()));

            ventana.draw(*_textoPantallaRanking);

            //------------------------------------------------------------
            // SIGUIENTE FILA
            //------------------------------------------------------------
            posicionY += 62;
        }
    }
}
//------------------------------------------------------------
// VERIFICA SI SE PRESIONO EL BOTON VOLVER
//------------------------------------------------------------
bool Menu::PresionoBotonVolver(sf::Vector2i posicionMouse)
{
    sf::FloatRect areaBoton;

    areaBoton = _botonVolver.getGlobalBounds();

    return areaBoton.contains(
               sf::Vector2f(posicionMouse));
}
//------------------------------------------------------------
// VERIFICA SI SE PRESIONÓ EL BOTÓN CONFIRMAR
//------------------------------------------------------------
bool Menu::PresionoBotonConfirmar(sf::Vector2i posicionMouse)
{
    if (posicionMouse.x >= 505 && posicionMouse.x <= 780 &&
        posicionMouse.y >= 610 && posicionMouse.y <= 675)
    {
        return true;
    }

    return false;
}
