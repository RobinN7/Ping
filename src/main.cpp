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


int resWidth=1920;
int resHeight=1080;


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


 	Animation idleAnimation;
 	idleAnimation.setSpriteSheet(playerTexture);
 	idleAnimation.addFrame(sf::IntRect(0,0,0,0));
 	idleAnimation.addFrame(sf::IntRect(0,0,0,0));
 	idleAnimation.addFrame(sf::IntRect(0,0,0,0));
 	idleAnimation.addFrame(sf::IntRect(0,0,0,0));

    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(playerTexture);
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
    walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(playerTexture);
    walkingAnimationLeft.addFrame(sf::IntRect(0, 0, 128, 128));
    walkingAnimationLeft.addFrame(sf::IntRect(128, 0, 128, 128));
    walkingAnimationLeft.addFrame(sf::IntRect(256, 0, 128, 128));
    walkingAnimationLeft.addFrame(sf::IntRect(384, 0, 128, 128));

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(playerTexture);
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
    walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(playerTexture);
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
    walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));

    Animation* currentAnimation = &walkingAnimationDown;

    // set up AnimatedSprite
    AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
    animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

    sf::Clock frameClock;

    float speed = 80.f;
    bool noKeyWasPressed = true;




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

        	/*case sf::Event::KeyPressed:
        		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
					sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        				blblblSound.play();*/
        	}
        }



        sf::Time frameTime = frameClock.restart();

		
		


		//millis = clock.getElapsedTime();



		/*if (millis.asMilliseconds()>=10)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if(catSprite.getPosition().x>0)
					catSprite.move(-10,0);
				
				if(catSprite.getPosition().x>resWidth/2 && catSprite.getPosition().x<8640)

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

				if(catSprite.getPosition().x<5*resWidth)
					catSprite.move(10,0);

				if(catSprite.getPosition().x>resWidth/2 && catSprite.getPosition().x<8640)
					view.move(10, 0);	
			}


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

			window.clear();
			window.draw(backSprite);
			window.draw(catSprite);
			window.display();

			clock.restart();

		}*/

		// if a key was pressed set the correct animation and move correctly
        sf::Vector2f movement(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            currentAnimation = &walkingAnimationUp;
            movement.y -= speed;
            noKeyWasPressed = false;
        }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            currentAnimation = &walkingAnimationDown;
            movement.y += speed;
            noKeyWasPressed = false;
        }
    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            currentAnimation = &walkingAnimationLeft;
            movement.x -= speed;
            noKeyWasPressed = false;
        }
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            currentAnimation = &walkingAnimationRight;
            movement.x += speed;
            noKeyWasPressed = false;
        }

        if (noKeyWasPressed)
        {
         	currentAnimation = &idleAnimation;  
        }

        noKeyWasPressed = true;

        animatedSprite.play(*currentAnimation);
        animatedSprite.move(movement * frameTime.asSeconds());


        // update AnimatedSprite
        animatedSprite.update(frameTime);


        // draw
        window.clear();
        window.draw(backSprite);
        window.draw(animatedSprite);
        window.display();
    }




	
}
