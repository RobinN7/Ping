
#include "../include/splash.hpp"

splashScreen::splashScreen(bool smallScreen)
{
	this->smallScreen = smallScreen;
}

splashScreen::~splashScreen()
{
}

int splashScreen::Run(sf::RenderWindow &window)
{

	bool Running = true;

	int resWidth;
	int resHeight;
	if (smallScreen)
	{
		resWidth = 1366;
		resHeight = 768;
	}
	else
	{
		resWidth = 1920;
		resHeight = 1080;
	}

	GameMusic music(0);

	sf::Texture backTexture;
	if (smallScreen)
	{
		if (!backTexture.loadFromFile("img/ping_small.png"))
 			std::cout<<"Error loading ping_small.png";
	}
	else
	{
		if (!backTexture.loadFromFile("img/ping.png"))
 			std::cout<<"Error loading ping.png";
 	}
 	backTexture.setSmooth(true);
 	
 	sf::Sprite backSprite;
 	backSprite.setTextureRect(sf::IntRect(0, 0, resWidth, resHeight));
 	backSprite.setTexture(backTexture);


	while (Running)
	{
		sf::Event event;

        while (window.pollEvent(event))
        {
        	switch (event.type)
        	{
        	
        	case sf::Event::Closed:
                return (-1);
                break;

        	case sf::Event::KeyPressed:
        		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        				return 1;
        	}
        }
        
        // draw
        window.clear();
        window.draw(backSprite);
        window.display();
    }
}
