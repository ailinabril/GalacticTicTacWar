#pragma once
#include "Fecha.h"

class Partida
{
private:
    int _idPartida;
    int _idJugador1;
    int _idJugador2;
    int _ganador; //0: empate, 1: jugador 1 gana, 2: jugador 2 gana
    Fecha _fecha;
    bool _eliminado;
public:
    //constructores
    Partida(); //constructor por defecto
    Partida(int idPartida, int idJugador1, int idJugador2, int ganador, Fecha fecha);

    //funciones principales
    void Cargar(); //pedir datos de la partida
    void Mostrar(); //mostrar la partida

    //getters
    int getIdPartida();
    int getIdJugador1();
    int getIdJugador2();
    int getGanador();
    Fecha getFecha();
    bool getEliminado();

    //setters
    void setGanador(int ganador);
    void setFecha(Fecha fecha);
    void setEliminado(bool estado);
};
