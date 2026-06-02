#pragma once
#include <fstream>
#include "Jugador.h"

using namespace std;

class ArchivoJugadores{
private:
    fstream _archivo;
public:
    void GuardarJugador(Jugador jugador);
    void LeerJugador();
    bool BuscarJugador(const char* nombre);
    Jugador BuscarYLeerJugador(const char* nombre);
};
