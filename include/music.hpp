/*
 * music.hpp
 *
 *  Created on: Aug 29, 2015
 *      Author: robin
 */

#ifndef INCLUDE_MUSIC_HPP_
#define INCLUDE_MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <iostream>       // std::cout

class GameMusic : public sf::Music
{
    public:
    GameMusic(unsigned char);
};



#endif /* INCLUDE_MUSIC_HPP_ */
