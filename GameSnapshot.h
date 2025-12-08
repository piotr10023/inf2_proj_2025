#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"

struct BlockData
{
    float x, y;
    int hp;
};

class GameSnapshot
{
private:
    sf::Vector2f paddlePosition;
    sf::Vector2f ballPosition;
    sf::Vector2f ballVelocity;

public:
    std::vector<BlockData> blocks;

    void capture(
        const Paletka& paletka,
        const Pilka& pilka,
        const std::vector<Stone>& bloki
    );
};
