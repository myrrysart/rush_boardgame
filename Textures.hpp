#pragma once

#include "SFML/Graphics.hpp"
#include <array>
#include <vector>

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

struct Sprites
{
	Sprites() = delete;
	Sprites(const Textures& tex) {	                              
		 player1.setTexture(tex.playerBlue);                 
		 player2.setTexture(tex.playerGreen);                
		 level_1_tile.setTexture(tex.tileGrey);              
		 level_2_tile.setTexture(tex.tileBlue);              
		 level_3_tile.setTexture(tex.tileGreen);             
		 blue_dome.setTexture(tex.domeBlue);                 
		 green_dome.setTexture(tex.domeGreen);               
 	}                                                                                                            
                
     std::array<std::vector<sf::Sprite>, 4> spriteLevels;
     sf::Sprite level_1_tile;                            
     sf::Sprite level_2_tile;                            
     sf::Sprite level_3_tile;                            
     sf::Sprite blue_dome;                               
     sf::Sprite green_dome;                              
  	 sf::Sprite player1;                                 
     sf::Sprite player2;   
};
