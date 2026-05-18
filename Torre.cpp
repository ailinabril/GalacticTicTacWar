#include "Torre.h"
#include <cstring>

///constructoer///
Torre::Torre() : ObjetoEspecial(3) {
    strcpy(_nombre, "Torre");
}

///bloquea la casilla para ambos jugadores///
bool Torre::aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador) {

    char casilla = tablero.getCasillero(fila, columna);//<----------------!!! use get.casillero pero es provicional ya que faltan en el .h y falta el .cpp del mismo//

    if (casilla == simboloJugador) {  ///no se puede poner en la casilla del jugador///
        return false;
    }

    tablero.setCasillero(fila, columna, '#'); ///bloquea la casille y elimina ficha enemiga en caso de haber///

    tablero.setTurnosBloqueados(fila, columna, 2);

    return true;
}
