#pragma once
#include <SFML/Graphics.hpp>

class Paletka {
private:
    float x;
    float y;
    float szerokosc;
    float wysokosc;
    float predkosc;
    sf::RectangleShape shape;

public:
    Paletka(float startX, float startY, float szer, float wys, float pred);

    void moveLeft();
    void moveRight();
    void clampToBounds(float width);
    void draw(sf::RenderTarget& target) const;

    float getX() const;
    float getY() const;
    float getSzerokosc() const;
    float getWysokosc() const;
};
