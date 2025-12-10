#include "Stone.h"

const std::array<sf::Color, 4> Stone::m_colorLUT = {
    sf::Color::Transparent, // 0 HP
    sf::Color::Red,         // 1 HP
    sf::Color::Yellow,      // 2 HP
    sf::Color::Blue         // 3 HP
};

Stone::Stone(sf::Vector2f startPos, sf::Vector2f rozmiar, int L)
    : m_punktyZycia(L), m_jestZniszczony(false)
{
    this->setPosition(startPos);
    this->setSize(rozmiar);
    this->setOutlineThickness(2.f);
    this->setOutlineColor(sf::Color::White);

    aktualizujKolor();
}

void Stone::trafienie()
{
    if (m_jestZniszczony)
        return;

    m_punktyZycia--;
    aktualizujKolor();

    if (m_punktyZycia <= 0)
        m_jestZniszczony = true;
}

void Stone::aktualizujKolor()
{
    if (m_punktyZycia >= 0 && m_punktyZycia < (int)m_colorLUT.size())
        this->setFillColor(m_colorLUT[m_punktyZycia]);
}

void Stone::draw(sf::RenderTarget& target) const
{
    if (!m_jestZniszczony)
        target.draw(*this);
}
