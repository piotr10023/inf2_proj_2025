
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
    // Konstruktor
    Paletka(float px, float py, float szer, float wys, float speed);

    void moveLeft();
    void moveRight();
    void clampToBounds(float width);


    // Rysowanie
    void draw(sf::RenderTarget& target);

    // Gettery (na razie tylko podstawowe)
    float getX() const { return x; }
    float getY() const { return y; }
};

