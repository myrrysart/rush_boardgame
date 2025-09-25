#include <SFML/Graphics.hpp>
#include <iostream>
#include <utility>


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

void handleClick(sf::Event::MouseButtonEvent click)
{
	std::cout << "screen : (" << click.x << "," <<  click.y << ")" << std::endl;
	std::pair<int, int> coords = screenToBoard({click.x, click.y});
	std::cout << "coords : (" << coords.first << "," <<  coords.second << ")" << std::endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 400), "Hivetorini!");
    sf::Texture board;
	if (!board.loadFromFile("assets/map.png"))
		std::cout << "Error" << std::endl;
	sf::Sprite	basemap;
	basemap.setTexture(board);
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
						handleClick(event.mouseButton);
					break;
				
				default:
					break;
			}
        }

        window.clear();
        window.draw(basemap);
        window.display();
    }

    return 0;
}
