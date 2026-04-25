#include <iostream>
#include <cstring>
#include "Jugador.h"
using namespace std;


///constructor original///
Jugador::Jugador(){
    _idJugador = 0;
    _victorias = 0;
    _derrotas = 0;
    _empates = 0;
    _eliminado = false;
    strcpy (_nombre, " ");

}


///constructor con parametros///
 Jugador::Jugador(int id, const char* nomb) {
    _idJugador = id;
    _victorias = 0;
    _derrotas = 0;
    _empates = 0;
    _eliminado = false;
    strcpy (_nombre, nomb);
}
