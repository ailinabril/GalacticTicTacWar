#pragma once
#include "ObjetoEspecial.h"

class Mina : public ObjetoEspecial{
public:
    //constructores
    Mina(); //constructor por defecto
    bool aplicarEfecto();
     //aplica el efecto de la mina en la posición indicada, ocupa la casilla y genera energia al dueño
};
