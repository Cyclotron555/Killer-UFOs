#include "UserInput.h"

    
	
	
	void UserInput::PlayerInput(sf::Sprite& player)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			player.move(-6.0f, 0.0f);
			std::cout << "Left is pressed!" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			wasKeyPressed = true;
			player.move(6.0f, 0.0f);
			std::cout << "Right is pressed!" << std::endl;
			if (sf::Event::KeyReleased && wasKeyPressed == true)
			{
				wasKeyPressed = false;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			player.move(0.0f, -6.0f);
			std::cout << "Up is pressed!" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			player.move(0.0f, 6.0f);
			std::cout << "Down is pressed!" << std::endl;
		}
		
		{
			
		}
	}
	//Slow down the player
	void UserInput::SlowDown(float speed, sf::Sprite& spr)
	{
		for (float i = speed; i >= 0; i--)
		{
			if (i > 0 && wasKeyPressed)
			{
				speed == i;
				spr.move(6.0f, 0.0f);
			}
			else
			{
				wasKeyPressed = false;
				break;
			}
		}
	}



