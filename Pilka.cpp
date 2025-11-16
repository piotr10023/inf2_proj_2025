#include "Pilka.h"

Pilka::Pilka(float startX, float startY, float r, float predkoscX, float predkoscY)
    : x(startX), y(startY), promien(r), dx(predkoscX), dy(predkoscY)
{
    shape.setRadius(promien);
    shape.setFillColor(sf::Color::White);
    shape.setPosition({x, y});   // ⬅ POPRAWIONE
}

void Pilka::ruch()
{
    x += dx;
    y += dy;

    // odbicie od lewej/prawej
    if (x <= 0 || x + promien * 2 >= 800)
        dx = -dx;

    // odbicie od góry/dół
    if (y <= 0 || y + promien * 2 >= 600)
        dy = -dy;

    shape.setPosition({x, y});   // ⬅ POPRAWIONE
}

void Pilka::rysuj(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Pilka::odbijX()
{
    dx = -dx;
}

void Pilka::odbijY()
{
    dy = -dy;
}
