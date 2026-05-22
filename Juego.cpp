#include "Juego.h"

using namespace std;

Juego::Juego(){
    _energiaJugador1 = 5;
    _energiaJugador2 = 5;

    _torreUsadaJugador1 = false;
    _torreUsadaJugador2 = false;

    _minaUsadaJugador1 = false;
    _minaUsadaJugador2 = false;

    _bombaUsadaJugador1 = false;
    _bombaUsadaJugador2 = false;

    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;

    _turnoActual = 1;
    _jugadorEnTurno = 1;
}

void Juego::IniciarPartida(){
    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;
    _energiaJugador1 = 5;
    _energiaJugador2 = 5;
    _turnoActual = 1;
    _jugadorEnTurno = 1;
}

void Juego::Jugar(){
    IniciarPartida();

    //el juego no termino
    while(!_juegoTerminado){
        MostrarEstado();
        TurnoJugador();
        VerificarGanador();
    }

    FinalizarPartida();
}

void Juego::TurnoJugador(){
    //validamos el turno actual
    if(_jugadorEnTurno == 1){
        _jugadorEnTurno = 2;
    }
    else{
        _jugadorEnTurno = 1;
    }

    _turnoActual++;
}

void Juego::MostrarEstado(){}

bool Juego::VerificarGanador(){}

void Juego::FinalizarPartida(){}






