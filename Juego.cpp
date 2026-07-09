#include "Juego.h"
#include "ArchivoJugadores.h"
#include <iostream>

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
//------------------------------------------------------------
// INICIA UNA NUEVA PARTIDA
//------------------------------------------------------------
void Juego::IniciarPartida()
{
    _jugador.Cargar();

    if (_archivoJugadores.BuscarJugador(_jugador.getNombre()))
    {
        _jugador = _archivoJugadores.BuscarYLeerJugador(_jugador.getNombre());
    }
    else
    {
        _archivoJugadores.GuardarJugador(_jugador);
    }

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

    //si la IA todavia no coloco sus tres fichas
    if(ContarFichas(tablero, 'O') < 3){

        //1 intentar realizar una jugada ganadora
        if(BuscarJugadaGanadora(tablero, 'O', fila, columna)){
            tablero.setCasillero(fila, columna, 'O');
            _cantidadFichasIA++;
            return;
        }

        //2 si el jugador puede ganar, lo bloquea
        if(BuscarJugadaGanadora(tablero, 'X', fila, columna)){
            tablero.setCasillero(fila, columna, 'O');
            _cantidadFichasIA++;
            return;
        }

        //3 si el centro esta libre, lo ocupa
        if(tablero.getCasillero(1, 1) == ' '){
            tablero.setCasillero(1, 1, 'O');
            _cantidadFichasIA++;
            return;
        }

        //4 intenta ocupar una de las esquinas
        int esquina [4][2] = {
            {0,0},
            {0,2},
            {2,0},
            {2,2}
        };

        for(int i = 0; i < 4; i++){
            int f = esquina[i][0];
            int c = esquina [i][1];

            if(tablero.getCasillero(f, c) == ' '){
                tablero.setCasillero(f, c, 'O');
                _cantidadFichasIA++;
                return;
            }
        }
    }
  else{
        int filaOrigen;
        int columnaOrigen;
        int filaDestino;
        int columnaDestino;

        //buscamos movimientos para ganar
        if(BuscarMovimientoGanador(tablero, filaOrigen, columnaOrigen, filaDestino, columnaDestino)){
            MoverFicha(tablero, filaOrigen, columnaOrigen, filaDestino, columnaDestino, 'O');
            return;
        }

        //si no encuentras ninguno, movete una ficha al azar
        MoverFichaIA(tablero);

        return;
    }
}

bool Juego::BuscarCasillaLibre(Tablero &tablero, int &fila, int &columna){
    //recorremos todas las casillas del tablero
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //si encontramos una casilla libre, la devolvemos
            if(tablero.getCasillero(i, j) == ' '){
                fila = i;
                columna = j;
                return true;
            }
        }
    }
    // si no hay casilla libre
    return false;
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

int Juego::ContarFichas(Tablero &tablero, char simbolo){
    int contador = 0;

    //recorremos todo el tablero
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //contamos las fichas de los simbolos indicados
            if(tablero.getCasillero(i, j) == simbolo){
                contador++;
            }
        }
    }
    return contador;
}

void Juego::MoverFichaIA(Tablero &tablero){
    int filaOrigen;
    int columnaOrigen;
    int filaDestino;
    int columnaDestino;

    //buscamos movimiento ganador
    if(BuscarMovimientoGanador(tablero, filaOrigen, columnaOrigen, filaDestino, columnaDestino)){
        MoverFicha(tablero, filaOrigen, columnaOrigen, filaDestino, columnaDestino, 'O');
        return;
    }
    //si no encuentra uno ganador, mover una ficha al azar
    do{
        filaOrigen = rand() % 3;
        columnaOrigen = rand() % 3;
    }while(tablero.getCasillero(filaOrigen, columnaOrigen) != 'O');

    do{
        filaDestino = rand() % 3;
        columnaDestino = rand() % 3;
    }while(tablero.getCasillero(filaDestino, columnaDestino) != ' ');

    MoverFicha(tablero, filaOrigen, columnaOrigen, filaDestino, columnaDestino, 'O');
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

bool Juego::BuscarMovimientoGanador(Tablero &tablero, int &filaOrigen, int &columnaOrigen, int &filaDestino, int &columnaDestino){
   //recorremos todas las casillas del tablero
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //buscamos una ficha de la IA
            if(tablero.getCasillero(i, j) == 'O'){
                //la quitamos temporalmente
                tablero.setCasillero(i, j, ' ');

                //probamos moverlas a todas las casillas libres
                for(int f = 0; f < 3; f++){
                    for(int c = 0; c < 3; c++){
                        if(tablero.getCasillero(f, c) == ' '){
                            //simulamos el movimiento
                            tablero.setCasillero(f, c, 'O');

                            //nos fijamos si con este movimiento ganamos
                            if(tablero.HayGanador('O')){
                                //deshacemos la simulacion
                                tablero.setCasillero(f, c, ' ');
                                tablero.setCasillero(i, j, 'O');

                                //guardamos el movimiento encontrado
                                filaOrigen = i;
                                columnaOrigen = j;
                                filaDestino = f;
                                columnaDestino = c;

                                return true;
                            }
                             //deshacemos la simulacion
                             tablero.setCasillero(f, c, ' ');
                        }
                    }

                }
                //volvemos a colocar la ficha donde estaba
                tablero.setCasillero(i, j, 'O');
            }
        }
    }
    return false;
}

