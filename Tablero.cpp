#include "Tablero.h"
#include <iostream>

using namespace std;

void Tablero::Inicializar(){
    for(int i = 0; i < 3; i++){ //filas
        for(int j = 0; j < 3; j++){ //columnas
            _tablero[i][j] = ' '; //casillas vacias
            _turnosBloqueados[i][j] = 0; //casilla no bloqueada
            _casillaDestruida[i][j] = false; //casilla no destruida por bomba
        }
    }
}

Tablero::Tablero(){
    Inicializar();
}

bool Tablero::PosicionValida(int fila, int columna){
    if ((fila < 0 || fila > 2) || (columna < 0 || columna > 2)){
        return false;
    }
    else {
        return true;
    }
}

char Tablero::getCasillero(int fila, int columna){
    return _tablero[fila][columna];
}

void Tablero::setCasillero(int fila, int columna, char valor){
    _tablero[fila][columna] = valor;
}

bool Tablero::CasillaLibre(int fila, int columna){
    if(PosicionValida(fila, columna)== true){
        //nos fijamos si esta vacia
        if(_tablero[fila][columna] == ' '){
            //nos fijamos si esta destruida
            if(_casillaDestruida[fila][columna]== false){
                //nos fijamos si esta bloqueada
                if(_turnosBloqueados[fila][columna]== 0){
                    return true;
                }
            }
        }

    }
    else {
        cout << "No esta libre" << endl;
        return false;
    }

    return false;
}

bool Tablero::PuedeColocar(int fila, int columna){
     return CasillaLibre(fila, columna);
}

bool Tablero::ColocarFicha(int fila, int columna, char simbolo){
    if(PuedeColocar(fila, columna)== true){
        _tablero[fila][columna] = simbolo;
        return true;
    }
    else {
        return false;
    }
}

void Tablero::Mostrar(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << _tablero[i][j];
        }
        cout<<endl;
    }
}

bool Tablero::HayGanador(char simbolo){
    //diagonal principal
    if(_tablero[0][0] == simbolo &&
       _tablero[1][1] == simbolo &&
       _tablero[2][2]== simbolo){
        return true;
       }

    //segunda diagonal
    if(_tablero[0][2] == simbolo &&
       _tablero[1][1] == simbolo &&
       _tablero[2][0]== simbolo){
        return true;
       }

    //fila 0
    if(_tablero[0][0] == simbolo &&
       _tablero[0][1] == simbolo &&
       _tablero[0][2]== simbolo){
        return true;
       }
    //fila 1
    if(_tablero[1][0] == simbolo &&
       _tablero[1][1] == simbolo &&
       _tablero[1][2]== simbolo){
        return true;
       }
    //fila 2
    if(_tablero[2][0] == simbolo &&
       _tablero[2][1] == simbolo &&
       _tablero[2][2]== simbolo){
        return true;
       }

    //columna 0
    if(_tablero[0][0] == simbolo &&
       _tablero[1][0] == simbolo &&
       _tablero[2][0]== simbolo){
        return true;
       }

    //columna 1
    if(_tablero[0][1] == simbolo &&
       _tablero[1][1] == simbolo &&
       _tablero[2][1]== simbolo){
        return true;
       }

    //columna 2
    if(_tablero[0][2] == simbolo &&
       _tablero[1][2] == simbolo &&
       _tablero[2][2]== simbolo){
        return true;
       }
    return false;
}

bool Tablero::HayEmpate(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(_tablero[i][j] == ' '){
                return false;
            }
        }
    }

    return true;
}

void Tablero::ActualizarBloqueo(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //si la casilla esta bloqueada
            if(_turnosBloqueados[i][j] > 0){
                //restamos turno
                _turnosBloqueados[i][j]--;
            }
        }
    }
}

void Tablero::ActualizarDestruccion(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //si la casilla esta destruida
            if(_casillaDestruida[i][j] == true){
                //la liberamos
                _casillaDestruida[i][j] = false;
            }
        }
    }
}

bool Tablero::ColocarTorre(int fila, int columna){
    if(PuedeColocar(fila, columna) == true){
        //colocamos la torre
        _tablero[fila][columna] = '#';

        //bloqueamos por dos turnos
        _turnosBloqueados[fila][columna] = 2;
        return true;
    }

    return false;
}

bool Tablero::ColocarMina(int fila, int columna){
    if(PuedeColocar(fila, columna) == true){
        //colocamos la mina
        _tablero[fila][columna] = 'M';
        return true;
    }

    return false;
}

bool Tablero::UsarBomba(int fila, int columna){
    //vemos si la posicion existe
    if(PosicionValida(fila, columna) == true){
        //vemos si hay algo en la casilla
        if(_tablero[fila][columna] != ' '){
            //eliminamos lo que habia
            _tablero[fila][columna] = ' ';
            //marcamos la casilla como destruida
            _casillaDestruida[fila][columna] = true;
            //bloqueamos un turno
            _turnosBloqueados[fila][columna] = 1;
            return true;
        }
    }

    return false;
}
