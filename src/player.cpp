/*
 * player.cpp
 *
 *  Created on: Aug 30, 2015
 *      Author: robin
 */

#include "../include/player.hpp"

Player::Player()
{
	// Set player texture
	playerTexture = new sf::Texture;
 	if (!playerTexture->loadFromFile("img/player.png"))
 		std::cout<<"Error loading player.png";
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
    this->position->x=1920/2;
    this->position->y=1080/2;
    this->speed->x=0;
    this->speed->y=0;
}

sf::Vector2f Player::getPosition()
{
	return *this->position;
}
