#include "Mina.h"
#include <cstring>

///constructor///
Mina::Mina() : ObjetoEspecial(2) {
    strcpy(_nombre, "Mina");
}

///ocupa la casilla y genera energía///
bool Mina::aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador) {

    char casilla = tablero.getCasillero(fila, columna);

    if (casilla == simboloJugador) {  ///no se puede usar sobre mi propia ficha///
        return false;
    }

    tablero.setCasillero(fila, columna, simboloJugador); ///coloca una ficha mia en la casilla///
    //lo mismo que con el get falta declarar los setters//
    return true;
}
