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

class Player
{
    public:

		Player();

		sf::Texture *playerTexture;

		Animation *idleAnimation;
	    Animation *walkingAnimationDown;
	    Animation *walkingAnimationLeft;
	    Animation *walkingAnimationRight;
	    Animation *walkingAnimationUp;

	    Animation *currentAnimation;

};


#endif /* INCLUDE_PLAYER_HPP_ */
