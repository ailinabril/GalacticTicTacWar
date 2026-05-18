#pragma once

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;
public:
    Fecha (); //constructor por defecto
    Fecha (int dia, int mes, int anio); //constructor

    //funciones principales
    void Cargar(); //pedir datos de la fecha
    bool ValidarFecha(); //valida que la fecha sea correcta
    void Mostrar(); //imprime la fecha en formato dd/mm/aaaa

    //getters
    int getDia();
    int getMes();
    int getAnio();

    //setters
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

};
