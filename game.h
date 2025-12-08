#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"
#include "GameSnapshot.h"

class Game
{
private:
    Paletka m_paletka;
    Pilka   m_pilka;
    std::vector<Stone> m_bloki;

    GameSnapshot m_snapshot;

public:
    Game();

    void generujBloki();
    void update(sf::Time dt);
    void render(sf::RenderTarget& target);

    void saveSnapshot(); 
};
