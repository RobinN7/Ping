/*
 * game.hpp
 *
 *  Created on: Sep 4, 2015
 *      Author: Tristan
 */

#ifndef INCLUDE_GAME_HPP_
#define INCLUDE_GAME_HPP_


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <thread>

#include "../include/player.hpp"
#include "../include/music.hpp"
#include "../include/AnimatedSprite.hpp"

#include "../include/cscreen.hpp"


class Game : public cScreen
{
    public:

    	Game();
    	virtual int Run(sf::RenderWindow &window);

    	virtual ~Game();
};



#endif /* INCLUDE_GAME_HPP_ */
