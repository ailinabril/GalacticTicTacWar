#pragma once
#include "Tablero.h"
class IA{
private:

    //creamos una referencia del tablero para no hacer una copia
    Tablero& _tablero;

public:

    // Recibe el tablero sobre el que va a jugar la IA.
    IA(Tablero& tablero);

    // Cada vez que sea turno de la computadora se llama esta función.
    void Jugar();

private:

    // Busca una posición libre cualquiera.
    bool BuscarCasillaLibre(int& fila, int& columna);

    // Busca una jugada que haga ganar al jugador indicado.
    // Si encuentra una, devuelve true y deja la posición encontrada.
    bool BuscarJugadaGanadora(char simbolo, int& fila, int& columna);

    // Cuenta cuántas fichas tiene un jugador en el tablero.
    int ContarFichas(char simbolo);

    // Mueve una ficha cuando ya hay 3 colocadas.
    void MoverFicha();
};
