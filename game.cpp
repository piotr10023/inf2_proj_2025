#include "GameSnapshot.h"
#include <iostream>

// ... w class Game masz GameSnapshot m_snapshot (jeœli nie, dodaj pole)

bool Game::saveGame(const std::string& path)
{
    // pierwszy: zrób snapshot z aktualnych obiektów
    m_snapshot.capture(m_paletka, m_pilka, m_bloki);
    if (m_snapshot.saveToFile(path)) {
        std::cout << "Zapisano gre: " << path << "\n";
        return true;
    }
    else {
        std::cout << "Blad zapisu: " << path << "\n";
        return false;
    }
}

bool Game::loadGame(const std::string& path)
{
    GameSnapshot tmp;
    if (!tmp.loadFromFile(path)) {
        std::cout << "Blad wczytywania pliku: " << path << "\n";
        return false;
    }

    // przywracamy paletke
    sf::Vector2f ppos = tmp.getPaddlePosition();
    m_paletka.setPosition(ppos.x, ppos.y);

    // pilka: pozycja i predkosc
    sf::Vector2f bpos = tmp.getBallPosition();
    sf::Vector2f bvel = tmp.getBallVelocity();
    m_pilka.setPosition(bpos.x, bpos.y);
    m_pilka.setVx(bvel.x);
    m_pilka.setVy(bvel.y);

    // bloki: zbuduj od nowa u¿ywaj¹c tego samego rozmiaru co w generujBloki()
    // Musimy u¿yæ takiego samego rozmiaru jaki generowaliœmy (ROZ_X/ROZ_Y)
    const int ILOSC_KOLUMN = 6;
    const float PRZERWA = 2.f;
    const float ROZ_Y = 25.f;
    const float ROZ_X = (800.f - (ILOSC_KOLUMN - 1) * PRZERWA) / ILOSC_KOLUMN;

    m_bloki.clear();
    for (const auto& bd : tmp.blocks) {
        m_bloki.emplace_back(sf::Vector2f(bd.x, bd.y), sf::Vector2f(ROZ_X, ROZ_Y), bd.hp);
    }

    std::cout << "Wczytano gre z pliku: " << path << "\n";
    return true;
}
