#include <iostream>
#include "Partida.h"
using namespace std;

//constructor por defecto
Partida::Partida(){
    _idPartida = 0;
    _idJugador1 = 0;
    _idJugador2 = 0;
    _ganador = 0;
    _fecha = Fecha();
    _eliminado = false;
}

//constructor con parametros
Partida::Partida(int idPartida, int idJugador1, int idJugador2, int ganador, Fecha fecha){
    _idPartida = idPartida;
    _idJugador1 = idJugador1;
    _idJugador2 = idJugador2;
    _ganador = ganador;
    _fecha = fecha;
    _eliminado = false;
}

void Partida::Cargar(){
    cout<< "Ingrese ID del jugador 1: ";
    cin>> _idJugador1;

    system("cls");

    cout<< "Ingrese ID del jugador 2: ";
    cin>> _idJugador2;

    _ganador = 0; //inicialmente sin ganador
    _fecha.Cargar(); //cargar la fecha de la partida
    _eliminado = false;
}

void Partida::Mostrar(){
    cout<< "ID Partida: " << _idPartida <<endl;

    cout<< "-----------------------------------" <<endl;

    cout<< "ID Jugador 1: " << _idJugador1 <<endl;

    cout<< "-----------------------------------" <<endl;

    cout<< "ID Jugador 2: " << _idJugador2 <<endl;

    cout<< "-----------------------------------" <<endl;

    cout<< "Fecha: ";
    _fecha.Mostrar();
    cout<<endl;

    cout<< "-----------------------------------" <<endl;

    cout<< "Ganador: ";

    if (_ganador == 0)
    {
        cout<< "Empate";
    }
    else if (_ganador == 1)
    {
        cout<< "Jugador 1";
    }
    else if (_ganador == 2)
    {
        cout<< "Jugador 2";
    }
    cout<<endl;
    cout<< "-----------------------------------" <<endl;
}

//getters
int Partida::getIdPartida(){
    return _idPartida;
}

int Partida::getIdJugador1(){
    return _idJugador1;
}

int Partida::getIdJugador2(){
    return _idJugador2;
}

int Partida::getGanador(){
    return _ganador;
}

Fecha Partida::getFecha(){
    return _fecha;
}

bool Partida::getEliminado(){
    return _eliminado;
}

//setters
void Partida::setGanador(int ganador){
    _ganador = ganador;
}

void Partida::setFecha(Fecha fecha){
    _fecha = fecha;
}

void Partida::setEliminado(bool estado){
    _eliminado = estado;
}
