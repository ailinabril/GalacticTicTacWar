#include <iostream>
#include "Fecha.h"
using namespace std;

//constructor por defecto
//asignamos una fecha por si no se carga una fecha valida
Fecha::Fecha()
{
    _dia = 2;
    _mes = 9;
    _anio = 2003;
}

//constructor con parametros
Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

//setters
int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

//getters
void Fecha::setDia(int dia)
{
    _dia = dia;
}

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}

//validacion de la fecha
bool Fecha::ValidarFecha()
{
    if (_anio > 0 && _mes > 0 && _mes <= 12 && _dia > 0 && _dia <=31)
    {
        //validaciones de meses con 30 dias
        if ((_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11) && _dia > 30)
        {
            return false;
        }

        //validacion de febrero
        if (_mes == 2)
        {
            //año bisiesto
            if ((_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0))
            {
                if (_dia > 29)
                {
                    return false;
                }
            }
            else
            {
                if (_dia > 28)
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

//cargar datos de la fecha
void Fecha::Cargar()
{
    do
    {
        cout<< "Ingrese el dia de hoy: ";
        cin>> _dia;

        cout<< "Ingrese el mes de hoy: ";
        cin>> _mes;

        cout<< "Ingrese el anio de hoy: ";
        cin>> _anio;

        if (!ValidarFecha())
        {
            cout<< "Fecha incorrecta, por favor ingresa nuevamente."<<endl;
            system("pause");
            system("cls");
        }
    } while (!ValidarFecha());

}

//mostrar la fecha en formato dd/mm/aaaa
void Fecha::Mostrar()
{
    cout<< _dia << "/" << _mes << "/" << _anio<< endl;
}
