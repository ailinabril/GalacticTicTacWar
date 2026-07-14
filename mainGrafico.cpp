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
    // 1 = Contrato
    // 2 = Juego
    // 3 = Ranking
    // 4 = Reglas
    //------------------------------------------------------------
    int pantallaActual = 0;

    while (ventana.isOpen())
    {
        //------------------------------------------------------------
        // EVENTOS
        //------------------------------------------------------------
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
            // ESCRIBIR NOMBRE DEL JUGADOR
            //------------------------------------------------------------
            if (pantallaActual == 1)
            {
                if (const auto* texto =
                            evento->getIf<sf::Event::TextEntered>())
                {
                    char letra = static_cast<char>(texto->unicode);

                    if ((letra >= 'A' && letra <= 'Z') ||
                            (letra >= 'a' && letra <= 'z') ||
                            (letra >= '0' && letra <= '9') ||
                            letra == ' ')
                    {
                        menuPrincipal.AgregarCaracter(letra);
                    }

                    if (texto->unicode == 8)
                    {
                        menuPrincipal.BorrarCaracter();
                    }
                }
            }

            //------------------------------------------------------------
            // MENU PRINCIPAL
            //------------------------------------------------------------
            if (pantallaActual == 0)
            {
                if (const auto* clickMouse =
                            evento->getIf<sf::Event::MouseButtonPressed>())
                {
                    sf::Vector2i posicionMouse;

                    posicionMouse.x = clickMouse->position.x;
                    posicionMouse.y = clickMouse->position.y;

                    int opcionSeleccionada =
                        menuPrincipal.procesarClick(posicionMouse);

                    switch (opcionSeleccionada)
                    {
                    case 1:
                        pantallaActual = 1;
                        break;

                    case 2:
                        pantallaActual = 3;
                        break;

                    case 3:
                        pantallaActual = 4;
                        break;

                    case 0:
                        ventana.close();
                        break;
                    }
                }
            }

            //------------------------------------------------------------
            // CONTRATO
            //------------------------------------------------------------
            if (pantallaActual == 1)
            {
                if (const auto* clickMouse =
                            evento->getIf<sf::Event::MouseButtonPressed>())
                {
                    sf::Vector2i posicionMouse;

                    posicionMouse.x = clickMouse->position.x;
                    posicionMouse.y = clickMouse->position.y;

                    if (menuPrincipal.PresionoBotonConfirmar(posicionMouse))
                    {
                        menuPrincipal.ConfirmarContrato();

                        tablero.IniciarPartida(menuPrincipal.getNombreJugador());

                        pantallaActual = 2;
                    }
                }
            }

            //------------------------------------------------------------
            // JUEGO
            //------------------------------------------------------------
            if (pantallaActual == 2)
            {
                tablero.procesarClickDelMouse(*evento, ventana);
            }

            //------------------------------------------------------------
            // RANKING
            //------------------------------------------------------------
            if (pantallaActual == 3)
            {
                if (const auto* clickMouse =
                            evento->getIf<sf::Event::MouseButtonPressed>())
                {
                    sf::Vector2i posicionMouse;

                    posicionMouse.x = clickMouse->position.x;
                    posicionMouse.y = clickMouse->position.y;

                    if (menuPrincipal.PresionoBotonVolver(posicionMouse))
                    {
                        pantallaActual = 0;
                    }
                }
            }

            //------------------------------------------------------------
            // REGLAS
            //------------------------------------------------------------
            if (pantallaActual == 4)
            {
                if (const auto* clickMouse =
                            evento->getIf<sf::Event::MouseButtonPressed>())
                {
                    sf::Vector2i posicionMouse;

                    posicionMouse.x = clickMouse->position.x;
                    posicionMouse.y = clickMouse->position.y;

                    if (menuPrincipal.PresionoBotonVolver(posicionMouse))
                    {
                        pantallaActual = 0;
                    }
                }
            }
        }
            //------------------------------------------------------------
    // SI TERMINÓ LA SERIE VOLVEMOS AL MENÚ
    //------------------------------------------------------------
    if (tablero.SerieTerminada())
    {
        tablero.ReiniciarSerie();

        pantallaActual = 0;
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
            menuPrincipal.dibujarContrato(ventana);
            break;

        case 2:

            tablero.dibujarTablero(ventana);
            tablero.actualizar();

            break;

        case 3:
            menuPrincipal.dibujarRanking(ventana);
            break;

        case 4:
            menuPrincipal.dibujarReglas(ventana);
            break;
        }

        ventana.display();
    }


    return 0;
}

