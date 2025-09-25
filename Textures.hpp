#pragma once

#include "SFML/Graphics.hpp"

struct Textures
{
	Textures() = delete;
	Textures(std::string filename) {
		tileGrey.loadFromFile(filename, sf::IntRect(0, 0, 64, 64));
		tileBlue.loadFromFile(filename, sf::IntRect(0, 64, 64, 64));
		tileGreen.loadFromFile(filename, sf::IntRect(0, 64*2, 64, 64));
		domeBlue.loadFromFile(filename, sf::IntRect(0, 64*3, 64, 64));
		domeGreen.loadFromFile(filename, sf::IntRect(0, 64*4, 64, 64));
		playerBlue.loadFromFile(filename, sf::IntRect(0, 64*5, 64, 64));
		playerGreen.loadFromFile(filename, sf::IntRect(0, 64*6, 64, 64));
	}
	Textures(const Textures& other) = delete;
	~Textures() = default;

	sf::Texture tileGrey;
	sf::Texture tileBlue;
	sf::Texture tileGreen;
	sf::Texture domeBlue;
	sf::Texture domeGreen;
	sf::Texture playerBlue;
	sf::Texture playerGreen;
	
};
