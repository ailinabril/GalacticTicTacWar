#include "Juego.h"
#include "ArchivoJugadores.h"

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
    //cargar jugadores
    _jugador1.Cargar(1);
    _jugador2.Cargar(2);

    //reiniciar variables
    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;
    _energiaJugador1 = 5;
    _energiaJugador2 = 5;
    _turnoActual = 1;
    _jugadorEnTurno = 1;

    //preparar tablero
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
        _partida.setGanador(1);
        return true;
    }

    //gana jugador 2
    if(_tablero.HayGanador('O') == true){

        _juegoTerminado = true;
        _partida.setGanador(2);
        return true;
    }

    //empate
    if(_tablero.HayEmpate() == true){

        _partida.setGanador(0);
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

void Juego::GuardarPartida(){
    _archivo.GuardarPartida(_partida);
}

void Juego::ActualizarRanking(){}


