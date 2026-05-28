#pragma once
#include <fstream>
#include "Partida.h"

using namespace std;

class ArchivoPartidas{
private:
    fstream _archivo;

public:
    void GuardarPartida(Partida partida);
    void LeerPartida();
};
