#include <SFML/Graphics.hpp>
#include <optional>
#include <ctime>
#include "TableroGrafico.h"
#include "Menu.h"

int main()
{
    srand(time(NULL));

    sf::RenderWindow ventana(
        sf::VideoMode(sf::Vector2u(1280, 720)),
        "GalacticTicTacWar"
    );

    TableroGrafico tablero;

    Menu menuPrincipal;

    int pantallaActual = 0;

    while (ventana.isOpen())
    {
        while (std::optional evento = ventana.pollEvent())
        {
            if (evento->is<sf::Event::Closed>())
            {
                ventana.close();
            }

            // CODIGO SECRETO KLOSTER

            if (const auto *teclaPresionada =
                        evento->getIf<sf::Event::KeyPressed>())
            {
                if (teclaPresionada->code == sf::Keyboard::Key::K)
                    tablero.procesarLetraKloster('K');

                if (teclaPresionada->code == sf::Keyboard::Key::L)
                    tablero.procesarLetraKloster('L');

                if (teclaPresionada->code == sf::Keyboard::Key::O)
                    tablero.procesarLetraKloster('O');

                if (teclaPresionada->code == sf::Keyboard::Key::S)
                    tablero.procesarLetraKloster('S');

                if (teclaPresionada->code == sf::Keyboard::Key::T)
                    tablero.procesarLetraKloster('T');

                if (teclaPresionada->code == sf::Keyboard::Key::E)
                    tablero.procesarLetraKloster('E');

                if (teclaPresionada->code == sf::Keyboard::Key::R)
                    tablero.procesarLetraKloster('R');
            }

            if (pantallaActual == 0)
            {
                if (const auto *click =evento->getIf<sf::Event::MouseButtonPressed>())
                {
                    sf::Vector2i posicionMouse =sf::Mouse::getPosition(ventana);

                    // prueba de coordenadas en consola

                    std::cout << "X: "<< posicionMouse.x<< " Y: "<< posicionMouse.y << std::endl;

                    int opcionMenu = menuPrincipal.procesarClick(posicionMouse);

                    if (opcionMenu == 1)
                    {
                        pantallaActual = 1;
                    }

                    if (opcionMenu == 3)
                    {
                        pantallaActual = 2;
                    }

                    if (opcionMenu == 0)
                    {
                        ventana.close();
                    }
                }
            }
            if (pantallaActual == 1)
            {
                tablero.procesarClickDelMouse(*evento, ventana);
            }
        }
        ventana.clear();

        if (pantallaActual == 0)
        {
            menuPrincipal.dibujar(ventana);
        }

        if (pantallaActual == 1)
        {
            tablero.dibujarTablero(ventana);
            tablero.actualizar();
        }

        if (pantallaActual == 2)
        {
            menuPrincipal.dibujarReglas(ventana);
        }

        ventana.display();
    }


    return 0;
}
