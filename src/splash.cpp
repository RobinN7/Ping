
#include "../include/splash.hpp"

splashScreen::splashScreen()
{
}

splashScreen::~splashScreen()
{
}

int splashScreen::Run(sf::RenderWindow &window)
{

	bool Running = true;

	int resWidth = 1920;
	int resHeight = 1080;

	GameMusic music(0);

	sf::Texture backTexture;
	if (!backTexture.loadFromFile("img/ping.png"))
 		std::cout<<"Error loading ping.png";
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
