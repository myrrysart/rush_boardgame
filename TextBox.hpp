#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <array>

class TextBox {
public:
    TextBox(const sf::Font& font, unsigned int characterSize);

    void setPosition(float x, float y);
    void setValues(int id, int turn, const std::array<int, 4> values);
    void draw(sf::RenderWindow& window);

private:
    void updateTextPositions();

    sf::Font _font;
    unsigned int _characterSize;
    sf::Vector2f _position;
    std::vector<sf::Text> _texts;
};
