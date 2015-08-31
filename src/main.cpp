/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin // schking
 */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>       // std::cout
#include <thread>         // std::thread

#include "../include/player.hpp"
#include "../include/music.hpp"
#include "../include/AnimatedSprite.hpp"



// **************************************************************************************

int resWidth = 1920;
int resHeight = 1080;

// ************************************************************************************** 

int main()
{
	sf::Vector2i screenDimensions(resWidth,resHeight);

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

    Player player;

	sf::Texture backTexture;
	if (!backTexture.loadFromFile("img/back2.png"))
 		std::cout<<"Error loading back2.png";
 	backTexture.setSmooth(true);

    // set up AnimatedSprite
    AnimatedSprite animatedSprite(sf::seconds(0.1), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));
    animatedSprite.setOrigin(50,50);

    sf::Clock frameClock;

    bool noKeyWasPressed = true;
    char pressedKey='L';
    char lastPressedKey='L';

 	backTexture.setRepeated(true);
 	sf::Sprite backSprite;

 	backSprite.setTextureRect(sf::IntRect(0, 0, 5*resWidth, resHeight));

 	backSprite.setTexture(backTexture);


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

        	/*case sf::Event::KeyPressed:
        		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        				blblblSound.play();*/
        	}
        }
        sf::Time frameTime = frameClock.restart();

		
        window.setView(view);

		if(player.position->y<resHeight-40)
			player.speed->y += 10;
		else
			player.speed->y = 0;
/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player.currentAnimation = player.walkingAnimationUp;

			if(player.position->y>0)
				player.speed->y -= (player.speed->y>-5000)*10;
			else
				player.speed->y = 0;

			pressedKey='U';
			noKeyWasPressed = false;
		}
*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player.currentAnimation = player.walkingAnimationDown;

			if(player.position->y<resHeight-40)
				player.speed->y += (player.speed->y<5000)*10;
			else
				player.speed->y = 0;

			pressedKey='D';
			noKeyWasPressed = false;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.currentAnimation = player.walkingAnimationLeft;

			if(player.position->x>0)
				player.speed->x -= (player.speed->x>-5000)*10;

			pressedKey='L';
			noKeyWasPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.currentAnimation = player.walkingAnimationRight;

			if(player.position->x<5*resWidth)
				player.speed->x += (player.speed->x<5000)*10;

			pressedKey='R';
			noKeyWasPressed = false;
		}

		if (pressedKey!=lastPressedKey)
		{
			player.speed->x = 0;
			player.speed->y = 0;
		}

		if (noKeyWasPressed)
		{
			player.currentAnimation = player.idleAnimation;
			if (player.position->y>resHeight-50)
				player.speed->x += -(player.speed->x>0)*20 + (player.speed->x<0)*20;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if(player.position->y>0)
				player.speed->y = -1000;
		}

		if(!(0<player.position->x<5*resWidth))
			player.speed->x = 0;


		player.position->x=animatedSprite.getPosition().x;
		player.position->y=animatedSprite.getPosition().y;



		lastPressedKey=pressedKey;
    	noKeyWasPressed = true;

        animatedSprite.play(*player.currentAnimation);
        animatedSprite.move(*player.speed * frameTime.asSeconds());

        // update AnimatedSprite
        animatedSprite.update(frameTime);


        // draw
        window.clear();
        window.draw(backSprite);
        window.draw(animatedSprite);
        window.display();
    }




	
}
