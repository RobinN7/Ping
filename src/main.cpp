/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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

	sf::Music music;
	if (!music.openFromFile("sound/music.wav"))
 		std::cout<<"Error opening music.wav";
	music.setLoop(true);
	music.play();

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound/blblbl.wav"))
 		std::cout<<"Error opening music.wav";
    sf::Sound blblblSound;
    blblblSound.setBuffer(buffer);

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
        	switch (event.type)
        	{
        	case sf::Event::Closed:
                window.close();
                break;
        	case sf::Event::KeyPressed:
        		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        			blblblSound.play();
        	}
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
	}
}
