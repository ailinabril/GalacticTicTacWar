#include <iostream>
#include "Partida.h"
using namespace std;

//constructor por defecto
Partida::Partida(){
    _idPartida = 0;
    _idJugador = 0;
    _ganador = 0;
    _fecha = Fecha();
}

//constructor con parametros
Partida::Partida(int idPartida, int idJugador, int ganador, Fecha fecha){
    _idPartida = idPartida;
    _idJugador = idJugador;
    _ganador = ganador;
    _fecha = fecha;
}


//getters
int Partida::getIdPartida(){
    return _idPartida;
}

int Partida::getIdJugador(){
    return _idJugador;
}

int Partida::getGanador(){
    return _ganador;
}

Fecha Partida::getFecha(){
    return _fecha;
}

//setters
void Partida::setGanador(int ganador){
    _ganador = ganador;
}

void Partida::setFecha(Fecha fecha){
    _fecha = fecha;
}

