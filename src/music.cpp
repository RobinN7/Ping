/*
 * music.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: robin
 */

#include "../include/music.hpp"

GameMusic::GameMusic(unsigned char screenNumber) : sf::Music()
{
	switch (screenNumber)
	{
	case 0:
		if (!this->openFromFile("sound/splashMusic.wav"))
	 		std::cout<<"Error opening splashMusic.wav";
		break;
	case 1:
		if (!this->openFromFile("sound/menuMusic.wav"))
	 		std::cout<<"Error opening menuMusic.wav";
		break;
	case 2:
		if (!this->openFromFile("sound/gameMusic.wav"))
	 		std::cout<<"Error opening gameMusic.wav";
		break;
	}
	this->setLoop(true);
	this->play();
}


