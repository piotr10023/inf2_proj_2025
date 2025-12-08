#include "GameSnapshot.h"
#include <iostream>

void GameSnapshot::capture(
    const Paletka& paletka,
    const Pilka& pilka,
    const std::vector<Stone>& bloki
)
{
    paddlePosition = { paletka.getX(), paletka.getY() };
    ballPosition = { pilka.getX(), pilka.getY() };
    ballVelocity = { pilka.getVx(), pilka.getVy() };

    blocks.clear();
    for (const auto& b : bloki)
    {
        BlockData data;
        data.x = b.getPosition().x;
        data.y = b.getPosition().y;
        data.hp = b.getHP();
        blocks.push_back(data);
    }

    std::cout << ">>> ilosc pozsotalych blokow: " << blocks.size() << "\n";
}
