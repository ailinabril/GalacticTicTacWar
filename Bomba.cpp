#include "Bomba.h"

// CONSTRUCTOR
Bomba::Bomba() : ObjetoEspecial(4, "Bomba")
{
}

// DESTRUYE UNA FICHA ENEMIGA

bool Bomba::aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador)
{
    //obtenemos el contenido de la casilla
    char casilla = tablero.getCasillero(fila, columna);

    //si la casilla esta vacia
    if(casilla == ' ')
    {
        return false;
    }

    //si la ficha pertenece al jugador
    if(casilla == simboloJugador)
    {
        return false;
    }

    //destruye la ficha enemiga
    tablero.setCasillero(fila, columna, ' ');

    return true;
}
