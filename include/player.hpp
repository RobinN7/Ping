/*
 * player.hpp
 *
 *  Created on: Aug 30, 2015
 *      Author: robin
 */

#ifndef INCLUDE_PLAYER_HPP_
#define INCLUDE_PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>       // std::cout
#include "../include/AnimatedSprite.hpp"

using namespace std;

class Player
{
    public:

		Player();
		void play(bool smallScreen, int player);
			// int player : 1 for the ball, 2 for the boy
		void playBall();
		void playMan();
		void move(bool bd, bool bl, bool br, bool bu);
			// current color
		string color;

		sf::Texture *playerTexture;
		void setIdleAnimation(string color);

		Animation *idleAnimation;
	   Animation *walkingAnimationDown;
	   Animation *walkingAnimationLeft;
	   Animation *walkingAnimationRight;
	   Animation *walkingAnimationUp;

	   Animation *currentAnimation;

	   sf::Vector2f getPosition();
	   sf::Vector2f getSpeed();
	   sf::Vector2f getAcceleration();
	   sf::Vector2f setAcceleration(sf::Vector2f acc);

	   sf::Vector2f  *position;
	   sf::Vector2f  *speed;
	   sf::Vector2f  *acceleration;
	    
	private:
		int player;
    	int resWidth;
		int resHeight;
		
		int rbCount; // to stop endless rebonds on the ground in fonction move
};


#endif /* INCLUDE_PLAYER_HPP_ */
