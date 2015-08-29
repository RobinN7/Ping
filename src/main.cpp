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


void keyboardEvents()
{

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,600),"TestWindow");

	sf::Clock clock;
	sf::Time millis = clock.getElapsedTime();
	sf::Time rotationTemp = clock.getElapsedTime();


	sf::Texture backTexture;
	if (!backTexture.loadFromFile("img/back.png"))
 		std::cout<<"Error loading back.png";

	sf::Texture catTexture;
 	if (!catTexture.loadFromFile("img/cat.png"))
 		std::cout<<"Error loading cat.png";


 	catTexture.setSmooth(true);
 	backTexture.setSmooth(true);

 	sf::Sprite backSprite;
 	sf::Sprite catSprite;

 	backSprite.setTexture(backTexture);
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
		window.draw(backSprite);
		window.draw(catSprite);
		window.display();

		millis = clock.getElapsedTime();
		if (millis.asMilliseconds()>=1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				catSprite.move(-1,0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				catSprite.move(1,0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				catSprite.move(0,-1);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				catSprite.move(0,1);
		}

		rotationTemp = clock.getElapsedTime();
		if (rotationTemp.asMilliseconds()>=50)
		{
			catSprite.rotate(sqrt(angle++));
			clock.restart();
		}
	}
}
