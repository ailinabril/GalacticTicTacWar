#pragma once


class Partida{
private:
    int _idPartida;
    int _idJugador;
    int _ganador; //0: empate, 1: jugador gana, 2: gana IA
public:
    //constructores
    Partida(); //constructor por defecto
    Partida(int idPartida, int idJugador, int ganador);

    //getters
    int getIdPartida();
    int getIdJugador();
    int getGanador();

    //setters
    void setGanador(int ganador);
};
