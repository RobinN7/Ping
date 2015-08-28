/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin
 */


#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200,200),"TestWindow");
	sf::CircleShape ball(50.f);
	ball.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(ball);
		window.display();

	}
}
