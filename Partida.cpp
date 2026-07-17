#include <iostream>
#include "Partida.h"
using namespace std;

//constructor por defecto
Partida::Partida(){
    _idPartida = 0;
    _idJugador = 0;
    _ganador = 0;
}

//constructor con parametros
Partida::Partida(int idPartida, int idJugador, int ganador){
    _idPartida = idPartida;
    _idJugador = idJugador;
    _ganador = ganador;
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

//setters
void Partida::setGanador(int ganador){
    _ganador = ganador;
}


