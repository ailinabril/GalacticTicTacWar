#include "Movimiento.h"
#include <iostream>
using namespace std;

Movimiento::Movimiento(){
    _idMovimiento = 0;
    _idPartida = 0;
    _turno = 0;
    _idJugador = 0;
    _accion = 0;
    _posicion = 0;
    _eliminado = false;
}

Movimiento::Movimiento(int idMovimiento, int idPartida, int turno, int idJugador, int accion, int posicion){
    _idMovimiento = idMovimiento;
    _idPartida = idPartida;
    _turno = turno;
    _idJugador = idJugador;
    _accion = accion;
    _posicion = posicion;
    _eliminado = false;
}

void Movimiento::Cargar(){
   cout<< "Turno: ";
   cin>> _turno;
   cout<< "Accion: ";
   cin>> _accion;
   cout<< "Posicion: ";
   cin>> _posicion;
}

void Movimiento::Mostrar(){
   cout<< "ID Partida: " << _idPartida << endl;
   cout<< "ID Jugador: " << _idJugador << endl;
   cout<< "ID Movimiento: " << _idMovimiento << endl;
   cout<< "Turno: " << _turno << endl;
   cout<< "Accion: " << _accion << endl;
   cout<< "Posicion: " << _posicion << endl;

   if (_eliminado){
        cout<< "Eliminado: SI"<<endl;
   }
   else {
        cout<< "Eliminado: NO"<<endl;
   }
}

int Movimiento::getIdMovimiento(){
    return _idMovimiento;
}

int Movimiento::getIdPartida(){
    return _idPartida;
}

int Movimiento::getTurno(){
    return _turno;
}

int Movimiento::getIdJugador(){
    return _idJugador;
}

int Movimiento::getAccion(){
    return _accion;
}

int Movimiento::getPosicion(){
    return _posicion;
}

bool Movimiento::getEliminado(){
    return _eliminado;
}

void Movimiento::setAccion(int accion){
    _accion = accion;
}

void Movimiento::setPosicion(int posicion){
    _posicion = posicion;
}

void Movimiento::setEliminado(bool estado){
    _eliminado = estado;
}
