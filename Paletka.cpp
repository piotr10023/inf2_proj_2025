#include "Paletka.h"

Paletka::Paletka(float px, float py, float szer, float wys, float speed)
{
    x = px;
    y = py;
    szerokosc = szer;
    wysokosc = wys;
    predkosc = speed;

    shape.setSize({ szerokosc, wysokosc });
    shape.setOrigin(szerokosc / 2, wysokosc / 2);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
}

void Paletka::draw(sf::RenderTarget& target) {
    target.draw(shape);
}
