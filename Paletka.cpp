#include "Paletka.h"

Paletka::Paletka(float px, float py, float szer, float wys, float speed)
{
    x = px;
    y = py;
    szerokosc = szer;
    wysokosc = wys;
    predkosc = speed;

    shape.setSize({ szerokosc, wysokosc });
    shape.setOrigin(szerokosc / 2.f, wysokosc / 2.f);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void Paletka::moveLeft() {
    x -= predkosc;
    shape.setPosition(x, y);
}

void Paletka::moveRight() {
    x += predkosc;
    shape.setPosition(x, y);
}

void Paletka::clampToBounds(float width) {
    float half = szerokosc / 2.f;

    if (x - half < 0)
        x = half;

    if (x + half > width)
        x = width - half;

    shape.setPosition(x, y);
}



void Paletka::draw(sf::RenderTarget& target) {
    target.draw(shape);
}
