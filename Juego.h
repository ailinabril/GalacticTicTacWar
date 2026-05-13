
#pragma once
#include "Jugador.h"
#include "Tablero.h"
#include "Partida.h"
#include "Movimiento.h"
#include "Torre.h"
#include "Mina.h"
#include "Bomba.h"

class Juego{
private:
    //jugadores
    Jugador _jugador1;
    Jugador _jugador2;

    //tablero
    Tablero _tablero;

    //energia
    int _energiaJugador1;
    int _energiaJugador2;

    //objetos usados
    bool _torreUsadaJugador1;
    bool _torreUsadaJugador2;
    bool _minaUsadaJugador1;
    bool _minaUsadaJugador2;
    bool _bombasUsadasJugador1;
    bool _bombasUsadasJugador2;

    //partida actual
    Partida _partida;

    //turnos
    int _turnoActual;
    int _jugadorEnTurno;

public:
    //constructores
    Juego(); //constructor por defecto

    //funciones principales
    void IniciarPartida(); //inicia una nueva partida, cargando los datos de los jugadores y la fecha
    void Jugar(); //controla el flujo del juego, alternando turnos entre los jugadores hasta que haya un ganador o empate
    void TurnoJugador(); //realiza las acciones del jugador en turno, como colocar ficha, usar objetos especiales, etc.
    void MostrarEstado(); //muestra el estado actual del juego, incluyendo el tablero, energia de los jugadores y objetos usados

    //control de victorias
    bool VerificarGanador(); //verifica si hay un ganador o empate después de cada turno y actualiza las estadísticas de los jugadores y la partida
    void FinalizarPartida(); //finaliza la partida, mostrando el resultado y guardando los datos de la partida

    //archivos
    void GuardarPartida(); //guarda los datos de la partida en un archivo
    void GuardarMovimiento(int jugador, int accion, int posicion); //guarda los movimientos realizados por los jugadores en un archivo
    void ActualizarRanking(); //actualiza el ranking de jugadores basado en sus victorias, derrotas y empates
};
