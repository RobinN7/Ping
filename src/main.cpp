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

	/*std::cout<<"Resolution horizontale : ";
	std::cin>>resWidth;
	std::cin>>resHeight;*/

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

    float speed = 200.f;
    bool noKeyWasPressed = true;


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

		
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            player.currentAnimation = player.walkingAnimationUp;
            
            if(animatedSprite.getPosition().y>0)
            	movement.y -= speed;
	
			if(animatedSprite.getPosition().y>resHeight/4 && animatedSprite.getPosition().y<3*resHeight/4)
				view.move(0, -1);

            noKeyWasPressed = false;
        }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            player.currentAnimation = player.walkingAnimationDown;

            if(animatedSprite.getPosition().y<resHeight)
            	movement.y += speed;
	
			if(animatedSprite.getPosition().y>resHeight/4 && animatedSprite.getPosition().y<3*resHeight/4)
				view.move(0, 1);

            noKeyWasPressed = false;
        }
    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
        	player.currentAnimation = player.walkingAnimationLeft;

            if(animatedSprite.getPosition().x>0)
            	movement.x -= speed;
	
			if(animatedSprite.getPosition().x>resWidth/2 && animatedSprite.getPosition().x<9*resWidth/2)
				view.move(-1, 0);

            noKeyWasPressed = false;
        }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
        	player.currentAnimation = player.walkingAnimationRight;

            if(animatedSprite.getPosition().x<5*resWidth)
            	movement.x += speed;
	
			if(animatedSprite.getPosition().x>resWidth/2 && animatedSprite.getPosition().x<9*resWidth/2)
				view.move(1, 0);

            noKeyWasPressed = false;
        }

        if (noKeyWasPressed)
        {
        	player.currentAnimation = player.idleAnimation;
        }


        noKeyWasPressed = true;

        window.setView(view);

        animatedSprite.play(*player.currentAnimation);
        animatedSprite.move(movement *frameTime.asSeconds());


        // update AnimatedSprite
        animatedSprite.update(frameTime);


        // draw
        window.clear();
        window.draw(backSprite);
        window.draw(animatedSprite);
        window.display();
    }




	
}
