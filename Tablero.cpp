#include "Tablero.h"
#include <iostream>

using namespace std;

void Tablero::Inicializar(){
    for(int i = 0; i < 3; i++){ //filas
        for(int j = 0; j < 3; j++){ //columnas
            _tablero[i][j] = ' '; //casillas vacias
            _turnosBloqueados[i][j] = 0; //casilla no bloqueada
            _casillaDestruida[i][j] = false; //casilla no destruida por bomba

        }
    }
}

Tablero::Tablero(){
    Inicializar();
}

bool Tablero::PosicionValida(int fila, int columna){
    if ((fila < 0 || fila > 2) || (columna < 0 || columna > 2)){
        return false;
    }
    else {
        return true;
    }
}

char Tablero::getCasillero(int fila, int columna){
    return _tablero[fila][columna];
}

void Tablero::setCasillero(int fila, int columna, char valor){
    _tablero[fila][columna] = valor;
}


