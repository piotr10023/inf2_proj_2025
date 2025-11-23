#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"

int main()
{
    const float WIDTH = 640.f;
    const float HEIGHT = 480.f;

    sf::RenderWindow window(sf::VideoMode((int)WIDTH, (int)HEIGHT), "ARKANOID");
    window.setFramerateLimit(60);

    // --- PALETKA I PILKA ---
    Paletka pal(320.f, 440.f, 100.f, 20.f, 8.f);
    Pilka pilka(320.f, 200.f, 4.f, 3.f, 8.f);

    // --- GENEROWANIE BLOKÓW ---
    std::vector<Stone> bloki;

    const int ILOSC_KOLUMN = 6;
    const int ILOSC_WIERSZY = 7;

    const float ODSTEP = 2.f;
    const float GORA_OFFSET = 50.f;

    const float ROZMIAR_BLOKU_Y = 25.f;
    const float ROZMIAR_BLOKU_X =
        (WIDTH - (ILOSC_KOLUMN - 1) * ODSTEP) / ILOSC_KOLUMN;

    for (int w = 0; w < ILOSC_WIERSZY; w++)
    {
        for (int k = 0; k < ILOSC_KOLUMN; k++)
        {
            float posX = k * (ROZMIAR_BLOKU_X + ODSTEP);
            float posY = GORA_OFFSET + w * (ROZMIAR_BLOKU_Y + ODSTEP);

            int L = (w < 1) ? 3 : (w < 3) ? 2 : 1;

            bloki.emplace_back(
                sf::Vector2f(posX, posY),
                sf::Vector2f(ROZMIAR_BLOKU_X, ROZMIAR_BLOKU_Y),
                L
            );
        }
    }

    // --- G£ÓWNA PÊTLA GRY ---
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // --- Sterowanie paletk¹ ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            pal.moveLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            pal.moveRight();
        }

        pal.clampToBounds(WIDTH);

        // --- Ruch i kolizje pi³ki ---
        pilka.move();
        pilka.collideWalls(WIDTH, HEIGHT);
        pilka.collidePaddle(pal);

        // --- PRZEGRANA ---
        if (pilka.getY() - pilka.getRadius() > HEIGHT)
        {
            std::cout << "MISS! KONIEC GRY\n";
            window.close();
        }

        // --- KOLIZJE PI£KI Z BLOKAMI ---
        for (int i = (int)bloki.size() - 1; i >= 0; i--)
        {
            Stone& blok = bloki[i];

            if (blok.isDestroyed())
                continue;

            sf::FloatRect blokRect(
                blok.getPosition(),
                blok.getSize()
            );

            float px = pilka.getX();
            float py = pilka.getY();
            float r = pilka.getRadius();

            if (blokRect.intersects(
                sf::FloatRect(px - r, py - r, r * 2.f, r * 2.f)))
            {
                blok.trafienie();
                pilka.setVy(-pilka.getVy());

                if (blok.isDestroyed())
                    bloki.erase(bloki.begin() + i);
            }
        }

        // --- RYSOWANIE ---
        window.clear(sf::Color(20, 20, 30));

        pal.draw(window);
        pilka.draw(window);

        for (auto& blok : bloki)
            blok.draw(window);

        window.display();
    }

    return 0;
}
