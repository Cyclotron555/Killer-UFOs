
#ifndef USER_INPUT_H
#define USER_INPUT_H
#include <SFML/Graphics.hpp>
#include<iostream>
#include <Windows.h>
#include <map>




class UserInput
{
	bool wasKeyPressed = false;
public:
	void PlayerInput(sf::Sprite& player);
	void SlowDown(float speed, sf::Sprite& spr);
};

#endif // !1