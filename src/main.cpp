/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin
 */

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>       // std::cout
#include <thread>         // std::thread

// **************************************************************************************

int resWidth;
int resHeight;

// ************************************************************************************** 


void keyboardEvents()
{

}

int main()
{

	std::cout<<"Resolution horizontale : ";
	std::cin>>resWidth;
	std::cout<<"Resolution verticale : ";
	std::cin>>resHeight;


	sf::RenderWindow window(sf::VideoMode(resWidth, resHeight),"TestWindow");

	sf::Clock clock;
	sf::Time millis = clock.getElapsedTime();
	sf::Time rotationTemp = clock.getElapsedTime();

	sf::View view(sf::Vector2f(resWidth/2, resHeight/2), sf::Vector2f(resWidth, resHeight));
	window.setView(view);

	view.setCenter(resWidth/2, resHeight/2);

	sf::Texture backTexture;
	if (!backTexture.loadFromFile("img/back2.png"))
 		std::cout<<"Error loading back2.png";

	sf::Texture catTexture;
 	if (!catTexture.loadFromFile("img/cat.png"))
 		std::cout<<"Error loading cat.png";


 	catTexture.setSmooth(true);
 	backTexture.setSmooth(true);

 	backTexture.setRepeated(true);

 	sf::Sprite backSprite;
 	sf::Sprite catSprite;

 	backSprite.setTextureRect(sf::IntRect(0, 0, 5*resWidth, resHeight));

 	backSprite.setTexture(backTexture);
 	catSprite.setTexture(catTexture);

 	catSprite.move(resWidth/2, resHeight/2);
 	catSprite.setOrigin(50,64);

 	unsigned int angle=0;


	while (window.isOpen())
	{
		sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		
		window.clear();
		window.draw(backSprite);
		window.draw(catSprite);
		window.display();

		millis = clock.getElapsedTime();


		if (millis.asMilliseconds()>=1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if(catSprite.getPosition().x>0)
					catSprite.move(-10,0);
				
				if(catSprite.getPosition().x>960 && catSprite.getPosition().x<8640)
					view.move(-10, 0);
				
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if(catSprite.getPosition().x<5*resWidth)
					catSprite.move(10,0);

				if(catSprite.getPosition().x>960 && catSprite.getPosition().x<8640)
					view.move(10, 0);
				
		}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{	
				if(catSprite.getPosition().y>0)
					catSprite.move(0,-10);
				
				if(catSprite.getPosition().y>resHeight/4 && catSprite.getPosition().y<3*resHeight/4)
					view.move(0, -10);
				
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if(catSprite.getPosition().y<resHeight)
					catSprite.move(0,10);
				
				if(catSprite.getPosition().y>resHeight/4 && catSprite.getPosition().y<3*resHeight/4)
				{
					view.move(0, 10);
				}
				
			}

			window.setView(view);


		}

		clock.restart();
	}
}
