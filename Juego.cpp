#include "Juego.h"
#include "ArchivoJugadores.h"

using namespace std;

Juego::Juego(){
    _cantidadFichasJugador = 0;
    _cantidadFichasIA = 0;

    _energiaJugador = 5;
    _energiaIA = 5;

    _torreUsadaJugador = false;
    _torreUsadaIA = false;

    _minaUsadaJugador = false;
    _minaUsadaIA = false;

    _bombaUsadaJugador = false;
    _bombaUsadaIA = false;

    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;

    _turnoActual = 1;
    _jugadorEnTurno = 1;
}

void Juego::IniciarPartida(){
    //cargar jugadores
    _jugador.Cargar(1);
    //validamos si ese nombre ya existe
    if(_archivoJugadores.BuscarJugador(_jugador.getNombre())){
        _jugador = _archivoJugadores.BuscarYLeerJugador(_jugador.getNombre());
    }
    else {
        _archivoJugadores.GuardarJugador(_jugador);
    }


    //reiniciar variables
    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;
    _energiaJugador = 5;
    _energiaIA = 5;
    _turnoActual = 1;
    _jugadorEnTurno = 1;

    //preparar tablero
}

void Juego::Jugar(){
    IniciarPartida();
}

void Juego::TurnoIA(Tablero &tablero){
    int fila;
    int columna;

    //si la ia todabia no coloco sus tres fichas
    if(_cantidadFichasIA < 3){

        //busca una casilla libre al azar
        do {
            fila = rand() % 3;
            columna = rand() % 3;

        } while(tablero.getCasillero(fila, columna) != ' ');

        //coloca la ficha de la ia
        tablero.setCasillero(fila, columna, 'O');

        //actualiza la candidad de fichas colocadas
        _cantidadFichasIA++;
    }
    else{
        int filaOrigen;
        int columnaOrigen;

        //elige una ficha de la ia al azar
        do{
            filaOrigen = rand() % 3;
            columnaOrigen = rand() % 3;

        } while(tablero.getCasillero(filaOrigen, columnaOrigen) != 'O');

        //busca una casilla libre para mover la ficha
        do{
            fila = rand() % 3;
            columna = rand() % 3;

        } while(tablero.getCasillero(fila, columna) != ' ');

        //mueve la ficha a la nueva posicion
        tablero.setCasillero(filaOrigen, columnaOrigen, ' ');
        tablero.setCasillero(fila, columna, 'O');
    }
}

bool Juego::VerificarGanador(){

    //gana jugador
    if(_tablero.HayGanador('X')){

        _juegoTerminado = true;
        _partida.setGanador(1);
        return true;
    }

    //gana IA
    if(_tablero.HayGanador('O')){

        _juegoTerminado = true;
        _partida.setGanador(2);
        return true;
    }

    //empate
    if(_tablero.HayEmpate()){

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

void Juego::ActualizarRanking(){
    if(_partida.getGanador() == 1){
        int victorias = _jugador.getVictorias();
        victorias++;
        _jugador.setVictorias(victorias);
    }
    else if(_partida.getGanador() == 2){
        int derrotas = _jugador.getDerrotas();
        derrotas++;
        _jugador.setDerrotas(derrotas);
    }
    else if(_partida.getGanador() == 0){
        int empates = _jugador.getEmpates();
        empates++;
        _jugador.setEmpates(empates);
    }

    _archivoJugadores.ModificarJugador(_jugador);
}

void Juego::MostrarRanking(){
    _archivoJugadores.MostrarRanking();
}


