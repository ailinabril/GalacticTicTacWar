#pragma once

class Jugador{
private:
    char _nombre[30];
    int _victorias;
    int _derrotas;
    int _empates;
    bool _eliminado;
public:
   // Constructores
    Jugador();
    Jugador(const char* nombreJugador);

    // Carga los datos del jugador
    void Cargar();
    // Asigna el identificador del jugador
    void Mostrar(); //mostrar datos
    //getters para obtener los datos
    const char* getNombre();
    int getVictorias() const;
    int getDerrotas();
    int getEmpates();
    bool getEliminado();

    //setters para modificar los datos
    void setNombre(const char* nombre);
    void setVictorias(int victorias);
    void setDerrotas(int derrotas);
    void setEmpates(int empates);
    void setEliminado(bool estado);
};
