#include "Game.h"
#include <iostream>


Game::Game()
    : m_window(sf::VideoMode((int)WIDTH, (int)HEIGHT), "ARKANOID"),
    m_paletka(320.f, 440.f, 100.f, 20.f, 8.f),
    m_pilka(320.f, 200.f, 4.f, 3.f, 8.f)
{
    m_window.setFramerateLimit(60);
    generujBloki();
}


void Game::generujBloki()
{
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

            m_bloki.emplace_back(
                sf::Vector2f(posX, posY),
                sf::Vector2f(ROZMIAR_BLOKU_X, ROZMIAR_BLOKU_Y),
                L
            );
        }
    }
}


void Game::run()
{
    while (m_window.isOpen())
    {
        sf::Time dt = m_deltaClock.restart();
        processEvents();
        update(dt);
        render();
    }
}


void Game::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}


void Game::update(sf::Time dt)
{
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        m_paletka.moveLeft();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        m_paletka.moveRight();

    m_paletka.clampToBounds(WIDTH);

    
    m_pilka.move();
    m_pilka.collideWalls(WIDTH, HEIGHT);
    m_pilka.collidePaddle(m_paletka);

    
    if (m_pilka.getY() - m_pilka.getRadius() > HEIGHT)
    {
        std::cout << "MISS! KONIEC GRY\n";
        m_window.close();
    }

    
    for (int i = (int)m_bloki.size() - 1; i >= 0; i--)
    {
        Stone& blok = m_bloki[i];

        if (blok.isDestroyed())
            continue;

        sf::FloatRect blokRect(blok.getPosition(), blok.getSize());

        sf::FloatRect pilkaRect(
            m_pilka.getX() - m_pilka.getRadius(),
            m_pilka.getY() - m_pilka.getRadius(),
            m_pilka.getRadius() * 2.f,
            m_pilka.getRadius() * 2.f
        );

        if (blokRect.intersects(pilkaRect))
        {
            blok.trafienie();
            m_pilka.setVy(-m_pilka.getVy());

            if (blok.isDestroyed())
                m_bloki.erase(m_bloki.begin() + i);
        }
    }
}


void Game::render()
{
    m_window.clear(sf::Color(20, 20, 30));

    m_paletka.draw(m_window);
    m_pilka.draw(m_window);

    for (auto& blok : m_bloki)
        blok.draw(m_window);

    m_window.display();
}
