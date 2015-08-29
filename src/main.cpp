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
	sf::RenderWindow window(sf::VideoMode(1920,1080),"TestWindow");

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

	sf::View view(sf::Vector2f(960, 540), sf::Vector2f(1920, 1080));
	window.setView(view);

	view.setCenter(960, 540);

	sf::Texture backTexture;
	if (!backTexture.loadFromFile("img/back2.png"))
 		std::cout<<"Error loading back2.png";

	sf::Texture catTexture;
 	if (!catTexture.loadFromFile("img/cat.png"))
 		std::cout<<"Error loading cat.png";


 	catTexture.setSmooth(true);
 	backTexture.setSmooth(true);

 	backTexture.setRepeated(true);

 	sf::Sprite backSprite;
 	sf::Sprite catSprite;

 	backSprite.setTextureRect(sf::IntRect(0, 0, 9600, 1080));

 	backSprite.setTexture(backTexture);
 	catSprite.setTexture(catTexture);

 	catSprite.move(960,540);
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
			{
				catSprite.move(-10,0);
				view.move(-10, 0);
				window.setView(view);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				catSprite.move(10,0);
				view.move(10, 0);
				window.setView(view);
		}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{	catSprite.move(0,-10);
				view.move(0, -10);
				window.setView(view);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				catSprite.move(0,10);
				view.move(0, 10);
				window.setView(view);
			}
		}
	}
}
