#include <iostream>
#include <cstring>
#include "Jugador.h"
using namespace std;


///constructor original///
Jugador::Jugador(){
    _idJugador = 0;
    _victorias = 0;
    _derrotas = 0;
    _empates = 0;
    _eliminado = false;
    strcpy (_nombre, " ");

}


///constructor con parametros///
 Jugador::Jugador(int id, const char* nomb) {
    _idJugador = id;
    _victorias = 0;
    _derrotas = 0;
    _empates = 0;
    _eliminado = false;
    strcpy (_nombre, nomb);
}

///cargar datos///
void Jugador::Cargar(int id) {
    _idJugador = id;

    cout << "Ingrese nombre del jugador: ";
    cin.ignore();
    cin.getline(_nombre, 30);

    _victorias = 0;
    _derrotas = 0;
    _empates = 0;
    _eliminado = false;
}

///mostrar datos///
void Jugador::Mostrar() {
    cout << "ID: " << _idJugador << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Victorias: " << _victorias << endl;
    cout << "Derrotas: " << _derrotas << endl;
    cout << "Empates: " << _empates << endl;
    cout << "Eliminado: " << (_eliminado ? "Si" : "No") << endl;
}

///getters///
int Jugador::getIdJugador() {
    return _idJugador;
}

const char* Jugador::getNombre() {
    return _nombre;
}

int Jugador::getVictorias() {
    return _victorias;
}

int Jugador::getDerrotas() {
    return _derrotas;
}

int Jugador::getEmpates() {
    return _empates;
}

bool Jugador::getEliminado() {
    return _eliminado;
}

///setters///
void Jugador::setVictorias(int victorias) {
    _victorias = victorias;
}

void Jugador::setDerrotas(int derrotas) {
    _derrotas = derrotas;
}

void Jugador::setEmpates(int empates) {
    _empates = empates;
}

void Jugador::setEliminado(bool estado) {
    _eliminado = estado;
}
