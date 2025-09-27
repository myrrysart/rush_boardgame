#include "TextBox.hpp"

TextBox::TextBox (const sf::Font& font, unsigned int characterSize)
        : _font(font), _characterSize(characterSize) {
        // Initialize text objects for each line
        for (int i = 0; i < 3; ++i) {
            sf::Text text;
            text.setFont(font);
            text.setCharacterSize(characterSize);
            text.setFillColor(sf::Color::White);
            _texts.push_back(text);
        }
    }

void TextBox::setPosition(float x, float y) {
        _position = sf::Vector2f(x, y);
        updateTextPositions();
    }

void TextBox::setValues(int activePlayer, int turn, const std::array<int, 4> tokens) {
        // Update each line of text with the current values
        _texts[0].setString("Active Player: " + std::to_string(activePlayer) + " Turn: " + std::to_string(turn));
		if (tokens.size() != 4)
			return;
        _texts[1].setString("tokens:  1   2   3   4");
        _texts[2].setString("                  " + std::to_string(tokens[0]) + " " + std::to_string(tokens[1]) + " " + std::to_string(tokens[2]) + " " + std::to_string(tokens[3]));

}

 void TextBox::draw(sf::RenderWindow& window) {
        for (const auto& text : _texts) {
            window.draw(text);
        }
    }

void TextBox::updateTextPositions() {
        // Position each line of text vertically
		_texts[0].setPosition(_position.x, _position.y);
		int offset = 375;
		int line = _characterSize + 5;
        _texts[1].setPosition(_position.x + offset, _position.y);
		_texts[2].setPosition(_position.x + offset - 35, _position.y + line);
}
