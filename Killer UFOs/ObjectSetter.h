#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <Windows.h>
#include "UserInput.h"
#include<string>
class ObjectSetter
{
public:
	void CenterSpriteOrigin(sf::Sprite& sprite);
	void ChangeSpriteOrigin(sf::Sprite& sprite, float originX, float originY);
};

