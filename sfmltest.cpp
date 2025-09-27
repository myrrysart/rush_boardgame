#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <utility>
#include <algorithm>
#include "TextBox.hpp"
#include "Santorini.hpp"
#include "Textures.hpp"

bool highestY(const sf::Sprite& a, const sf::Sprite& b)
{                                                      
    return a.getPosition().y < b.getPosition().y;      
}         
//return the screen coordinates of the left corner of the selected tile
//add an offset based on bulding height?
sf::Vector2f boardToScreen(std::pair<int, int> boardPos)
{
	std::pair<int, int> origin = {37, 158};
	int	width = 116;
	int height = 58;
	float screenX = origin.first + width * (boardPos.first + boardPos.second)/ 2.f;
	float screenY = origin.second - height * (boardPos.second - boardPos.first)/ 2.f;
	return sf::Vector2f(screenX, screenY);
}

void addPiece(std::pair<int, int> target, int player, Santorini &game, Sprites sprite)
{
	float yoffset = 16.f;
	sf::Vector2f draw = boardToScreen(target);
	int level = game._board[target.first][target.second].lvl - 1;
	switch (level)
	{
		case 0:
			sprite.spriteLevels[level].push_back(sprite.level_1_tile);
			break;
		case 1:
			sprite.spriteLevels[level].push_back(sprite.level_2_tile);
			break;
		case 2:
			sprite.spriteLevels[level].push_back(sprite.level_3_tile);
			break;
		case 3:
			if (player == PLAYER1)
				sprite.spriteLevels[level].push_back(sprite.blue_dome);
			else
				sprite.spriteLevels[level].push_back(sprite.green_dome);
			break;
	}
	sprite.spriteLevels[level].back().setPosition(draw.x - 32.f, draw.y - 32.f - yoffset * level); 
	std::sort(sprite.spriteLevels[level].begin(), sprite.spriteLevels[level].end(), highestY);
}

void removeWorker(std::pair<int, int> target)
{

}

void addWorker(std::pair<int, int> target, int player, Santorini &game, Sprites sprite, std::pair<int, int> removed)
{
	sf::Vector2f draw = boardToScreen(target);
	if (removed.first != -1)
		removeWorker(removed);
	int level = game._board[target.first][target.second].lvl;
	if (player == PLAYER1)
		sprite.spriteLevels[level].push_back(sprite.player1);
	else
		sprite.spriteLevels[level].push_back(sprite.player2);
	sprite.spriteLevels[level].back().setPosition(draw.x - 32.f, draw.y - 32.f); 
	std::sort(sprite.spriteLevels[level].begin(), sprite.spriteLevels[level].end(), highestY);
}


//calculate the board coordinates of the given screen position
std::pair<int, int> screenToBoard(std::pair<int, int> click)
{
	std::pair<int, int> origin = {37, 158};
	int	width = 116;
	int height = 58;
	float isoX = click.first - origin.first;
	float isoY = click.second - origin.second;

	int boardX = static_cast<int>(isoX / width + isoY / height);
	int boardY = static_cast<int>(isoX / width - isoY / height);
	return {boardX, boardY};
}

