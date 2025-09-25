#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Textures.hpp"

int main(void)
{
	sf::RenderWindow win(sf::VideoMode(800, 600), "Rush");

	Textures tex("assets/spritesheet.png");
	sf::Sprite player1;
	sf::Sprite player2;
	player1.setTexture(tex.playerBlue);
	player2.setTexture(tex.playerGreen);

	std::vector<sf::Sprite> tiles;
	sf::Sprite level_1_tile;
	sf::Sprite level_2_tile;
	sf::Sprite level_3_tile;
	sf::Sprite blue_dome;
	sf::Sprite green_dome;
	level_1_tile.setTexture(tex.tileGrey);
	level_2_tile.setTexture(tex.tileGrey);
	level_3_tile.setTexture(tex.tileGreen);
	blue_dome.setTexture(tex.domeBlue);
	green_dome.setTexture(tex.domeGreen);

	level_2_tile.setPosition(sf::Vector2f(64.f, 64.f));
	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				win.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape))
				win.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mouse = static_cast<sf::Vector2f>(sf::Mouse::getPosition(win));
			tiles.push_back(level_1_tile);
			tiles.back().setPosition(mouse.x - 32.f, mouse.y - 32.f);
			//player1.setPosition(mouse.x - 32.f, mouse.y - 32.f);
		}

		win.clear();
		for (auto& tile : tiles)
			win.draw(tile);
		win.draw(player1);
		win.display();
	}
	return (0);
}
