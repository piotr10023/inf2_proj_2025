#include "Paletka.h"

Paletka::Paletka(float startX, float startY, float szer, float wys, float pred)
    : x(startX), y(startY), szerokosc(szer), wysokosc(wys), predkosc(pred)
{
    shape.setSize({szerokosc, wysokosc});
    shape.setFillColor(sf::Color::White);
    shape.setPosition({x, y});
}

void Paletka::moveLeft() {
    x -= predkosc;
    shape.setPosition({x, y});
}

void Paletka::moveRight() {
    x += predkosc;
    shape.setPosition({x, y});
}

void Paletka::clampToBounds(float width) {
    if (x < 0) x = 0;
    if (x + szerokosc > width) x = width - szerokosc;
    shape.setPosition({x, y});
}

void Paletka::draw(sf::RenderTarget& target) const {
    target.draw(shape);
}

float Paletka::getX() const { return x; }
float Paletka::getY() const { return y; }
float Paletka::getSzerokosc() const { return szerokosc; }
float Paletka::getWysokosc() const { return wysokosc; }
