#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paletka.h"
#include "Pilka.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid test");
    window.setFramerateLimit(60);

    Paletka pal(320.f, 440.f, 100.f, 20.f, 8.f);
    Pilka pilka(320.f, 200.f, 4.f, 3.f, 8.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            pal.moveLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            pal.moveRight();

        pal.clampToBounds(640.f);

        pilka.move();
        pilka.collideWalls(640.f, 480.f);
        pilka.collidePaddle(pal);

        window.clear(sf::Color(20, 20, 30));
        pal.draw(window);
        pilka.draw(window);
        window.display();
    }

    return 0;
}
