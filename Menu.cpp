#include "Menu.h"

using namespace std;

void Menu::IniciarMenu(){
    int opcion;

    do {
        MostrarOpciones();

        cout<< "Ingrese una opcion: ";
        cin>> opcion;

        switch(opcion){
        case 1:
            _juego.Jugar();
            break;

        case 2:
            MostrarRanking();
            break;

        case 3:
            MostrarReglas();
            break;

        case 0:
            cout<< "Gracias por jugar a nuestro juego. ADIOS :)" <<endl;
            break;

        default:
            cout<< "Opcion invalida" <<endl;
            break;
        }

    }while (opcion != 0);
}
void Menu::MostrarOpciones(){
    cout<< "1- Jugar" <<endl;
    cout<< "2- Ranking" <<endl;
    cout<< "3- Reglas" <<endl;
    cout<< "0- Salir" <<endl;

}
void Menu::MostrarReglas(){
    cout<< "Cada jugador contara con un maximo de 3 fichas dentro del tablero." <<endl;
    cout<< "Los jugadores jugaran por turnos alternados." <<endl;
    cout<< "Una vez colocadas las 3 fichas, deberan mover una de sus piezas hacia una posicion libre del tablero." <<endl;
    cout<< "Los objetos especiales consumiran energia al ser utilizados." <<endl;
    cout<< "Cada objeto especial podra utilizarse una unica vez por partida."<< endl;
    cout<< "Solo podra existir una torre activa dentro del tablero al mismo tiempo." <<endl;
    cout<< "La torre bloqueara temporalmente una casilla del tablero y unicamente podra colocarse sobre posiciones vacias." <<endl;
    cout<< "La bomba permite destruir una ficha enemiga y la casilla afectada no podra utilizarse durante un turno." <<endl;
    cout<< "La mina energetica otorgara energia adicional al jugador que la utilice." <<endl;
    cout<< "Los objetos especiales no modifica las condiciones de victoria." <<endl;
    cout<< "El jugador que consiga formar una linea horizontal, vertical o diagonal de tres fichas sera declarado ganador." <<endl;
    cout<< "En caso de que ningun jugador consiga ganar luego de 20 movimientos consecutivos despues de colocar las tres fichas, la partida finalizara en empate." <<endl;
}

void Menu::MostrarRanking(){
    _juego.MostrarRanking();
}



Menu::Menu()
{
    _texturaMenu.loadFromFile("menuPrincipal.png");

    _spriteMenu = new sf::Sprite(_texturaMenu);

    _fuente.openFromFile("Orbitron-Regular.ttf");

    _textoReglas = new sf::Text(_fuente);

    _textoReglas->setCharacterSize(22);

    _textoReglas->setFillColor(sf::Color::White);

    _textoReglas->setPosition(sf::Vector2f(50.f,50.f));

}

void Menu::dibujar(sf::RenderWindow &ventana)
{
    ventana.draw(*_spriteMenu);
}

int Menu::procesarClick(sf::Vector2i mouse)
{
    // JUGAR
    if (mouse.x >= 370 && mouse.x <= 910 && mouse.y >= 245 && mouse.y <= 330)
    {
        return 1;
    }

    // RANKING
    if (mouse.x >= 370 && mouse.x <= 910 && mouse.y >= 350 && mouse.y <= 435)
    {
        return 2;
    }

    // REGLAS
    if (mouse.x >= 370 && mouse.x <= 910 && mouse.y >= 441 && mouse.y <= 540)
    {
        return 3;
    }

    // SALIR
    if (mouse.x >= 370 && mouse.x <= 910 && mouse.y >= 560 && mouse.y <= 645)
    {
        return 0;
    }

    return -1;
}

void Menu::dibujarReglas(sf::RenderWindow &ventana)
{
    _textoReglas->setString(

    "REGLAS\n\n"

    "Cada jugador contara con un maximo de 3 fichas dentro del tablero.\n\n"
    "Los jugadores jugaran por turnos alternados.\n\n"
    "Una vez colocadas las 3 fichas, deberan mover una de sus piezas.\n\n"
    "hacia una posicion libre del tablero.\n\n"
    "Los objetos especiales consumiran energia al ser utilizados.\n\n"
    "Cada objeto especial podra utilizarse una unica vez por partida.\n\n"
    "Solo podra existir una torre activa dentro del tablero al mismo tiempo.\n\n"
    "La torre bloqueara temporalmente una casilla del tablero y unicamente.\n\n"
    "podra colocarse sobre posiciones vacias.\n\n"
    "La bomba permite destruir una ficha enemiga y la casilla afectada.\n\n"
    "no podra utilizarse durante un turno.\n\n"
    "La mina energetica otorgara energia adicional al jugador que la utilice.\n\n"
    "Los objetos especiales no modifica las condiciones de victoria.\n\n"
    "El jugador que consiga formar una linea horizontal.\n\n"
    "vertical o diagonal de tres fichas sera declarado ganador.\n\n"
    "En caso de que ningun jugador consiga ganar luego de 20 movimientos consecutivos.\n\n"
    "despues de colocar las tres fichas, la partida finalizara en empate.\n\n"
    )
;

    ventana.draw(*_textoReglas);
}
