#include "IA.H"
#include <cstdlib>
using namespace std;

// Guarda la referencia al tablero recibido.
IA::IA(Tablero& tablero)
    : _tablero(tablero)


// Cuenta cuántas fichas tiene un jugador.
int IA::ContarFichas(char simbolo){
    int contador = 0;

    // Recorremos todo el tablero.
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            // Si encontramos una ficha del jugador
            if(_tablero.getCasillero(i,j)==simbolo)
            {
                contador++;
            }
        }
    }

    return contador;
}


// Busca cualquier casilla libre.
bool IA::BuscarCasillaLibre(int& fila,int& columna){
    // Probamos posiciones al azar.
    for(int intento=0;intento<100;intento++){
        int f=rand()%3;
        int c=rand()%3;

        // Si está libre devolvemos esa posición.
        if(_tablero.getCasillero(f,c)==' '){
            fila=f;
            columna=c;
            return true;
        }
    }

    return false;
}


// Busca una jugada ganadora ( tanto para ganar como para bloquear.)//

bool IA::BuscarJugadaGanadora(char simbolo,int& fila,int& columna)
{
    // Recorremos todo el tablero.
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            // Solo probamos sobre espacios vacíos.
            if(_tablero.getCasillero(i,j)==' '){
                // Simulamos colocar una ficha.
                _tablero.setCasillero(i,j,simbolo);

                // Preguntamos si con esa ficha se gana.
                if(_tablero.HayGanador(simbolo)){
                    // Dejamos el tablero como estaba.
                    _tablero.setCasillero(i,j,' ');

                    fila=i;
                    columna=j;

                    return true;
                }

                // Deshacemos la simulación.
                _tablero.setCasillero(i,j,' ');
            }
        }
    }

    return false;
}


// Mueve una ficha cuando ya tiene las 3 colocadas.

void IA::MoverFicha(){
    int origenFila;
    int origenColumna;

    int destinoFila;
    int destinoColumna;

    // Elegimos una ficha cualquiera.
    do{
        origenFila=rand()%3;
        origenColumna=rand()%3;
        }
    while(_tablero.getCasillero(origenFila,origenColumna)!='O');

    // Elegimos un destino libre.
    if(BuscarCasillaLibre(destinoFila,destinoColumna)){
        // Quitamos la ficha vieja.
        _tablero.setCasillero(origenFila,origenColumna,' ');

        // Colocamos la nueva.
        _tablero.setCasillero(destinoFila,destinoColumna,'O');
    }
}


void IA::Jugar()
{
    int fila;
    int columna;

    // Si todavía no tiene las 3 fichas
    if(ContarFichas('O')<3){
        // 1° Intentar ganar.
        if(BuscarJugadaGanadora('O',fila,columna)){
            _tablero.ColocarFicha(fila,columna,'O');
            return;
        }

        // 2° Bloquear al jugador.
        if(BuscarJugadaGanadora('X',fila,columna)){
            _tablero.ColocarFicha(fila,columna,'O');
            return;
        }

        // 3° Tomar el centro si está libre.
        if(_tablero.getCasillero(1,1)==' '){
            _tablero.ColocarFicha(1,1,'O');
            return;
        }

        // 4° Tomar una esquina.
        int esquinas[4][2]={
            {0,0},
            {0,2},
            {2,0},
            {2,2}
        };

        for(int i=0;i<4;i++){
            int f=esquinas[i][0];
            int c=esquinas[i][1];

            if(_tablero.getCasillero(f,c)==' '){
                _tablero.ColocarFicha(f,c,'O');
                return;
            }
        }

        // 5° Si no encontró nada, juega aleatorio.
        if(BuscarCasillaLibre(fila,columna)){
            _tablero.ColocarFicha(fila,columna,'O');
        }
    }
    else{
        // Si ya tiene las tres fichas, empieza a moverlas.
        MoverFicha();
    }
}
