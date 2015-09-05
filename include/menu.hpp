/*
 * game.hpp
 *
 *  Created on: Sep 4, 2015
 *      Author: Tristan
 */

#ifndef INCLUDE_MENU_HPP_
#define INCLUDE_MENU_HPP_


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <thread>

#include "../include/player.hpp"
#include "../include/music.hpp"
#include "../include/AnimatedSprite.hpp"

#include "../include/cscreen.hpp"


class menu : public cScreen
{
    public:

    	menu();
    	virtual int Run(sf::RenderWindow &window);
};



#endif /* INCLUDE_MENU_HPP_ */
