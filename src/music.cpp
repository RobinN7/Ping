/*
 * music.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: robin
 */

#include "../include/music.hpp"

GameMusic::GameMusic() : sf::Music()
{
	if (!this->openFromFile("sound/music.wav"))
 		std::cout<<"Error opening music.wav";
	this->setLoop(true);
	this->play();
}


