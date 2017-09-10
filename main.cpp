#include <iostream>
#include "Source.h"
int main()
{
	DinoGame game; 
	sf::RenderWindow window(sf::VideoMode(640, 480), "DinoRun");
	sf::Clock clk;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		game.Update(clk.restart());
		game.Intersects();
		window.clear(sf::Color::White);
		game.Draw(window);
		window.display();
	}
	return 0;
}