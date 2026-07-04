#include "Juego.h"
#include "ArchivoJugadores.h"

using namespace std;

Juego::Juego(){
    _cantidadFichasJugador = 0;
    _cantidadFichasIA = 0;

    _energiaJugador = 5;
    _energiaIA = 5;

    _torreUsadaJugador = false;
    _torreUsadaIA = false;

    _minaUsadaJugador = false;
    _minaUsadaIA = false;

    _bombaUsadaJugador = false;
    _bombaUsadaIA = false;

    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;
}

void Juego::IniciarPartida(){
    //cargar jugadores
    _jugador.Cargar(1);
    //validamos si ese nombre ya existe
    if(_archivoJugadores.BuscarJugador(_jugador.getNombre())){
        _jugador = _archivoJugadores.BuscarYLeerJugador(_jugador.getNombre());
    }
    else {
        _archivoJugadores.GuardarJugador(_jugador);
    }


    //reiniciar variables
    _movimientosTotales = 0;
    _empate = false;
    _juegoTerminado = false;
    _energiaJugador = 5;
    _energiaIA = 5;
}

void Juego::Jugar(){
    IniciarPartida();
}

void Juego::TurnoIA(Tablero &tablero){
    int fila;
    int columna;

    //si todabia no tiene las 3 fichas
    if(ContarFichas(tablero, 'O') < 3){
        //1 intentar juegar
        if(BuscarJugadaGanadora(tablero, 'O', fila, columna)){
            tablero.ColocarFicha(fila, columna, 'O');
            return;
        }

        //2 bloquear al jugador
        if(BuscarJugadaGanadora(tablero, 'X', fila, columna)){
            tablero.ColocarFicha(fila, columna,'O');
            return;
        }

        //3 tomar el centro
        if(tablero.getCasillero(1, 1) == ' '){
            tablero.ColocarFicha(1, 1, 'O');
            return;
        }
        //4 tomar una esquina
        int esquinas[4][2]={
            {0,0},
            {0,2},
            {2,0},
            {2,2}
        };

        for(int i=0;i<4;i++){
            int f=esquinas[i][0];
            int c=esquinas[i][1];

            if(tablero.getCasillero(f,c)==' '){
                tablero.ColocarFicha(f,c,'O');
                return;
            }
        }

        // 5° Si no encontró nada, juega aleatorio.
        if(BuscarCasillaLibre(tablero, fila, columna)){
            tablero.ColocarFicha(fila, columna,'O');
        }
    }
    else{
        // Si ya tiene las tres fichas, empieza a moverlas.
        MoverFichaIA(tablero);
    }
}

int Juego::ContarFichas(Tablero &tablero, char simbolo){
    int contador = 0;

    //recorremos todo el tableor
    for(int fila = 0; fila < 3; fila++){
        for(int columna = 0; columna < 3; columna++){
            //si encontramos la ficha del jugador indicado
            if(tablero.getCasillero(fila, columna) == simbolo){
                contador++;
            }
        }
    }
    return contador;
}

bool Juego::ColocarFicha(Tablero &tablero, int fila, int columna){

    //verificamos que la casilla este libre
    if(tablero.getCasillero(fila, columna) != ' '){

        return false;
    }
    //colocamos la ficha del jugador
    tablero.setCasillero(fila, columna, 'X');

    //actualizamos la cantidad de fichas colocadas
    _cantidadFichasJugador++;

    return true;
}

bool Juego::BuscarCasillaLibre(Tablero &tablero, int &fila, int &columna)
{
    //probamos posiciones al azar
    for (int intento = 0; intento < 100; intento++)
    {
        int f = rand() % 3;
        int c = rand() % 3;

        //si la casilla está libre, devolvemos esa posición
        if (tablero.getCasillero(f, c) == ' ')
        {
            fila = f;
            columna = c;
            return true;
        }
    }

    //no se encontró ninguna casilla libre
    return false;
}

bool Juego::MoverFicha(Tablero &tablero, int filaOrigen, int columnaOrigen, int filaDestino, int columnaDestino, char simbolo){
    //verificamos si la casilla del destino esta libre
    if(tablero.getCasillero(filaDestino, columnaDestino) != ' '){
        return false;
    }

    //mueve la ficha del jugador
    tablero.setCasillero(filaOrigen, columnaOrigen, ' ');
    tablero.setCasillero(filaDestino, columnaDestino, simbolo);

    return true;
}

void Juego::MoverFichaIA(Tablero &tablero){
    int filaOrigen;
    int columnaOrigen;
    int filaDestino;
    int columnaDestino;

    //buscar una ficha de la ia al azar
    do{
        filaOrigen = rand() % 3;
        columnaOrigen = rand() % 3;
    }while(tablero.getCasillero(filaOrigen, columnaOrigen) != 'O');

    //buscar una casilla libre
    BuscarCasillaLibre(tablero, filaDestino, columnaDestino);

    //Reutilizar la funcion que ya existe para mover fichas
    MoverFicha(tablero, filaOrigen, columnaOrigen, filaDestino, columnaDestino, 'O');

}

bool Juego::BuscarJugadaGanadora(Tablero &tablero, char simbolo, int &fila, int &columna){
    //recorremos todas las casillas del tablero
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //solo probamos sobre casillas vacias
            if(tablero.getCasillero(i, j) == ' '){
                //simular colocar una ficha
                tablero.setCasillero(i, j, simbolo);

                //verificamos i con esa jugada se gana
                if(tablero.HayGanador(simbolo)){
                    //dejamos el tablero como estaba
                    tablero.setCasillero(i, j, ' ');

                    fila = i;
                    columna = j;

                    return true;
                }
                //si no gana, deshacemos la simulacion
                tablero.setCasillero(i, j, ' ');
            }
        }
    }
    return false;
}

bool Juego::VerificarGanador(Tablero &tablero){

    //gana jugador
    if(tablero.HayGanador('X')){

        _juegoTerminado = true;
        _partida.setGanador(1);
        return true;
    }

    //gana IA
    if(tablero.HayGanador('O')){

        _juegoTerminado = true;
        _partida.setGanador(2);
        return true;
    }

    //empate
    if(tablero.HayEmpate()){

        _partida.setGanador(0);
        _empate = true;
        _juegoTerminado = true;

        return true;
    }

    return false;
}

void Juego::FinalizarPartida(){

    //guardar datos de la partida
    GuardarPartida();

    //actualizar ranking
    ActualizarRanking();

}

void Juego::GuardarPartida(){
    _archivo.GuardarPartida(_partida);
}

void Juego::ActualizarRanking(){
    if(_partida.getGanador() == 1){
        int victorias = _jugador.getVictorias();
        victorias++;
        _jugador.setVictorias(victorias);
    }
    else if(_partida.getGanador() == 2){
        int derrotas = _jugador.getDerrotas();
        derrotas++;
        _jugador.setDerrotas(derrotas);
    }
    else if(_partida.getGanador() == 0){
        int empates = _jugador.getEmpates();
        empates++;
        _jugador.setEmpates(empates);
    }

    _archivoJugadores.ModificarJugador(_jugador);
}

void Juego::MostrarRanking(){
    _archivoJugadores.MostrarRanking();
}

int Juego::getCantidadFichasJugador(){
    return _cantidadFichasJugador;
}

int Juego::getCantidadFichasIA(){
    return _cantidadFichasIA;
}


