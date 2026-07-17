#include "Mina.h"
#include <cstring>

///constructor///
Mina::Mina() : ObjetoEspecial(){
    strcpy(_nombre, "Mina");
}

///dice si la mina puede usarse
bool Mina::aplicarEfecto(){
    return true;
}
