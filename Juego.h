#pragma once
#include "Jugador.h"
#include "Tablero.h"
#include "Partida.h"
#include "Torre.h"
#include "Mina.h"
#include "Bomba.h"
#include "ArchivoGanarPartida.h"
#include "ArchivoJugadores.h"

class Juego{
private:
    //jugador
    Jugador _jugador;

    //cantidad de fichas
    int _cantidadFichasJugador;
    int _cantidadFichasIA;

    //energia
    int _energiaJugador;
    int _energiaIA;

    //objetos usados
    bool _torreUsadaJugador;
    bool _torreUsadaIA;
    bool _minaUsadaJugador;
    bool _minaUsadaIA;
    bool _bombaUsadaJugador;
    bool _bombaUsadaIA;
    int _movimientosTotales;
    bool _empate;
    bool _juegoTerminado;

    //partida actual
    Partida _partida;
    ArchivoPartidas _archivo;

    //archivo de jugadores
    ArchivoJugadores _archivoJugadores;

    //IA
    bool BuscarCasillaLibre(Tablero &tablero, int &fila, int &columna);
    bool BuscarJugadaGanadora(Tablero &tablero, char simbolo, int &fila, int &columnad);
    int ContarFichas(Tablero &tablero, char simbolo);
    void MoverFichaIA(Tablero &tablero);

public:
    //constructores
    Juego(); //constructor por defecto

    //funciones principales
    void IniciarPartida(); //inicia una nueva partida, cargando los datos de los jugadores y la fecha
    void Jugar(); //controla el flujo del juego, alternando turnos entre los jugadores hasta que haya un ganador o empate
    void MostrarRanking();

    //control de victorias
    bool VerificarGanador(Tablero &tablero); //verifica si hay un ganador o empate después de cada turno y actualiza las estadísticas de los jugadores y la partida
    void FinalizarPartida(); //finaliza la partida, mostrando el resultado y guardando los datos de la partida

    //archivos
    void GuardarPartida(); //guarda los datos de la partida en un archivo
    void ActualizarRanking(); //actualiza el ranking de jugadores basado en sus victorias, derrotas y empates

    //IA
    void TurnoIA(Tablero &tablero);

    //fichas
    bool ColocarFicha(Tablero &tablero, int fila, int comlumna);
    bool MoverFicha(Tablero &tablero, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, char simbolo);

    int getCantidadFichasJugador();
    int getCantidadFichasIA();
};
