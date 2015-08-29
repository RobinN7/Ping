/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin
 */

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>       // std::cout
#include <thread>         // std::thread

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"TestWindow");

	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();

	sf::Texture catTexture;
 	if (!catTexture.loadFromFile("img/cat.png"))
	{
 		std::cout<<"Error loading cat.png";
	}
 	catTexture.setSmooth(true);
 	sf::Sprite catSprite;
 	catSprite.setTexture(catTexture);
 	catSprite.move(50,64);
 	catSprite.setOrigin(50,64);

 	unsigned int angle=0;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(catSprite);
		window.display();

		elapsed = clock.getElapsedTime();
		if (elapsed.asMilliseconds()>=20)
		{
			catSprite.move(1,1);
			catSprite.rotate(sqrt(angle++));
			clock.restart();
		}
	}
}
