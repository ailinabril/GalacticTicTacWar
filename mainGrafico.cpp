#include <SFML/Graphics.hpp>
#include <optional>
#include <ctime>
#include "TableroGrafico.h"

int main(){
    srand(time(NULL));
    sf::RenderWindow ventana(
        sf::VideoMode(sf::Vector2u(1280, 720)),   // Crear ventana principal
        "GalacticTicTacWar"
    );

    TableroGrafico _tablero;        // Crear tablero

    while (ventana.isOpen())
    {
        while (std::optional evento = ventana.pollEvent())
        {

            if (evento->is<sf::Event::Closed>())       // Cerrar ventana
            {
                ventana.close();
            }

            _tablero.procesarClickDelMouse(*evento, ventana);     // Procesar clicks

        }

        ventana.clear(); // Limpiar pantalla

        _tablero.dibujarTablero(ventana); // Dibujar tablero

        _tablero.actualizar();

        ventana.display();    // Mostrar frame

    }

    return 0;
}
