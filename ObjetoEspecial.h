#pragma once
#include "Tablero.h"

class ObjetoEspecial{
protected:
    int _costoEnergia; //costo de energia para colocar el objeto especial
    char _nombre[20]; //nombre del objeto especial
public:
    //constructores
    ObjetoEspecial();
    ObjetoEspecial(int costo, const char* nombre);

    //getters
    int getCostoEnergia();

    //polimorfismo dinamico
    // "= 0" indica que este método es virtual puro, por lo tanto esta clase es abstracta
    // y obliga a las clases hijas a implementar aplicarEfecto().
    virtual bool aplicarEfecto(Tablero &tablero, int fila, int columna, char simboloJugador) = 0;
    //aplica el efecto del objeto especial en la posición indicada

    //destruccion virtual
    // "~" indica destructor.
    // Se declara virtual para que al eliminar un ObjetoEspecial se destruya correctamente
    // el objeto derivado (Torre, Mina o Bomba).
    virtual ~ObjetoEspecial(); //destructor virtual para permitir la destrucción correcta de objetos derivados
};
