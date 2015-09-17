/*
 * player.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: robin
 */

#include "../include/player.hpp"

Player::Player()
{
}

void Player::play(bool smallScreen, int player)
{
	this->player = player; // 1:ball, 2:man
	
	// Set screen size
	if (smallScreen)
	{
		resWidth = 1366;
		resHeight = 768;
	}
	else
	{
		resWidth = 1920;
		resHeight = 1080;
	}	
	
	// run corresponding player 
	if (player==1)
		playBall();
	if (player==2)
		playMan();
}

void Player::playBall()
{
	 setIdleAnimation("blue");
	 
 	 walkingAnimationDown = new Animation;
    walkingAnimationDown->setSpriteSheet(*playerTexture);
    walkingAnimationDown->addFrame(sf::IntRect(300, 0, 100, 100));
    walkingAnimationDown->addFrame(sf::IntRect(400, 0, 100, 100));
    walkingAnimationDown->addFrame(sf::IntRect(500, 0, 100, 100));

    walkingAnimationLeft = new Animation;
    walkingAnimationLeft->setSpriteSheet(*playerTexture);
    walkingAnimationLeft->addFrame(sf::IntRect(200, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(100, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(0, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(100, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(200, 0, 100, 100));

    walkingAnimationRight = new Animation;
    walkingAnimationRight->setSpriteSheet(*playerTexture);
    walkingAnimationRight->addFrame(sf::IntRect(600, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(700, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(800, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(700, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(600, 0, 100, 100));

    walkingAnimationUp = new Animation;
    walkingAnimationUp->setSpriteSheet(*playerTexture);
    walkingAnimationUp->addFrame(sf::IntRect(300, 0, 100, 100));
    walkingAnimationUp->addFrame(sf::IntRect(400, 0, 100, 100));
    walkingAnimationUp->addFrame(sf::IntRect(500, 0, 100, 100));

    currentAnimation = new Animation;
    currentAnimation = this->walkingAnimationDown;

    position = new sf::Vector2f;
    speed = new sf::Vector2f;
    acceleration = new sf::Vector2f;
    this->position->x=resWidth/2;
    this->position->y=resHeight/2;
    this->speed->x=0;
    this->speed->y=0;
}

void Player::setIdleAnimation(string color)
{
	this->color = color;
	if (player==1)
	{
		// Set player texture
		playerTexture = new sf::Texture;
		if (color=="blue")
 			if (!playerTexture->loadFromFile("img/player.png"))
 				std::cout<<"Error loading player.png";
 		if (color=="purple")
 			if (!playerTexture->loadFromFile("img/playerPurple.png"))
 				std::cout<<"Error loading playerPurple.png";
 		if (color=="red")
 			if (!playerTexture->loadFromFile("img/playerRed.png"))
 				std::cout<<"Error loading playerRed.png";
 		playerTexture->setSmooth(true);

 		// Define player animations
 		idleAnimation = new Animation;
 		idleAnimation->setSpriteSheet(*playerTexture);
 		for (int i=0;i<9;i++)
 		 	idleAnimation->addFrame(sf::IntRect(100*(i%3+3),100*(i/3),100,100));
 		for (int i=7;i>=0;i--)
 			idleAnimation->addFrame(sf::IntRect(100*(i%3+3),100*(i/3),100,100));
 	}
}

void Player::playMan()
{
// Set player texture
	playerTexture = new sf::Texture;
 	if (!playerTexture->loadFromFile("img/player2.png"))
 		std::cout<<"Error loading player2.png";
 	playerTexture->setSmooth(true);

 	// Define player animations
 	idleAnimation = new Animation;
 	idleAnimation->setSpriteSheet(*playerTexture);
 	for (int i=0;i<9;i++)
 	 	idleAnimation->addFrame(sf::IntRect(100*(i%3+3),100*(i/3),100,100));
 	for (int i=7;i>=0;i--)
 		idleAnimation->addFrame(sf::IntRect(100*(i%3+3),100*(i/3),100,100));

 	 walkingAnimationDown = new Animation;
    walkingAnimationDown->setSpriteSheet(*playerTexture);
    walkingAnimationDown->addFrame(sf::IntRect(300, 0, 100, 100));
    walkingAnimationDown->addFrame(sf::IntRect(400, 0, 100, 100));
    walkingAnimationDown->addFrame(sf::IntRect(500, 0, 100, 100));

    walkingAnimationLeft = new Animation;
    walkingAnimationLeft->setSpriteSheet(*playerTexture);
    walkingAnimationLeft->addFrame(sf::IntRect(200, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(100, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(0, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(100, 0, 100, 100));
    walkingAnimationLeft->addFrame(sf::IntRect(200, 0, 100, 100));

    walkingAnimationRight = new Animation;
    walkingAnimationRight->setSpriteSheet(*playerTexture);
    walkingAnimationRight->addFrame(sf::IntRect(600, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(700, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(800, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(700, 0, 100, 100));
    walkingAnimationRight->addFrame(sf::IntRect(600, 0, 100, 100));

    walkingAnimationUp = new Animation;
    walkingAnimationUp->setSpriteSheet(*playerTexture);
    walkingAnimationUp->addFrame(sf::IntRect(300, 0, 100, 100));
    walkingAnimationUp->addFrame(sf::IntRect(400, 0, 100, 100));
    walkingAnimationUp->addFrame(sf::IntRect(500, 0, 100, 100));

    currentAnimation = new Animation;
    currentAnimation = this->walkingAnimationDown;

    position = new sf::Vector2f;
    speed = new sf::Vector2f;
    acceleration = new sf::Vector2f;
    this->position->x=resWidth/2;
    this->position->y=resHeight/2;
    this->speed->x=0;
    this->speed->y=0;
}

sf::Vector2f Player::getPosition()
{
	return *this->position;
}

void Player::move(bool bd, bool bl, bool br, bool bu)
{
	bool noKeyWasPressed = true;

	//if(this->position->y<resHeight) 
	//	this->speed->y += 30;
	
	// GRAVITY
	if(this->position->y<resHeight-32)
		this->speed->y += 10;
		
	// KEYBOARD MOVEMENTS
	
	// Down		
	if (bd)
	{
		this->currentAnimation = this->walkingAnimationDown;
		this->speed->y += (this->speed->y<5000)*20;
		//pressedKey='D';
		noKeyWasPressed = false;
		// TODO blblblSound.play();
	}
	// Left
	if (bl)
	{
		this->currentAnimation = this->walkingAnimationLeft;

		if(this->position->x>0)
			this->speed->x -= (this->speed->x>-5000)*20;

			noKeyWasPressed = false;
	}
	// Right
	if (br)
	{
		this->currentAnimation = this->walkingAnimationRight;

		if(this->position->x<5*resWidth)
			this->speed->x += (this->speed->x<5000)*20;

		noKeyWasPressed = false;
	}
	
	// decrease horizontal speed in the top of the screen 
	if (noKeyWasPressed)
	{
		this->currentAnimation = this->idleAnimation;
		if (this->position->y>resHeight-50)
			this->speed->x += -(this->speed->x>0)*20 + (this->speed->x<0)*20;
	}
	
	// jump
	if (bu) 
	{
		if(this->position->y>0)
			this->speed->y = -800;
	}
	
	// REBONDS (TODO : translate)
	bool rebond = false;
		// ground
	if (this->position->y>resHeight-32 && this->speed->y > 0)
	{
			this->speed->y/=-2;
			rebond = true;
	}
		// stop mini-rebonds on the ground
	if ( this->position->y>resHeight-33) 
		rbCount++;
	else
		rbCount = 0;
	if (rbCount>10 && !bu)
		this->speed->y=0;
	
		// left side
	if (this->position->x<32 && this->speed->x < 0)
	{
			this->speed->x/=-1;
			rebond = true;
	}
		// right side
	if (this->position->x>resWidth-32 && this->speed->x > 0)
	{
			this->speed->x/=-1;
			rebond = true;
	}
	
	// supposed to stop the ball at the border of the screen ? 
	if(!(0<this->position->x<1*resWidth))
		this->speed->x = 0;
}
