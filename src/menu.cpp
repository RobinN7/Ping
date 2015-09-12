


#include "../include/menu.hpp"

Menu::Menu()
{
	
}

Menu::~Menu()
{

}

int Menu::Run(sf::RenderWindow &window)
{

	bool Running = true;

	int resWidth = 1920;
	int resHeight = 1080;

	GameMusic music(1);

	sf::Texture backTexture;
	if (!backTexture.loadFromFile("img/menu.png"))
 		std::cout<<"Error loading menu.png";
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
                	backSprite.setTextureRect(sf::IntRect(1920, 0, resWidth, resHeight));
 					backSprite.setTexture(backTexture);
 					selection = true;
                }
            	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                	backSprite.setTextureRect(sf::IntRect(3840, 0, resWidth, resHeight));
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
