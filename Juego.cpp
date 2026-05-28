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

void Juego::MostrarEstado(){

    //actualiza estados temporales del tablero
    _tablero.ActualizarBloqueo();
    _tablero.ActualizarDestruccion();

}


bool Juego::VerificarGanador(){

    //gana jugador 1
    if(_tablero.HayGanador('X') == true){

        _juegoTerminado = true;
        return true;
    }

    //gana jugador 2
    if(_tablero.HayGanador('O') == true){

        _juegoTerminado = true;
        return true;
    }

    //empate
    if(_tablero.HayEmpate() == true){

        _empate = true;
        _juegoTerminado = true;

        return true;
    }

    return false;
}


void Juego::FinalizarPartida(){

    //guardar datos de la partida
    GuardarPartida();

    //actualizar ranking
    ActualizarRanking();

}

void Juego::GuardarPartida(){}

void Juego::ActualizarRanking(){}


