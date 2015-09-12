
#ifndef INCLUDE_SPLASH_HPP_
#define INCLUDE_SPLASH_HPP_


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <thread>

#include "../include/music.hpp"
#include "../include/AnimatedSprite.hpp"

#include "../include/cscreen.hpp"

class splashScreen : public cScreen
{
	public:
		splashScreen();
		virtual int Run(sf::RenderWindow &window);

    	virtual ~splashScreen();
};



#endif /* INCLUDE_SPLASH_HPP_ */
