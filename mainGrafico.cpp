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

    //------------------------------------------------------------
    // OBJETOS PRINCIPALES
    //------------------------------------------------------------
    TableroGrafico tablero;
    Menu menuPrincipal;

    //------------------------------------------------------------
    // PANTALLA ACTUAL
    // 0 = Menu
    // 1 = Juego
    // 2 = Ranking
    // 3 = Reglas
    //------------------------------------------------------------
    int pantallaActual = 0;

    while (ventana.isOpen())
    {
        while (std::optional evento = ventana.pollEvent())
        {
            //------------------------------------------------------------
            // CERRAR VENTANA
            //------------------------------------------------------------
            if (evento->is<sf::Event::Closed>())
            {
                ventana.close();
            }

            //------------------------------------------------------------
            // CODIGO SECRETO KLOSTER
            //------------------------------------------------------------
            if (const auto* teclaPresionada =
                    evento->getIf<sf::Event::KeyPressed>())
            {
                switch (teclaPresionada->code)
                {
                case sf::Keyboard::Key::K:
                    tablero.procesarLetraKloster('K');
                    break;

                case sf::Keyboard::Key::L:
                    tablero.procesarLetraKloster('L');
                    break;

                case sf::Keyboard::Key::O:
                    tablero.procesarLetraKloster('O');
                    break;

                case sf::Keyboard::Key::S:
                    tablero.procesarLetraKloster('S');
                    break;

                case sf::Keyboard::Key::T:
                    tablero.procesarLetraKloster('T');
                    break;

                case sf::Keyboard::Key::E:
                    tablero.procesarLetraKloster('E');
                    break;

                case sf::Keyboard::Key::R:
                    tablero.procesarLetraKloster('R');
                    break;

                default:
                    break;
                }
            }

            //------------------------------------------------------------
            // MENU PRINCIPAL
            //------------------------------------------------------------
            if (pantallaActual == 0)
            {
                if (const auto* click =
                        evento->getIf<sf::Event::MouseButtonPressed>())
                {
                    sf::Vector2i posicionMouse =
                        sf::Mouse::getPosition(ventana);

                    int opcionSeleccionada =
                        menuPrincipal.procesarClick(posicionMouse);

                    switch (opcionSeleccionada)
                    {
                    case 1:
                        pantallaActual = 1;
                        break;

                    case 2:
                        pantallaActual = 2;
                        break;

                    case 3:
                        pantallaActual = 3;
                        break;

                    case 0:
                        ventana.close();
                        break;
                    }
                }
            }

            //------------------------------------------------------------
            // JUEGO
            //------------------------------------------------------------
            if (pantallaActual == 1)
            {
                tablero.procesarClickDelMouse(*evento, ventana);
            }
        }

        //------------------------------------------------------------
        // DIBUJAR PANTALLA
        //------------------------------------------------------------
        ventana.clear();

        switch (pantallaActual)
        {
        case 0:
            menuPrincipal.dibujar(ventana);
            break;

        case 1:
            tablero.dibujarTablero(ventana);
            tablero.actualizar();
            break;

        case 2:
            menuPrincipal.dibujarRanking(ventana);
            break;

        case 3:
            menuPrincipal.dibujarReglas(ventana);
            break;
        }

        ventana.display();
    }

    return 0;
}
