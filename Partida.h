#pragma once
#include "Fecha.h"

class Partida{
private:
    int _idPartida;
    int _idJugador;
    int _ganador; //0: empate, 1: jugador gana, 2: gana IA
    Fecha _fecha;
public:
    //constructores
    Partida(); //constructor por defecto
    Partida(int idPartida, int idJugador, int ganador, Fecha fecha);

    //getters
    int getIdPartida();
    int getIdJugador();
    int getGanador();
    Fecha getFecha();

    //setters
    void setGanador(int ganador);
    void setFecha(Fecha fecha);
};
