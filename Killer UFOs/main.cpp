#include <SFML/Graphics.hpp>
#include<iostream>
#include <Windows.h>
#include "UserInput.h"
#include "ObjectSetter.h"
#include<string>




int main() 
{

	UserInput UI;
	ObjectSetter OS;
	//Hide Console
	/*HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);*/
	/********************************************VARS*************************************************************/
	unsigned int windowWidth = 640;
	unsigned int windowHeight = 360;
	unsigned int frameRate = 60;
	float playerSpeed = 600.0f;
	/********************************************END*VARS*********************************************************/
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Killer UFOs", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(frameRate);
	
	float winSizeX = window.getSize().x;
	float winSizeY = window.getSize().y;

	//Player
	sf::Vector2f scalePlayer = sf::Vector2f(0.05f, 0.05f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("textures/ufo.png");
	playerTexture.setSmooth(true);
	sf::Sprite player(playerTexture);
	sf::Vector2f startPos = sf::Vector2f(winSizeX / 2, winSizeY / 2);
	player.setPosition(sf::Vector2f(startPos));
	player.scale(scalePlayer);
	OS.SetObjectOrigin(player);
	//End Player


	

	//Game Loop
	while (window.isOpen())
	{
		//Draw here
		window.clear(sf::Color::Black);
		window.draw(player);
		window.display();
		//End Draw Here


		sf::Event event;
		UI.PlayerInput(player);
		UI.SlowDown(playerSpeed, player);
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
	}
	return 0;
}