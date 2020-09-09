
#ifndef USER_INPUT_H
#define USER_INPUT_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include <Windows.h>
#include <map>
using namespace std;




class UserInput
{
	bool wasKeyReleased = false;
	bool rightPressed = false;
	float playerSpeed = 0.0f;
	sf::Clock clock;
	float deltaTime = clock.restart().asSeconds();
public:
	void PlayerInput(sf::Sprite& player, sf::Event& ev);
};

#endif // !1