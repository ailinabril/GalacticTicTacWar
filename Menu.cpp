#include "Menu.h"

using namespace std;

void Menu::IniciarMenu(){
    int opcion;

    do {
        MostrarOpciones();

        cout<< "Ingrese una opcion: ";
        cin>> opcion;

        switch(opcion){
        case 1:
            _juego.Jugar();
            break;

        case 2:
            MostrarRanking();
            break;

        case 3:
            MostrarReglas();
            break;

        case 0:
            cout<< "Gracias por jugar a nuestro juego. ADIOS :)" <<endl;
            break;

        default:
            cout<< "Opcion invalida" <<endl;
            break;
        }

    }while (opcion != 0);
}
void Menu::MostrarOpciones(){
    cout<< "1- Jugar" <<endl;
    cout<< "2- Ranking" <<endl;
    cout<< "3- Reglas" <<endl;
    cout<< "0- Salir" <<endl;

}
void Menu::MostrarReglas(){}
void Menu::MostrarRanking(){}
