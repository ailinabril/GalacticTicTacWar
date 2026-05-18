#pragma once
#include "ObjetoEspecial.h"

class Bomba : public ObjetoEspecial{
public:
    //constructores
    Bomba(); //constructor por defecto
    bool aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador) override;
    //aplica el efecto de la bomba en la posición indicada, destruyendo la ficha enemiga
    // y marcando la casilla como destruida por 1 turno
};
