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

using namespace std; //to put just "cout" instead of "std::cout" 



class Menu : public cScreen
{
    public:
    	Menu(bool smallScreen);
    	virtual int Run(sf::RenderWindow &window);

    	virtual ~Menu();
    	
    private:
    	bool smallScreen;
    	int resWidth;
		int resHeight;
};



#endif /* INCLUDE_MENU_HPP_ */
