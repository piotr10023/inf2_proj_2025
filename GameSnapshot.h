#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Paletka.h"
#include "Pilka.h"
#include "Stone.h"

struct BlockData {
    float x, y;
    int hp;
};

class GameSnapshot {
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

    bool saveToFile(const std::string& path) const;
    bool loadFromFile(const std::string& path);

    sf::Vector2f getPaddlePosition() const { return paddlePosition; }
    sf::Vector2f getBallPosition() const { return ballPosition; }
    sf::Vector2f getBallVelocity() const { return ballVelocity; }
};