void handleClick(sf::Event::MouseButtonEvent click, Santorini &game, Sprites sprite)
{
	std::pair<int, int> coords = screenToBoard({click.x, click.y});
	std::pair<int, int> old = game.chosenSquare;
	int player, temp;
	if (game.gameState < Santorini::State::PLAYER2_INIT_WORKER1)
		player = PLAYER1;
	else
		player = PLAYER2;
	if (!game.isValidInput(coords, player))
	{
		std::cout << "click out of bounds" << std::endl;
		return;
	}
	switch (game.gameState)
	{
		case Santorini::State::PLAYER1_INIT_WORKER1:
			if (game.placeWorker(coords, player))
			{
				addWorker(coords, player, game, sprite, old);
				temp = static_cast<int>(game.gameState); 
				game.gameState = static_cast<Santorini::State>(temp + 1);
			}
			break;
		case Santorini::State::PLAYER1_INIT_WORKER2:
			if (game.placeWorker(coords, player))
			{
				addWorker(coords, player, game, sprite, old);
				game.gameState = Santorini::State::PLAYER2_INIT_WORKER1;
			}
			break;
		case Santorini::State::PLAYER1_CHOOSE_WORKER:
		case Santorini::State::PLAYER2_CHOOSE_WORKER:
			if (game.chooseWorker(coords, player))
			{
				temp = static_cast<int>(game.gameState); 
				game.gameState = static_cast<Santorini::State>(temp + 1);
			}
			break;
		case Santorini::State::PLAYER1_MOVE_WORKER:
		case Santorini::State::PLAYER2_MOVE_WORKER:
			if (game.moveWorker(coords, player))
			{
				addWorker(coords, player, game, sprite, old);
				temp = static_cast<int>(game.gameState); 
				game.gameState = static_cast<Santorini::State>(temp + 1);
			}
			break;
		case Santorini::State::PLAYER1_BUILD:
		case Santorini::State::PLAYER2_BUILD:
			if (game.build(coords, player))
			{
				addPiece(coords, player, game, sprite);
				temp = static_cast<int>(game.gameState) + 3;
				if (temp > 10)
					game.turn++;
				temp = temp % 10; 
				game.gameState = static_cast<Santorini::State>(temp);
			}
			break;
		case Santorini::State::PLAYER2_INIT_WORKER1:
			if (game.placeWorker(coords, player))
			{
				temp = static_cast<int>(game.gameState); 
				game.gameState = static_cast<Santorini::State>(temp + 1);
			}
			break;
		case Santorini::State::PLAYER2_INIT_WORKER2:
			if (game.placeWorker(coords, player))
			{
				game.gameState = Santorini::State::PLAYER1_CHOOSE_WORKER;
				game.turn++;
			}
			break;
		default:
			break;
	}
	game.printBoard();
/*
	std::cout << "screen : (" << click.x << "," <<  click.y << ")" << std::endl;
	std::pair<int, int> c = screenToBoard({click.x, click.y});
	std::cout << "coords : (" << c.first << "," <<  c.second << ")" << std::endl;
	std::pair<int, int> drawing = boardToScreen({c.first, c.second});
	std::cout << "draw coords : (" << drawing.first << "," <<  drawing.second << ")" << std::endl;
*/
}

                                           

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "Hivetorini!");

	//set background
    sf::Texture board;
	if (!board.loadFromFile("assets/map.png"))
		std::cout << "Error loading background image" << std::endl;
	sf::Sprite	basemap;
	basemap.setTexture(board);

	//make text box
	sf::Font font;
	if (!font.loadFromFile("assets/LiberationSans-Regular.ttf"))
		std::cout << "Error loading font" << std::endl;
	TextBox textBox(font, 20);
	textBox.setPosition(10.f, 10.f);

	//Load piece sprites
     Textures tex("assets/spritesheet.png");             
	 Sprites sprite(tex);

	//game init
	Santorini mySant;
	int player;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

			switch (event.type)
			{
            	case sf::Event::Closed:
                	window.close();
					break;
				
				case sf::Event::KeyPressed:                                 
					break;

				case sf::Event::MouseButtonPressed:
					if (event.mouseButton.button == sf::Mouse::Left)
						handleClick(event.mouseButton, mySant, sprite);
					break;
				
				default:
					break;
			}
        }
		if (mySant.gameState < Santorini::State::PLAYER2_INIT_WORKER1)
			player = PLAYER1;
		else
			player = PLAYER2;
		textBox.setValues(player, mySant.turn, mySant.pieces);
        window.clear();
	    window.draw(basemap);
		textBox.draw(window);
        for (auto& tile : sprite.spriteLevels[0])
            window.draw(tile);               
        for (auto& tile : sprite.spriteLevels[1])
            window.draw(tile);               
		for (auto& tile : sprite.spriteLevels[2])
            window.draw(tile);               
        for (auto& tile : sprite.spriteLevels[3])
            window.draw(tile);          
        window.display();
    }

    return 0;
}
