#include "Bomba.h"

///constructor///
Bomba::Bomba() : ObjetoEspecial(4, "Bomba"){
}

///destruye una ficha enemiga///
bool Bomba::aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador){
    char casilla = tablero.getCasillero(fila, columna);

    ///no se puede usar sobre una ficha propia///
    if (casilla == simboloJugador)
    {
        return false;
    }

    ///destruye la casilla///
    tablero.setCasillero(fila, columna, '*');

    return true;
}
