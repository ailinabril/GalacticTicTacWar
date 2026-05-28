#include "ObjetoEspecial.h"
#include <cstring>

ObjetoEspecial::ObjetoEspecial(){
    _costoEnergia = 0;

    //strcpy sirve para copiar texto dentro de un arreglo char
    strcpy(_nombre, "");
}

ObjetoEspecial::ObjetoEspecial(int costo, const char* nombre){
    _costoEnergia = costo;
    strcpy(_nombre, nombre);
}

int ObjetoEspecial::getCostoEnergia(){
    return _costoEnergia;
}

ObjetoEspecial::~ObjetoEspecial(){}
