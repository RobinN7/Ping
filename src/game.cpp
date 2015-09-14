/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin // schking
 */

#include "../include/game.hpp"


Game::Game()
{
	
}

Game::~Game()
{

}

int Game::Run(sf::RenderWindow &window)
{

	bool Running = true;

	int resWidth = 1920;
	int resHeight = 1080;

	sf::Vector2i screenDimensions(resWidth,resHeight);

	sf::Clock clock;
	sf::Time millis = clock.getElapsedTime();

	GameMusic music(2);

    sf::SoundBuffer buffer1;
    sf::SoundBuffer buffer2;

    if (!buffer1.loadFromFile("sound/blblblSound.wav"))
 		std::cout<<"Error opening blblblSound.wav";
    sf::Sound blblblSound;
    blblblSound.setBuffer(buffer1);

    if (!buffer2.loadFromFile("sound/jumpSound.wav"))
 		std::cout<<"Error opening jumpSound.wav";
    sf::Sound jumpSound;
    jumpSound.setVolume(40.f);
    jumpSound.setBuffer(buffer2);

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


	while (Running)
	{
		sf::Event event;

        while (window.pollEvent(event))
        {
        	switch (event.type)
        	{
        	
        	case sf::Event::Closed:
                return(-1);
                break;

        	case sf::Event::KeyPressed:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						return(1);
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
						jumpSound.play();
					break;
        	}
        }
        
        sf::Time frameTime = frameClock.restart();

		
        window.setView(view);

        player.speed->y += 30;
/*
		if(player.position->y<resHeight-40)
			player.speed->y += 10;
		else
			player.speed->y = 0;
*/
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
			player.speed->y += (player.speed->y<5000)*20;
			pressedKey='D';
			noKeyWasPressed = false;
			blblblSound.play();
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player.currentAnimation = player.walkingAnimationLeft;

			if(player.position->x>0)
				player.speed->x -= (player.speed->x>-5000)*20;
			pressedKey='L';
			noKeyWasPressed = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player.currentAnimation = player.walkingAnimationRight;

			if(player.position->x<5*resWidth)
				player.speed->x += (player.speed->x<5000)*20;

			pressedKey='R';
			noKeyWasPressed = false;
		}
/*
		if (pressedKey!=lastPressedKey && (pressedKey=='L' || pressedKey=='R'))
			player.speed->x = 0;
*/
		if (noKeyWasPressed)
		{
			player.currentAnimation = player.idleAnimation;
			if (player.position->y>resHeight-50)
				player.speed->x += -(player.speed->x>0)*20 + (player.speed->x<0)*20;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			if(player.position->y>0)
				player.speed->y = -800;


		lastPressedKey=pressedKey;
    	noKeyWasPressed = true;

        animatedSprite.play(*player.currentAnimation);
        animatedSprite.move(*player.speed * frameTime.asSeconds());

		player.position->x=animatedSprite.getPosition().x;
		player.position->y=animatedSprite.getPosition().y;

		while ((player.position->x<32) || (player.position->x>resWidth-32) || (player.position->y>resHeight-32))
		{
			animatedSprite.move(-*player.speed * frameTime.asSeconds());
			if ((player.position->x<32) || (player.position->x>resWidth-32)) player.speed->x/=2;
			if (player.position->y>resHeight-32) player.speed->y/=2;
			animatedSprite.move(*player.speed * frameTime.asSeconds());

			player.position->x=animatedSprite.getPosition().x;
			player.position->y=animatedSprite.getPosition().y;
		}


        // update AnimatedSprite
        animatedSprite.update(frameTime);

        // draw
        window.clear();
        window.draw(backSprite);
        window.draw(animatedSprite);
        window.display();
    }
}
