#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"

class Game
{
private:
    static constexpr float WIDTH = 640.f;
    static constexpr float HEIGHT = 480.f;

    sf::RenderWindow m_window;
    sf::Clock        m_deltaClock;

    Paletka m_paletka;
    Pilka   m_pilka;

    std::vector<Stone> m_bloki;

private:
    void processEvents();
    void update(sf::Time dt);
    void render();

    void generujBloki();

public:
    Game();
    void run();
};
#pragma once
