/*
* main.cpp
 *
 *  Created on: Aug 28, 2015
 *      Author: robin // schking
 */

#include "../include/game.hpp"


Game::Game(bool smallScreen)
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

Game::~Game()
{

}

int Game::Run(sf::RenderWindow &window)
{
	// INITIALISATION
		
	bool Running = true;

	// Screen
	screenDimensions = sf::Vector2i(resWidth,resHeight);
	view = sf::View(sf::Vector2f(resWidth/2, resHeight/2), sf::Vector2f(resWidth, resHeight));
	window.setView(view);
	view.setCenter(resWidth/2, resHeight/2);

	// Time
	sf::Clock clock;
	sf::Time sec;
	
	// To display clock and score
	int pts = 0;
	sf::Text time;
	sf::Text points;
	sf::Font font;
	font.loadFromFile("fonts/OpenSans-Regular.ttf");
	time.setString("time");
	time.setFont(font);
	time.setCharacterSize(65);
	time.setStyle(sf::Text::Bold);
	time.setColor(sf::Color::Blue);
	time.setPosition(resWidth-290, 90); 
	points.setString(to_string(pts));
	points.setFont(font);
	points.setCharacterSize(65);
	points.setStyle(sf::Text::Bold);
	points.setColor(sf::Color::Blue);
	points.setPosition(resWidth-360, 200); 

	// Music
	GameMusic music(2);

    sf::SoundBuffer buffer1;
    sf::SoundBuffer buffer2;

    if (!buffer1.loadFromFile("sound/blblblSound.wav"))
 		std::cout<<"Error opening blblblSound.wav";
    blblblSound.setBuffer(buffer1);

    if (!buffer2.loadFromFile("sound/jumpSound.wav"))
 		std::cout<<"Error opening jumpSound.wav";
    jumpSound.setVolume(40.f);
    jumpSound.setBuffer(buffer2);
	
	// Background
	if (smallScreen)
	{
		if (!backTexture.loadFromFile("img/back3_small.png"))
 			std::cout<<"Error loading back3_small.png"<<endl;
 	}
 	else
 	{
		if (!backTexture.loadFromFile("img/back3.png"))
 			std::cout<<"Error loading back3.png"<<endl;
 	}
 	backTexture.setSmooth(true);

	// two balls !!!! 
   player1.play(smallScreen,1);
   player2.play(smallScreen,1);

	// set up AnimatedSprite
	animatedSprite1 = AnimatedSprite(sf::seconds(0.1), true, false);
	animatedSprite1.setPosition(sf::Vector2f(screenDimensions / 2));
	animatedSprite1.setOrigin(50,50);
	// set up AnimatedSprite -- second player
	animatedSprite2 = AnimatedSprite(sf::seconds(0.1), true, false);
	animatedSprite2.setPosition(sf::Vector2f(screenDimensions / 2));
	animatedSprite2.setOrigin(50,50);
	// separate the balls
	animatedSprite1.move(-100,0);
	animatedSprite2.move(100,0);

	sf::Clock frameClock;

	// keyboard variables initialisation
	noKeyWasPressed = true;
/*	pressedKey1='L';
	lastPressedKey1='L';
	pressedKey2='L';
	lastPressedKey2='L';
*/

 	backTexture.setRepeated(true);
 	
 	sf::Sprite backSprite;
 	backSprite.setTextureRect(sf::IntRect(0, 0, 1*resWidth, resHeight));
 	backSprite.setTexture(backTexture);


	// PLAY LOOP (INFINITE !!)
	
	
	while (Running)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{	
        	case sf::Event::Closed:
                return(-1);
                break;

        	case sf::Event::KeyPressed:
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
							return (1);
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) 
						|| sf::Keyboard::isKeyPressed(sf::Keyboard::E))
						jumpSound.play();
					break;
        	}
		}
        
		sf::Time frameTime = frameClock.restart();

		window.setView(view);

		// Update the players' movements and speeds 
		player1.move(	sf::Keyboard::isKeyPressed(sf::Keyboard::D), // down
							sf::Keyboard::isKeyPressed(sf::Keyboard::S), // left
							sf::Keyboard::isKeyPressed(sf::Keyboard::F), // right
							sf::Keyboard::isKeyPressed(sf::Keyboard::E)); // up
							 
		player2.move(	sf::Keyboard::isKeyPressed(sf::Keyboard::K), // down
						 	sf::Keyboard::isKeyPressed(sf::Keyboard::J), // left
							sf::Keyboard::isKeyPressed(sf::Keyboard::L), // right
							sf::Keyboard::isKeyPressed(sf::Keyboard::I)); // up
		
		// Update posisitions
		double x1 = animatedSprite1.getPosition().x; double y1 = animatedSprite1.getPosition().y;
		double x2 = animatedSprite2.getPosition().x; double y2 = animatedSprite2.getPosition().y;
		player1.position->x = x1;
		player1.position->y = y1;
		player2.position->x = x2;
		player2.position->y = y2;

		// TODO : update score here ? (timeEncouter++, levelEncouter, changement des affichages)
		// purple balls when they are quite close, red when almost at the same place
		// distances are squares !!!
		oldDistance = distance; 
		distance = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		if ( distance < 10000 
			&& (player1.position->y<resHeight-35) && (player2.position->y<resHeight-35) 
			&& ( player1.speed->x>10 || player1.speed->x<-10 || player2.speed->x>10 || player2.speed->x<-10 ) )
		{
			if (distance < 1000)
			{ 
				if (player1.color!="red") 
				{
					player1.setIdleAnimation("red");
					player2.setIdleAnimation("red");
				}
				pts += frameTime.asSeconds()*500;
			}
			else 
			{
				if (player1.color!="purple")
				{
					player1.setIdleAnimation("purple");
					player2.setIdleAnimation("purple");
				}
			}
			pts += frameTime.asSeconds()*200;
			points.setColor(sf::Color::Green);
		}
		else 
		{
			if (player1.color!="blue")
			{
				player2.setIdleAnimation("blue");
				player1.setIdleAnimation("blue");
			}	
			points.setColor(sf::Color::Blue);
		}

		//lastPressedKey1=pressedKey1;
		//lastPressedKey2=pressedKey2;
    	noKeyWasPressed = true;
    	
    	// display time and points
    	sec = clock.getElapsedTime();
    	float t = sec.asSeconds();
    	time.setString(timeToString(t));
    	points.setString(to_string(pts));

		// Play the animation
		animatedSprite1.play(*player1.currentAnimation);
		animatedSprite1.move(*player1.speed * frameTime.asSeconds());
		
		animatedSprite2.play(*player2.currentAnimation);
		animatedSprite2.move(*player2.speed * frameTime.asSeconds());

		// update AnimatedSprite
		animatedSprite1.update(frameTime);
		animatedSprite2.update(frameTime);

		// draw
		window.draw(backSprite);
		window.draw(time);
		window.draw(points);
		window.draw(animatedSprite1);
		window.draw(animatedSprite2);
		window.display();
	}
}

// Time to string
string Game::timeToString(float sec)
{
	int minutes, seconds, millisec;
	string s;
	
	seconds = sec;
	float t3 = (sec-seconds) * 100;
	millisec = t3;
	minutes = seconds/60;
	seconds = seconds-minutes*60 ;
	
	if (minutes < 10) 
		s += "0";
	s += std::to_string(minutes) + ":";
	if (seconds < 10) 
		s += "0";
	s += std::to_string(seconds) + ":";
	if (millisec < 10) 
		s += "0"; 
	s += std::to_string(millisec);
	
	return s;
}



