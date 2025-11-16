#pragma once
#include <SFML/Graphics.hpp>

class Pilka {
private:
    float x, y;
    float dx, dy;   // prędkości w osi X i Y
    float promien;
    sf::CircleShape shape;

public:
    Pilka(float startX, float startY, float r, float predkoscX, float predkoscY);

    void ruch();
    void rysuj(sf::RenderWindow& window);
    float getX() const { return x; }
    float getY() const { return y; }
    float getPromien() const { return promien; }

    // do kolizji z paletką później:
    void odbijX();
    void odbijY();
};
