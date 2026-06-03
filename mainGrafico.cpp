#include <SFML/Graphics.hpp>
#include <optional>
#include <ctime>
#include "TableroGrafico.h"

int main()
{
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

            if (const auto *tecla = evento->getIf<sf::Event::KeyPressed>())
            {
                if (tecla->code == sf::Keyboard::Key::K)
                {
                    _tablero.procesarLetraKloster('K');
                }
                if (tecla->code == sf::Keyboard::Key::L)
                {
                    _tablero.procesarLetraKloster('L');
                }
                if (tecla->code == sf::Keyboard::Key::O)
                {
                    _tablero.procesarLetraKloster('O');
                }
                if (tecla->code == sf::Keyboard::Key::S)
                {
                    _tablero.procesarLetraKloster('S');
                }
                if (tecla->code == sf::Keyboard::Key::T)
                {
                    _tablero.procesarLetraKloster('T');
                }
                if (tecla->code == sf::Keyboard::Key::E)
                {
                    _tablero.procesarLetraKloster('E');
                }
                if (tecla->code == sf::Keyboard::Key::R)
                {
                    _tablero.procesarLetraKloster('R');
                }
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