bool Juego::BuscarJugadaGanadora(Tablero &tablero, char simbolo, int &fila, int &columna){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tablero.getCasillero(i, j) == ' '){
                //simular la jugada y colocamos la fihca
                tablero.setCasillero(i, j, simbolo);

                if(tablero.HayGanador(simbolo)){
<<<<<<< HEAD
                    //dejamos el tablero como estaba
                    tablero.setCasillero(i,j, ' ');
                    fila = i;
                    columna = j;
=======
>>>>>>> 1b674b9acb3ecafe9bb91392965779e9793fdc87

                    return true;
                }
                //deshacer la simulacion
                tablero.setCasillero(i, j, ' ');
            }
        }
    }
    return false;
}
}

bool Juego::VerificarGanador(Tablero &tablero){

    //gana jugador
    if(tablero.HayGanador('O')){

        _juegoTerminado = true;
        _partida.setGanador(1);
        return true;
    }

    //gana IA
    if(tablero.HayGanador('X')){

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

//------------------------------------------------------------
// MUESTRA EL RANKING DE JUGADORES ORDENADO POR VICTORIAS
//------------------------------------------------------------
void Juego::MostrarRanking()
{
    int cantidadJugadores = _archivoJugadores.CantidadJugadores();

    if (cantidadJugadores == 0)
    {
        cout << "No hay jugadores registrados." << endl;
        return;
    }

    Jugador* jugadores = new Jugador[cantidadJugadores];

    // Cargar todos los jugadores desde el archivo
    for (int i = 0; i < cantidadJugadores; i++)
    {
        jugadores[i] = _archivoJugadores.LeerJugador(i);
    }

    // Ordenar por cantidad de victorias (de mayor a menor)
    for (int i = 0; i < cantidadJugadores - 1; i++)
    {
        for (int j = 0; j < cantidadJugadores - i - 1; j++)
        {
            if (jugadores[j].getVictorias() < jugadores[j + 1].getVictorias())
            {
                Jugador auxiliar = jugadores[j];
                jugadores[j] = jugadores[j + 1];
                jugadores[j + 1] = auxiliar;
            }
        }
    }

    cout << endl;
    cout << "========== RANKING ==========" << endl;

    for (int i = 0; i < cantidadJugadores; i++)
    {
        if (!jugadores[i].getEliminado())
        {
            cout << i + 1 << " - "
                 << jugadores[i].getNombre()
                 << " | Victorias: "
                 << jugadores[i].getVictorias()
                 << endl;
        }
    }

    delete[] jugadores;
}

int Juego::getCantidadFichasJugador(){
    return _cantidadFichasJugador;
}

int Juego::getCantidadFichasIA(){
    return _cantidadFichasIA;
}

bool Juego::getBombaUsadaJugador() // DEVUELVE SI LA BOMBA YA FUE UTILIZADA
{
    return _bombaUsadaJugador;
}

void Juego::setBombaUsadaJugador(bool estado)
{
    //guardamos el estado de la bomba
    _bombaUsadaJugador = estado;
}

void Juego::RestarEnergiaJugador(int energia) // DESCUENTA ENERGIA AL JUGADOR
{
    //descontamos energia
    _energiaJugador -= energia;

    //evitamos valores negativos
    if(_energiaJugador < 0)
    {
        _energiaJugador = 0;
    }
}

int Juego::getEnergiaJugador() // DEVUELVE LA ENERGIA DEL JUGADOR
{
    return _energiaJugador;
}

//------------------------------------------------------------
// REGISTRA EL RESULTADO DE LA PARTIDA
//------------------------------------------------------------
void Juego::RegistrarResultadoPartida(int ganador)
{
    _partida.setGanador(ganador);
}

void Juego::RestarFichaJugador() // RESTA UNA FICHA DEL JUGADOR
{
    //evitamos valores negativos
    if(_cantidadFichasJugador > 0)
    {
        _cantidadFichasJugador--;
    }
}

void Juego::RestarFichaIA() // RESTA UNA FICHA DE LA IA
{
    if(_cantidadFichasIA > 0) //evitamos valores negativos
    {
        _cantidadFichasIA--;
    }
}

