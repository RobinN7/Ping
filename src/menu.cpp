


#include "../include/menu.hpp"

Menu::Menu(bool smallScreen)
{
	this->smallScreen = smallScreen;
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
}

Menu::~Menu()
{

}

int Menu::Run(sf::RenderWindow &window)
{

	bool Running = true;

	GameMusic music(1);

	sf::Texture backTexture;
	if (smallScreen)
	{
		if (!backTexture.loadFromFile("img/menu_small.png"))
 			std::cout<<"Error loading menu_small.png";
 	}
	else
	{
		if (!backTexture.loadFromFile("img/menu.png"))
 			std::cout<<"Error loading menu.png";
 	}
 	backTexture.setSmooth(true);

 	sf::Sprite backSprite;
 	backSprite.setTextureRect(sf::IntRect(0, 0, resWidth, resHeight));
 	backSprite.setTexture(backTexture);
 	
 	bool selection = true;

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
        		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                	// select the second picture of the row (play)
                	backSprite.setTextureRect(sf::IntRect(resWidth, 0, resWidth, resHeight));
 						backSprite.setTexture(backTexture);
 						selection = true;
                }
            	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                	// select the third picture of the row (quit)
                	backSprite.setTextureRect(sf::IntRect(resWidth*2, 0, resWidth, resHeight));
 						backSprite.setTexture(backTexture);
 						selection = false;
                }
            	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            	{
            		if (selection)
            			return 2;
            		else
            			return (-1);
            	}

        		break;

        	}
        }

        // draw
        window.clear();
        window.draw(backSprite);
        window.display();
    }



}
