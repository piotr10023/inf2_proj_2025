#include "Game.h"
#include <algorithm>


Game::Game()
    : m_paletka(400.f, 550.f, 120.f, 20.f, 8.f),
    m_pilka(400.f, 300.f, 4.f, 3.f, 8.f)
{
    generujBloki();
}

void Game::generujBloki()
{
    const int ILOSC_KOLUMN = 6;
    const int ILOSC_WIERSZY = 7;
    const float ROZMIAR_Y = 25.f;
    const float PRZERWA = 2.f;
    const float startY = 50.f;
    const float ROZMIAR_X = (800.f - (ILOSC_KOLUMN - 1) * PRZERWA) / ILOSC_KOLUMN;

    m_bloki.clear();

    for (int y = 0; y < ILOSC_WIERSZY; y++)
    {
        for (int x = 0; x < ILOSC_KOLUMN; x++)
        {
            float posX = x * (ROZMIAR_X + PRZERWA);
            float posY = y * (ROZMIAR_Y + PRZERWA) + startY;

            int L = (y < 1) ? 3 : (y < 3) ? 2 : 1;

            m_bloki.emplace_back(
                sf::Vector2f(posX, posY),
                sf::Vector2f(ROZMIAR_X, ROZMIAR_Y),
                L
            );
        }
    }
}

void Game::update(sf::Time dt)
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_paletka.moveLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_paletka.moveRight();
    }

    m_paletka.clampToBounds(800);

    
    m_pilka.move();
    m_pilka.collideWalls(800, 600);

    
    m_pilka.collidePaddle(m_paletka);  

    
    for (auto& blok : m_bloki)
    {
        if (!blok.isDestroyed() &&
            m_pilka.getGlobalBounds().intersects(blok.getGlobalBounds()))
        {
            blok.trafienie();
            m_pilka.setVy(-m_pilka.getVy());
        }
    }

    
    m_bloki.erase(
        std::remove_if(
            m_bloki.begin(),
            m_bloki.end(),
            [](Stone& s) { return s.isDestroyed(); }
        ),
        m_bloki.end()
    );
}

void Game::render(sf::RenderTarget& target)
{
    m_paletka.draw(target);
    m_pilka.draw(target);

    for (auto& b : m_bloki)
        b.draw(target);
}
