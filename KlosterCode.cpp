#include "KlosterCode.h"

Klostercode::Klostercode(){
    _codigo[0] = 'K';
    _codigo[1] = 'L';
    _codigo[2] = 'O';
    _codigo[3] = 'S';
    _codigo[4] = 'T';
    _codigo[5] = 'E';
    _codigo[6] = 'R';

    _pasoActual = 0;
    _activado = false;
}

void Klostercode::ProcesarLetra(char letra){
    if(letra == _codigo[_pasoActual]){
        _pasoActual++;

        if(_pasoActual == TAM){
            _activado = true;
            _pasoActual = 0;
        }
    }
    else{
        if(letra == _codigo[0])
            _pasoActual = 1;  ///un seguro por si el usuario repite dos veces una tecla por error
        else
            _pasoActual = 0;
    }
}

bool Klostercode::EstaActivado(){
    return _activado;
}

void Klostercode::Reiniciar(){
    _pasoActual = 0;
    _activado = false;
}
