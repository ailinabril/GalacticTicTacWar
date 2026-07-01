#include "Menu.h"

using namespace std;

//------------------------------------------------------------
// CONSTRUCTOR
//------------------------------------------------------------
Menu::Menu()
{
    _texturaMenu.loadFromFile("menuPrincipal.png");

    _spriteMenu = new sf::Sprite(_texturaMenu);

    if (!_fuente.openFromFile("Orbitron-Regular.ttf"))
    {
        cout << "Error al cargar la fuente." << endl;
    }

    //------------------------------------------------------------
    // TEXTO DE REGLAS
    //------------------------------------------------------------
    _textoReglas = new sf::Text(_fuente);

    _textoReglas->setCharacterSize(22);
    _textoReglas->setFillColor(sf::Color::White);
    _textoReglas->setPosition(sf::Vector2f(50.f, 50.f));

    //------------------------------------------------------------
    // TEXTO DEL RANKING
    //------------------------------------------------------------
    _textoPantallaRanking = new sf::Text(_fuente);

    _textoPantallaRanking->setCharacterSize(28);
    _textoPantallaRanking->setFillColor(sf::Color::White);
    _textoPantallaRanking->setPosition(sf::Vector2f(80.f, 60.f));
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
    _textoReglas->setString(

        "REGLAS\n\n"

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
// DIBUJA LA PANTALLA DEL RANKING
//------------------------------------------------------------
void Menu::dibujarRanking(sf::RenderWindow &ventana)
{
    string textoRanking;

    textoRanking = "RANKING DE JUGADORES\n\n";

    int cantidadJugadores = _archivoJugadores.CantidadJugadores();

    for (int i = 0; i < cantidadJugadores; i++)
    {
        Jugador jugador = _archivoJugadores.LeerJugador(i);

        if (jugador.getEliminado() == false)
        {
            textoRanking += jugador.getNombre();

            textoRanking += "   V: ";

            textoRanking += to_string(jugador.getVictorias());

            textoRanking += "   D: ";

            textoRanking += to_string(jugador.getDerrotas());

            textoRanking += "   E: ";

            textoRanking += to_string(jugador.getEmpates());

            textoRanking += "\n";
        }
    }

    _textoPantallaRanking->setString(textoRanking);

    ventana.draw(*_textoPantallaRanking);
}
