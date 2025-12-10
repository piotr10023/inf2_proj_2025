#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#include "Menu.h"
#include "Game.h"
#include "GameSnapshot.h"

enum class GameState {
    Menu,
    Playing,
    Scores,
    Exiting
};

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "Arkanoid – projekt"
    );

    window.setFramerateLimit(60);

    // MENU
    Menu menu(window.getSize().x, window.getSize().y);

    // GRA
    Game game;

    // Aktualny stan
    GameState currentState = GameState::Menu;

    sf::Clock clock;

    while (window.isOpen())
    {
        // Obs³uga zdarzeñ
        while (const std::optional ev = window.pollEvent())
        {
            const auto& event = *ev;

            // Wyjœcie z programu
            if (event.is<sf::Event::Closed>())
                window.close();

            // Obs³uga klawiatury
            if (const auto* key = event.getIf<sf::Event::KeyPressed>())
            {
                // -------------------------
                //      MENU
                // -------------------------
                if (currentState == GameState::Menu)
                {
                    if (key->scancode == sf::Keyboard::Scancode::Up)
                        menu.przesunG();

                    if (key->scancode == sf::Keyboard::Scancode::Down)
                        menu.przesunD();

                    if (key->scancode == sf::Keyboard::Scancode::Enter)
                    {
                        int id = menu.getSelectedItem();

                        if (id == 0)               // NOWA GRA
                            currentState = GameState::Playing;

                        else if (id == 1)          // SCORES
                            currentState = GameState::Scores;

                        else if (id == 2)          // EXIT
                            window.close();
                    }
                }

                // -------------------------
                //       PLAYING
                // -------------------------
                else if (currentState == GameState::Playing)
                {
                    if (key->scancode == sf::Keyboard::Scancode::Escape)
                    {
                        currentState = GameState::Menu;
                    }

                    // ZAPIS GRY
                    if (key->scancode == sf::Keyboard::Scancode::S)
                    {
                        game.saveGame("savegame.txt");
                    }

                    // WCZYTANIE GRY
                    if (key->scancode == sf::Keyboard::Scancode::L)
                    {
                        game.loadGame("savegame.txt");
                    }
                }

                // -------------------------
                //     SCORES (placeholder)
                // -------------------------
                else if (currentState == GameState::Scores)
                {
                    if (key->scancode == sf::Keyboard::Scancode::Escape)
                        currentState = GameState::Menu;
                }
            }
        }

        // -------------------------
        //   LOGIKA GRY
        // -------------------------
        sf::Time dt = clock.restart();

        if (currentState == GameState::Playing)
        {
            game.update(dt);
        }

        // -------------------------
        //        RENDER
        // -------------------------
        window.clear();

        switch (currentState)
        {
        case GameState::Menu:
            menu.draw(window);
            break;

        case GameState::Playing:
            game.render(window);
            break;

        case GameState::Scores:
            // Mo¿esz tu coœ narysowaæ
            break;

        case GameState::Exiting:
            window.close();
            break;
        }

        window.display();
    }

    return 0;
}
