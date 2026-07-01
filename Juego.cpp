#include "Juego.h"
#include "ArchivoJugadores.h"
#include <iostream>

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
}
//------------------------------------------------------------
// INICIA UNA NUEVA PARTIDA
//------------------------------------------------------------
void Juego::IniciarPartida()
{
    _jugador.Cargar();

    if (_archivoJugadores.BuscarJugador(_jugador.getNombre()))
    {
        _jugador = _archivoJugadores.BuscarYLeerJugador(_jugador.getNombre());
    }
    else
    {
        _archivoJugadores.GuardarJugador(_jugador);
    }

    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;
    _energiaJugador = 5;
    _energiaIA = 5;
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

bool Juego::ColocarFicha(Tablero &tablero, int fila, int columna){

    //verificamos que la casilla este libre
    if(tablero.getCasillero(fila, columna) != ' '){

        return false;
    }
    //colocamos la ficha del jugador
    tablero.setCasillero(fila, columna, 'X');

    //actualizamos la cantidad de fichas colocadas
    _cantidadFichasJugador++;

    return true;
}

bool Juego::MoverFicha(Tablero &tablero, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino){
    //verificamos si la casilla del destino esta libre
    if(tablero.getCasillero(filaDestino, columnaDestino) != ' '){
        return false;
    }

    //mueve la ficha del jugador
    tablero.setCasillero(filaOrigen, columnaOrigen, ' ');
    tablero.setCasillero(filaDestino, columnaDestino, 'X');

    return true;
}

bool Juego::VerificarGanador(Tablero &tablero){

    //gana jugador
    if(tablero.HayGanador('X')){

        _juegoTerminado = true;
        _partida.setGanador(1);
        return true;
    }

    //gana IA
    if(tablero.HayGanador('O')){

        _juegoTerminado = true;
        _partida.setGanador(2);
        return true;
    }

    //empate
    if(tablero.HayEmpate()){

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

//------------------------------------------------------------
// MUESTRA EL RANKING DE JUGADORES ORDENADO POR VICTORIAS
//------------------------------------------------------------
void Juego::MostrarRanking()
{
    int cantidadJugadores = _archivoJugadores.CantidadJugadores();

    if (cantidadJugadores == 0)
    {
        cout << "No hay jugadores registrados." << endl;
        return;
    }

    Jugador* jugadores = new Jugador[cantidadJugadores];

    // Cargar todos los jugadores desde el archivo
    for (int i = 0; i < cantidadJugadores; i++)
    {
        jugadores[i] = _archivoJugadores.LeerJugador(i);
    }

    // Ordenar por cantidad de victorias (de mayor a menor)
    for (int i = 0; i < cantidadJugadores - 1; i++)
    {
        for (int j = 0; j < cantidadJugadores - i - 1; j++)
        {
            if (jugadores[j].getVictorias() < jugadores[j + 1].getVictorias())
            {
                Jugador auxiliar = jugadores[j];
                jugadores[j] = jugadores[j + 1];
                jugadores[j + 1] = auxiliar;
            }
        }
    }

    cout << endl;
    cout << "========== RANKING ==========" << endl;

    for (int i = 0; i < cantidadJugadores; i++)
    {
        if (!jugadores[i].getEliminado())
        {
            cout << i + 1 << " - "
                 << jugadores[i].getNombre()
                 << " | Victorias: "
                 << jugadores[i].getVictorias()
                 << endl;
        }
    }

    delete[] jugadores;
}

int Juego::getCantidadFichasJugador(){
    return _cantidadFichasJugador;
}

int Juego::getCantidadFichasIA(){
    return _cantidadFichasIA;
}

//------------------------------------------------------------
// REGISTRA EL RESULTADO DE LA PARTIDA
//------------------------------------------------------------
void Juego::RegistrarResultadoPartida(int ganador)
{
    _partida.setGanador(ganador);
}

