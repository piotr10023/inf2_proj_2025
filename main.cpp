#include <SFML/Graphics.hpp>
#include "Paletka.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Arkanoid test");
    window.setFramerateLimit(60);

    // Tworzymy paletkê
    Paletka pal(320.f, 440.f, 100.f, 20.f, 8.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(20, 20, 30)); // ciemne t³o
        pal.draw(window);
        window.display();
    }

    return 0;
}
