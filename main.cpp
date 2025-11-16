#include <SFML/Graphics.hpp>
#include "Paletka.h"
#include "Pilka.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test paletki");

    Paletka p(350, 550, 100, 20, 3);
    
    Pilka pilka(390, 300, 10, 3, 1); // ⬅ DODANE – inicjalizacja piłki


    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Sterowanie paletką
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            p.moveLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            p.moveRight();

        p.clampToBounds(800);

        // --- LOGIKA PIŁKI --- //
        pilka.ruch();       // ⬅ DODANE – ruch piłki


        window.clear();

        p.draw(window);
        pilka.rysuj(window); // ⬅ DODANE – rysowanie piłki

        window.display();
    }

    return 0;
}
