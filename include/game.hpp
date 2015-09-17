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

using namespace std; 



class Game : public cScreen
{
    public:

    	Game(bool smallScreen);
    	virtual int Run(sf::RenderWindow &window);
    	string timeToString(float sec);
    	void player(Player player, bool bd, bool bl, bool br, bool bu); 

    	virtual ~Game();
    	
    private:
    	bool smallScreen;
    	int resWidth;
		int resHeight;
		
		// sounds
		sf::Sound blblblSound;
		sf::Sound jumpSound;
		
		// for firstplayer() and secondplayer() :
			// players
		Player player1;
		Player player2;
			// screen, background
		sf::Vector2i screenDimensions;
		sf::View view;
		sf::Texture backTexture;
			// AnimatedSprites
		AnimatedSprite animatedSprite1;
		AnimatedSprite animatedSprite2;
			// keyboard
		bool noKeyWasPressed;
/*		char pressedKey1;
		char lastPressedKey1;
		char pressedKey2;
		char lastPressedKey2;
*/
			// distance between balls (square of the real distance)
		int distance;
		int oldDistance; 
		
};



#endif /* INCLUDE_GAME_HPP_ */
