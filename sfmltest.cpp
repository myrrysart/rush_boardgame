#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>
#include "TextBox.hpp"
#include "Santorini.hpp"

//return the screen coordinates of the left corner of the selected tile
//add an offset based on bulding height?
std::pair<int, int> boardToScreen(std::pair<int, int> boardPos)
{
	std::pair<int, int> origin = {37, 158};
	int	width = 116;
	int height = 58;
	float screenX = origin.first + width * (boardPos.first + boardPos.second)/ 2 ;
	float screenY = origin.second - height * (boardPos.second - boardPos.first)/ 2;
	return {static_cast<int>(screenX), static_cast<int>(screenY)};
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

void handleClick(sf::Event::MouseButtonEvent click, Santorini &game)
{
	std::pair<int, int> coords = screenToBoard({click.x, click.y});
	int player;
	if (game.gameState < PLAYER2_INIT_WORKER1)
		player = PLAYER1;
	else
		player = PLAYER2;
	if (!Santorini::isValidInput(coords, player))
		std::cout << "click out of bounds" << std::endl;
		return;
	switch (game.gameState)
	{
		case PLAYER1_INIT_WORKER1:
			if (game.placeWorker(coords, player))
				game.gameState++;
			break;
		case PLAYER1_INIT_WORKER2:
			if (game.placeWorker(coords, player))
				game.gameState = PLAYER2_INIT_WORKER1;
			break;
		case PLAYER1_CHOOSE_WORKER:
		case PLAYER2_CHOOSE_WORKER:
			if (game.chooseWorker(coords, player))
				game.gameState++;
			break;
		case PLAYER1_MOVE_WORKER:
		case PLAYER2_MOVE_WORKER:
			if (game.moveWorker(coords, player)
				game.gameState++;
			break;
		case PLAYER1_BUILD:
		case PLAYER2_BUILD:
			if (game.build(coords, player))
				game.gameState = static_cast<e_state>(game.gameState + 3);
			break;
		case PLAYER2_INIT_WORKER1:
			if (game.placeWorker(coords, player))
				game.gameState++;
			break;
		case PLAYER2_INIT_WORKER2:
			if (game.placeWorker(coords, player))
				game.gameState = PLAYER1_CHOOSE_WORKER;
			break;
		default:
			break;
	}

	std::cout << "screen : (" << click.x << "," <<  click.y << ")" << std::endl;
	std::pair<int, int> coords = screenToBoard({click.x, click.y});
	std::cout << "coords : (" << coords.first << "," <<  coords.second << ")" << std::endl;
	std::pair<int, int> drawing = boardToScreen({coords.first, coords.second});
	std::cout << "draw coords : (" << drawing.first << "," <<  drawing.second << ")" << std::endl;
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

	//dummy values for textbox
	int turn = 0;
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
						handleClick(event.mouseButton, mySant);
					break;
				
				default:
					break;
			}
        }
		if (game.gameState < PLAYER2_INIT_WORKER1)
			player = PLAYER1;
		else
			player = PLAYER2;
		textBox.setValues(player, turn, mySant.pieces);
        window.clear();
	    window.draw(basemap);
		textBox.draw(window);
        window.display();
    }

    return 0;
}
