#include "Pilka.h"
#include "Paletka.h"
#include <iostream>

Pilka::Pilka(float px, float py, float svx, float svy, float r)
{
    x = px;
    y = py;
    vx = svx;
    vy = svy;
    radius = r;

    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void Pilka::move() {
    x += vx;
    y += vy;
    shape.setPosition(x, y);
}

void Pilka::collideWalls(float width, float height)
{
    if (x - radius <= 0) {
        vx = -vx;
        x = radius;
    }

    if (x + radius >= width) {
        vx = -vx;
        x = width - radius;
    }

    if (y - radius <= 0) {
        vy = -vy;
        y = radius;
    }

    shape.setPosition(x, y);
}

bool Pilka::collidePaddle(const Paletka& p)
{
    float palX = p.getX();
    float palY = p.getY();
    float palW = p.getSzerokosc();
    float palH = p.getWysokosc();

    bool overlapX =
        x >= palX - palW / 2.f &&
        x <= palX + palW / 2.f;

    float paddleTop = palY - palH / 2.f;

    bool overlapY =
        (y + radius) >= paddleTop &&
        (y - radius) < paddleTop;

    if (overlapX && overlapY)
    {
        vy = -std::abs(vy);
        y = paddleTop - radius;
        shape.setPosition(x, y);
        std::cout << "HIT PADDLE\n";
        return true;
    }

    return false;
}

void Pilka::draw(sf::RenderTarget& target) {
    target.draw(shape);
}
