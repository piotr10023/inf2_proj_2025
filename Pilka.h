#pragma once
#include <SFML/Graphics.hpp>

class Paletka;

class Pilka {
private:
    float x;
    float y;
    float vx;
    float vy;
    float radius;
    sf::CircleShape shape;

public:
    Pilka(float px, float py, float svx, float svy, float r);

    void move();
    void collideWalls(float width, float height);
    bool collidePaddle(const Paletka& p);

    void draw(sf::RenderTarget& target);

    float getX() const { return x; }
    float getY() const { return y; }
    float getVx() const { return vx; }
    float getVy() const { return vy; }
    float getRadius() const { return radius; }

    void setVx(float newVx) { vx = newVx; }
    void setVy(float newVy) { vy = newVy; }


    sf::FloatRect getGlobalBounds() const { return shape.getGlobalBounds(); }
};
