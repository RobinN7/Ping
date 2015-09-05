/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin // schking
 */

#include "../include/game.hpp"
#include "../include/splash.hpp"
#include "../include/menu.hpp"

 #include "../include/screens.hpp"

int main()
{
	int resWidth = 1920;
	int resHeight = 1080;

	//Applications variables
    std::vector<cScreen*> Screens;
    int screen = 0;

    //Window creation
    sf::Vector2i screenDimensions(resWidth,resHeight);
	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y),"Ping");

    //Mouse cursor no more visible
    window.setMouseCursorVisible(false);
    window.setFramerateLimit(60);

    //Screens preparations
    splashScreen splash1;
    Screens.push_back(&splash1);
    Menu menu1;
    Screens.push_back(&menu1);
    Game Jeu1;
    Screens.push_back(&Jeu1);

    //Main loop
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(window);
    }

    return EXIT_SUCCESS;
}
