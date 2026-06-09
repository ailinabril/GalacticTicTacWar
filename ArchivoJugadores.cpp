#include <iostream>
#include "ArchivoJugadores.h"
#include <cstring>

using namespace std;

void ArchivoJugadores::GuardarJugador(Jugador jugador){
    //abrimos el archivo
    _archivo.open("jugadores.dat", ios::out | ios::binary | ios::app);

    //validamos si se abrio correctamente
    if(_archivo.is_open()){
        //guardamos el archivo
        _archivo.write((char*) &jugador, sizeof(Jugador));
    }
    else {
        cout<< "El archivo no se abrio. "<< endl;
    }
    //cerramos el archivo
    _archivo.close();
}

void ArchivoJugadores::LeerJugador(){
    //abrimos el archivo
    _archivo.open("jugadores.dat", ios::in | ios::binary);

    //validamos si se abrio correctamente
    if(_archivo.is_open()){
        Jugador cargarDatos;

        //cargamos los datos
         _archivo.read((char*) &cargarDatos, sizeof(Jugador));
    }
    else {
        cout<< "El archivo no se abrio. "<< endl;
    }

    //cerramos el archivo
    _archivo.close();
}

bool ArchivoJugadores::BuscarJugador(const char* nombre){
    //abrimos el archivo
    _archivo.open("jugadores.dat", ios::in | ios::binary);

    //validamos si se abrio correctamente
    if(_archivo.is_open()){
        Jugador cargarDatos;

        //cargamos los datos y recorremos los jugadores que estan guardados
        while(_archivo.read((char*) &cargarDatos, sizeof(Jugador))){
            //comparamos los nombres
            if(stricmp(cargarDatos.getNombre(), nombre)== 0){
                _archivo.close();
                return true;
            }
        }
    }

    _archivo.close();
    return false;
}

Jugador ArchivoJugadores::BuscarYLeerJugador(const char* nombre){
    //abrimos el archivo
    _archivo.open("jugadores.dat", ios::in | ios::binary);

    //validamos si se abrio correctamente
    Jugador cargarDatos;
    if(_archivo.is_open()){

        while(_archivo.read((char*) &cargarDatos, sizeof(Jugador))){
            if(stricmp(cargarDatos.getNombre(), nombre)== 0){
                _archivo.close();
                return cargarDatos;
            }
        }
        _archivo.close();
    }
    else {
        cout<< "El archivo no se abrio." <<endl;
    }
    return cargarDatos;
}

void ArchivoJugadores::ModificarJugador(Jugador jugador){
    //abrimos el archivo
    _archivo.open("Jugadores.dat", ios::in | ios::out | ios::binary);

    //validamos si se abrio correctamente
    Jugador modificarDatos;
    if(_archivo.is_open()){
        while(_archivo.read((char*) &modificarDatos, sizeof(Jugador))){
            if(stricmp(modificarDatos.getNombre(), jugador.getNombre()) == 0){
                //volvemos un registro
                _archivo.seekp(-sizeof(Jugador), ios::cur);
                //actualizamos al jugador
                _archivo.write((char*) &jugador, sizeof(Jugador));
                //cerramos el archivo
                _archivo.close();
                return;
            }
        }
    }
    _archivo.close();
}
