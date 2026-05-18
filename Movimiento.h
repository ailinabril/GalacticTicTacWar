#pragma once

class Movimiento{
private:
    int _idMovimiento;
    int _idPartida;
    int _turno;
    int _idJugador;
    int _accion;
    int _posicion;
    bool _eliminado;
public:
    //constructores
    Movimiento(); //constructor por defecto
    Movimiento(int idMovimiento, int idPartida, int turno, int idJugador, int accion, int posicion);

    //funciones principales
    void Cargar(); //pedir datos del movimiento
    void Mostrar(); //mostrar el movimiento

    //getters
    int getIdMovimiento();
    int getIdPartida();
    int getTurno();
    int getIdJugador();
    int getAccion();
    int getPosicion();
    bool getEliminado();

    //setters
    void setAccion(int accion);
    void setPosicion(int posicion);
    void setEliminado(bool estado);
};
