#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Blad wczytywania czcionki!\n";
    }

    sf::Text t;

    t.setFont(font);
    t.setFillColor(sf::Color::Cyan);
    t.setString("Nowa gra");
    t.setPosition(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 1);
    menu.push_back(t);

    t.setFont(font);
    t.setFillColor(sf::Color::White);
    t.setString("Ostatnie wyniki");
    t.setPosition(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 2);
    menu.push_back(t);

    t.setFont(font);
    t.setFillColor(sf::Color::White);
    t.setString("Wyjscie");
    t.setPosition(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 3);
    menu.push_back(t);
}

void Menu::draw(sf::RenderTarget& window)
{
    for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::przesunG()
{
    menu[selectedItem].setFillColor(sf::Color::White);
    selectedItem--;

    if (selectedItem < 0)
        selectedItem = MAX_LICZBA_POZIOMOW - 1;

    menu[selectedItem].setFillColor(sf::Color::Cyan);
}

void Menu::przesunD()
{
    menu[selectedItem].setFillColor(sf::Color::White);
    selectedItem++;

    if (selectedItem >= MAX_LICZBA_POZIOMOW)
        selectedItem = 0;

    menu[selectedItem].setFillColor(sf::Color::Cyan);
}
