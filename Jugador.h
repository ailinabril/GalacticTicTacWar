#pragma once

class Jugador{
private:
    int _idJugador;
    char _nombre[30];
    int _victorias;
    int _derrotas;
    int _empates;
    bool _eliminado;
public:
    Jugador(); //constructor por defecto
    Jugador(int id, const char* nomb); //constructor
    void Cargar(int id); //pedir datos del jugador
    void Mostrar(); //mostrar datos

    //getters para obtener los datos
    int getIdJugador();
    const char* getNombre();
    int getVictorias();
    int getDerrotas();
    int getEmpates();
    bool getEliminado();

    //setters para modificar los datos
    void setVictorias(int victorias);
    void setDerrotas(int derrotas);
    void setEmpates(int empates);
    void setEliminado(bool estado);
};
