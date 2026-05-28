#pragma once
#include <iostream>
#include "Juego.h"

class Menu {
private:
    Juego _juego;

public:
    void IniciarMenu();
    void MostrarOpciones();
    void LeerOpcion();
    void MostrarReglas();
    void MostrarRanking();
};
