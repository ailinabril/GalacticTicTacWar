#include <iostream>
#include <cstring>

#include "ArchivoJugadores.h"

using namespace std;

//------------------------------------------------------------
// GUARDA UN JUGADOR EN EL ARCHIVO
//------------------------------------------------------------
void ArchivoJugadores::GuardarJugador(Jugador jugador)
{
    _archivo.open("jugadores.dat", ios::out | ios::binary | ios::app);

    if (_archivo.is_open())
    {
        _archivo.write((char*)&jugador, sizeof(Jugador));
    }

    _archivo.close();
}

//------------------------------------------------------------
// BUSCA UN JUGADOR POR SU NOMBRE
//------------------------------------------------------------
bool ArchivoJugadores::BuscarJugador(const char* nombre)
{
    _archivo.open("jugadores.dat", ios::in | ios::binary);

    if (_archivo.is_open())
    {
        Jugador cargarDatos;

        while (_archivo.read((char*)&cargarDatos, sizeof(Jugador)))
        {
            if (stricmp(cargarDatos.getNombre(), nombre) == 0)
            {
                _archivo.close();
                return true;
            }
        }
    }

    _archivo.close();
    return false;
}

//------------------------------------------------------------
// BUSCA Y DEVUELVE UN JUGADOR SEGUN SU NOMBRE
//------------------------------------------------------------
Jugador ArchivoJugadores::BuscarYLeerJugador(const char* nombre)
{
    _archivo.open("jugadores.dat", ios::in | ios::binary);

    Jugador cargarDatos;

    if (_archivo.is_open())
    {
        while (_archivo.read((char*)&cargarDatos, sizeof(Jugador)))
        {
            if (stricmp(cargarDatos.getNombre(), nombre) == 0)
            {
                _archivo.close();
                return cargarDatos;
            }
        }
    }

    _archivo.close();

    return cargarDatos;
}

//------------------------------------------------------------
// MODIFICA LOS DATOS DE UN JUGADOR
//------------------------------------------------------------
void ArchivoJugadores::ModificarJugador(Jugador jugador)
{
    _archivo.open("jugadores.dat", ios::in | ios::out | ios::binary);

    Jugador modificarDatos;

    if (_archivo.is_open())
    {
        while (_archivo.read((char*)&modificarDatos, sizeof(Jugador)))
        {
            if (stricmp(modificarDatos.getNombre(), jugador.getNombre()) == 0)
            {
                _archivo.seekp(-sizeof(Jugador), ios::cur);

                _archivo.write((char*)&jugador, sizeof(Jugador));

                _archivo.close();

                return;
            }
        }
    }

    _archivo.close();
}

//------------------------------------------------------------
// ELIMINA LOGICAMENTE UN JUGADOR
//------------------------------------------------------------
bool ArchivoJugadores::EliminarJugador(const char* nombre)
{
    if (BuscarJugador(nombre))
    {
        Jugador jugador;

        jugador = BuscarYLeerJugador(nombre);

        if (!jugador.getEliminado())
        {
            jugador.setEliminado(true);

            ModificarJugador(jugador);

            return true;
        }
    }

    return false;
}

//------------------------------------------------------------
// REACTIVA UN JUGADOR ELIMINADO
//------------------------------------------------------------
bool ArchivoJugadores::ReactivarJugador(const char* nombre)
{
    if (BuscarJugador(nombre))
    {
        Jugador jugador;

        jugador = BuscarYLeerJugador(nombre);

        if (jugador.getEliminado())
        {
            jugador.setEliminado(false);

            ModificarJugador(jugador);

            return true;
        }
    }

    return false;
}

//------------------------------------------------------------
// DEVUELVE LA CANTIDAD DE JUGADORES GUARDADOS
//------------------------------------------------------------
int ArchivoJugadores::CantidadJugadores()
{
    _archivo.open("jugadores.dat", ios::in | ios::binary);

    if (!_archivo.is_open())
    {
        return 0;
    }

    _archivo.seekg(0, ios::end);

    int cantidad;

    cantidad = _archivo.tellg() / sizeof(Jugador);

    _archivo.close();

    return cantidad;
}

//------------------------------------------------------------
// LEE UN JUGADOR SEGUN SU POSICION EN EL ARCHIVO
//------------------------------------------------------------
Jugador ArchivoJugadores::LeerJugador(int posicion)
{
    Jugador jugador;

    _archivo.open("jugadores.dat", ios::in | ios::binary);

    if (_archivo.is_open())
    {
        _archivo.seekg(posicion * sizeof(Jugador), ios::beg);

        _archivo.read((char*)&jugador, sizeof(Jugador));

        _archivo.close();
    }

    return jugador;
}
