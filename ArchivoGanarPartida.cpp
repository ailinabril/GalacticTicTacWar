#include "ArchivoGanarPartida.h"
#include <iostream>

using namespace std;

void ArchivoPartidas::GuardarPartida(Partida partida){
    //abrimos el archivo
    _archivo.open("partidas.dat", ios::out | ios::binary | ios::app);

    //validamos si se abrio correctamente el archivo
    if(_archivo.is_open()){
        //guardamos el archivo

        // &partida obtiene la direccion en memoria del objeto partida
        // (char*) convierte los datos en bytes para guardarlos en un archivo binario
        // sizeof(Partida) indica cuantos bytes ocupa el objeto Partida
        // ios::app sirve para agregar partidas nuevas sin borrar las anteriores

        _archivo.write((char*)&partida, sizeof(Partida));
    }
    else {
        cout<< "El archivo no se abrio. "<< endl;
    }

    //cerramos archivo y liberamos memoria
    _archivo.close();
}

void ArchivoPartidas::LeerPartida(){
    //leemos el archivo
    _archivo.open("partidas.dat", ios::in | ios::binary);

    //validamos si se abrio correctamente
    if(_archivo.is_open()){
        Partida cargarDatos;

        //cargamos y leemos los datos
        _archivo.read((char*)&cargarDatos, sizeof(Partida));
    }
    else {
        cout<< "El archivo no se abrio. "<< endl;
    }

    //cerramos archivo y liberamos memoria
    _archivo.close();
}
