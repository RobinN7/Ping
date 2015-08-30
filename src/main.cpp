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


 	Animation idleAnimation;
 	idleAnimation.setSpriteSheet(playerTexture);
 	idleAnimation.addFrame(sf::IntRect(300,0,100,100));
 	idleAnimation.addFrame(sf::IntRect(400,0,100,100));
 	idleAnimation.addFrame(sf::IntRect(500,0,100,100));
 	idleAnimation.addFrame(sf::IntRect(300,100,100,100));
 	idleAnimation.addFrame(sf::IntRect(400,100,100,100));
 	idleAnimation.addFrame(sf::IntRect(500,100,100,100));
 	idleAnimation.addFrame(sf::IntRect(300,200,100,100));
 	idleAnimation.addFrame(sf::IntRect(400,200,100,100));
 	idleAnimation.addFrame(sf::IntRect(500,200,100,100));
 	idleAnimation.addFrame(sf::IntRect(400,200,100,100));
 	idleAnimation.addFrame(sf::IntRect(300,200,100,100));
	idleAnimation.addFrame(sf::IntRect(500,100,100,100));
	idleAnimation.addFrame(sf::IntRect(400,100,100,100));
	idleAnimation.addFrame(sf::IntRect(300,100,100,100));
	idleAnimation.addFrame(sf::IntRect(500,0,100,100));
 	idleAnimation.addFrame(sf::IntRect(400,0,100,100));
 	idleAnimation.addFrame(sf::IntRect(300,0,100,100));

    Animation walkingAnimationDown;
    walkingAnimationDown.setSpriteSheet(playerTexture);
    walkingAnimationDown.addFrame(sf::IntRect(300, 0, 100, 100));
    walkingAnimationDown.addFrame(sf::IntRect(400, 0, 100, 100));

    Animation walkingAnimationLeft;
    walkingAnimationLeft.setSpriteSheet(playerTexture);
    walkingAnimationLeft.addFrame(sf::IntRect(200, 0, 100, 100));
    walkingAnimationLeft.addFrame(sf::IntRect(100, 0, 100, 100));
    walkingAnimationLeft.addFrame(sf::IntRect(0, 0, 100, 100));
    walkingAnimationLeft.addFrame(sf::IntRect(100, 0, 100, 100));
    walkingAnimationLeft.addFrame(sf::IntRect(200, 0, 100, 100));    

    Animation walkingAnimationRight;
    walkingAnimationRight.setSpriteSheet(playerTexture);
    walkingAnimationRight.addFrame(sf::IntRect(600, 0, 100, 100));
    walkingAnimationRight.addFrame(sf::IntRect(700, 0, 100, 100));
    walkingAnimationRight.addFrame(sf::IntRect(800, 0, 100, 100));
    walkingAnimationRight.addFrame(sf::IntRect(700, 0, 100, 100));
    walkingAnimationRight.addFrame(sf::IntRect(600, 0, 100, 100));

    Animation walkingAnimationUp;
    walkingAnimationUp.setSpriteSheet(playerTexture);
    walkingAnimationUp.addFrame(sf::IntRect(300, 0, 100, 100));
    walkingAnimationUp.addFrame(sf::IntRect(400, 0, 100, 100));


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
            currentAnimation = &walkingAnimationUp;
            
            if(movement.y>0)
            	movement.y -= speed;
				
			if(playerSprite.getPosition().y>resHeight/4 && playerSprite.getPosition().y<3*resHeight/4)
				view.move(0, -1);

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

        window.setView(view);

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
