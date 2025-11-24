#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"

enum class GameState
{
    Menu,
    Playing,
    Exiting
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arkanoid");
    window.setFramerateLimit(60);

    Menu menu(window.getSize().x, window.getSize().y);
    Game game;

    GameState currentState = GameState::Menu;

    sf::Clock deltaClock;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            
            if (currentState == GameState::Menu &&
                event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                    menu.przesunG();

                if (event.key.code == sf::Keyboard::Down)
                    menu.przesunD();

                if (event.key.code == sf::Keyboard::Enter)
                {
                    int pick = menu.getSelectedItem();

                    if (pick == 0)     
                        currentState = GameState::Playing;

                    if (pick == 1)     
                        ; 

                    if (pick == 2)      
                        currentState = GameState::Exiting;
                }
            }

            
            if (currentState == GameState::Playing &&
                event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                    currentState = GameState::Menu;
            }
        }

        sf::Time dt = deltaClock.restart();

        if (currentState == GameState::Playing)
        {
            game.update(dt);
        }

        window.clear();

        if (currentState == GameState::Menu)
        {
            menu.draw(window);
        }
        else if (currentState == GameState::Playing)
        {
            game.render(window);
        }
        else if (currentState == GameState::Exiting)
        {
            window.close();
        }

        window.display();
    }

    return 0;
}
