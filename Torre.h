#pragma once
#include "ObjetoEspecial.h"

class Torre : public ObjetoEspecial{
public:
    //constructores
    Torre(); //constructor por defecto

    //polimorfismo dinamico
    //sobre escribe el metodo del padre
    bool aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador) override;
    //aplica el efecto de la torre en la posición indicada, bloqueando esa casilla para ambos jugadores
};
