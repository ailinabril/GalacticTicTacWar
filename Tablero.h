
#pragma once

class Tablero
{
private:
    //tablero principal
    char _tablero[3][3]; //matriz para representar el tablero de juego

    //casilla destruida por la bomba
    bool _casillaDestruida[3][3]; //matriz para marcar las casillas destruidas por la bomba
public:
    //constructores
    Tablero(); //constructor por defecto

    //funciones principales
    void Inicializar(); //inicializa el tablero con espacios vacíos y sin casillas destruidas
    void Mostrar(); //imprime el tablero de 3 x 3
    bool ColocarFicha(int fila, int columna, char simbolo);
    //coloca una ficha en la posición indicada, devuelve true si se colocó correctamente,
    //false si la posición no es válida o está ocupada

    bool ColocarTorre(int fila, int columna);
    //coloca una torre en la posición indicada, bloqueando esa casilla para ambos jugadores

    bool ColocarMina(int fila, int columna);
    //coloca una mina en la posición indicada, ocupa la casilla y genera energia al dueño

    bool UsarBomba(int fila, int columna);
    // Devuelve true si se aplicó correctamente, false si la posición no es válida o no hay ficha enemiga

    //validaciones
    bool PosicionValida(int fila, int columna);
    //verifica si la posición es válida dentro del tablero

    bool CasillaLibre(int fila, int columna);
    //verifica si la casilla está libre no ocupada ni destruida

    bool PuedeColocar(int fila, int columna);
    //verifica si se puede colocar una ficha, torre, mina o bomba en la posición indicada

    //estado del ganador
    bool HayGanador(char simbolo); //verifica si hay un ganador en el tablero
    bool HayEmpate(); //verifica si hay un empate en el tablero

    //para la bomba
    void ActualizarDestruccion(); //libera la casilla destruida despues de 1 turno
};
