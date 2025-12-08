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
    Paletka(float px, float py, float szer, float wys, float speed);

    void moveLeft();
    void moveRight();
    void clampToBounds(float width);

    void draw(sf::RenderTarget& target);

    float getX() const { return x; }
    float getY() const { return y; }
    float getSzerokosc() const { return szerokosc; }
    float getWysokosc() const { return wysokosc; }
};
