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

#include "../include/music.hpp"

// **************************************************************************************



// ************************************************************************************** 





int resWidth=1920;
int resHeight=1080;

void keyboardEvents()
{

}

int main()
{
	sf::RenderWindow window(sf::VideoMode(resWidth, resHeight),"Ping");

	sf::Clock clock;
	sf::Time millis = clock.getElapsedTime();

	GameMusic music;

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound/blblbl.wav"))
 		std::cout<<"Error opening music.wav";
    sf::Sound blblblSound;
    blblblSound.setBuffer(buffer);

	sf::View view(sf::Vector2f(resWidth/2, resHeight/2), sf::Vector2f(resWidth, resHeight));
	window.setView(view);

	view.setCenter(resWidth/2, resHeight/2);

	sf::Texture backTexture;
	if (!backTexture.loadFromFile("img/back2.png"))
 		std::cout<<"Error loading back2.png";

	sf::Texture playerTexture;
 	if (!playerTexture.loadFromFile("img/player.png"))
 		std::cout<<"Error loading player.png";


 	playerTexture.setSmooth(true);
 	backTexture.setSmooth(true);

 	backTexture.setRepeated(true);

 	sf::Sprite backSprite;
 	sf::Sprite playerSprite;

 	backSprite.setTextureRect(sf::IntRect(0, 0, 5*resWidth, resHeight));

 	backSprite.setTexture(backTexture);
 	playerSprite.setTexture(playerTexture);

 	playerSprite.move(resWidth/2, resHeight/2);
 	playerSprite.setOrigin(50,64);

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
		window.draw(playerSprite);
		window.display();

		millis = clock.getElapsedTime();

		if (millis.asMilliseconds()>=10)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if(playerSprite.getPosition().x>0)
					playerSprite.move(-10,0);


				if(playerSprite.getPosition().x>resWidth/2 && playerSprite.getPosition().x<8640)
					view.move(-10, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if(playerSprite.getPosition().x<5*resWidth)
					playerSprite.move(10,0);

				if(playerSprite.getPosition().x>960 && playerSprite.getPosition().x<8640)
					view.move(10, 0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{	
				if(playerSprite.getPosition().y>0)
					playerSprite.move(0,-10);
				
				if(playerSprite.getPosition().y>resHeight/4 && playerSprite.getPosition().y<3*resHeight/4)
					view.move(0, -10);
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if(playerSprite.getPosition().y<resHeight)
					playerSprite.move(0,10);
				
				if(playerSprite.getPosition().y>resHeight/4 && playerSprite.getPosition().y<3*resHeight/4)
				{
					view.move(0, 10);
				}
				
			}
			clock.restart();

			window.setView(view);


		}



	}
}
