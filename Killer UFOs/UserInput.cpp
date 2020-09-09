#include "UserInput.h"





void UserInput::PlayerInput(sf::Sprite& player, sf::Event& ev)
{
	playerSpeed = 6.0f;
	switch (ev.key.code)
	{
	case sf::Keyboard::Left:
		player.move(-playerSpeed, 0.0f);
		std::cout << "Left is pressed!" << std::endl;
		break;
	case sf::Keyboard::Right:
		player.move(playerSpeed, 0.0f);
		std::cout << "Right is pressed!" << std::endl;
		break;
	case sf::Keyboard::Up:
		player.move(0.0f, -playerSpeed);
		std::cout << "Up is pressed!" << std::endl;
		break;
	case sf::Keyboard::Down:
		player.move(0.0f, playerSpeed);
		std::cout << "Down is pressed!" << std::endl;
		break;
	}

}




