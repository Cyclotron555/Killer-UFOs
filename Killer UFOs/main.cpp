#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include <Windows.h>
#include "UserInput.h"
#include "ObjectSetter.h"
#include "CreateRectangleFixture.h"
#include<string>
#include<Box2D/Box2D.h>




void CreateLandFixture(b2World& World, float X, float Y);
//void CreateBoxFixture(b2World& World, int mouseX, int mouseY);
int main() 
{
	CreateRectangleFixture* rectangle = NULL;
	UserInput UI;
	ObjectSetter Set;
	//Hide Console
	/*HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);*/
	/********************************************VARS*************************************************************/
	//Framerate
	float fps;
	sf::Clock clock = sf::Clock::Clock();
	sf::Time previousTime = clock.getElapsedTime();
	sf::Time currentTime;
	int boxFixtureCount = 0;
	unsigned int windowWidth = 1000;
	unsigned int windowHeight = 600;
	unsigned int frameRate = 60;
	float scale = 30.f;
	float playerSpeed = 600.0f;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Killer UFOs", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(frameRate);
	float winSizeX = window.getSize().x;
	float winSizeY = window.getSize().y;
	/********************************************END*VARS*********************************************************/
	/** Prepare the BOX2D world */
	b2Vec2 gravity(0.f, 10.0f);
	b2World world(gravity);
	//Player
	sf::Vector2f scalePlayer = sf::Vector2f(0.05f, 0.05f);
	sf::Texture playerTexture, landtexture, crateTexture;
	playerTexture.loadFromFile("Textures/ufo.png");
	landtexture.loadFromFile("Textures/land.png");
	crateTexture.loadFromFile("Textures/crate1.png");
	playerTexture.setSmooth(true);
	//Sprite Player
	sf::Vector2f startPos = sf::Vector2f(winSizeX / 2, winSizeY / 2);
	sf::Sprite player(playerTexture);
	player.setPosition(sf::Vector2f(startPos));
	player.scale(scalePlayer);
	Set.CenterSpriteOrigin(player);
	//Sprite Land
	sf::Sprite landSpr(landtexture);
	Set.CenterSpriteOrigin(landSpr);
	landSpr.scale(sf::Vector2f(2.0f, 1.0f));
	//Sprite crate
	sf::Sprite boxSpr(crateTexture);
	Set.CenterSpriteOrigin(boxSpr);
	boxSpr.scale(sf::Vector2f(0.1f, 0.1f));
	CreateLandFixture(world, 400.f, 500.f);



	

	//Game Loop
	while (window.isOpen())
	{
		//Get mouse position
		int MouseX = sf::Mouse::getPosition(window).x;
		int MouseY = sf::Mouse::getPosition(window).y;
		//Display mouse position
		std::cout << "Mouse position : X - " << MouseX << " | Y - " << MouseY << endl;
		sf::Event event;
		//Draw here
		window.clear(sf::Color::Black);
		window.draw(player);
		//Print framerate
		currentTime = clock.getElapsedTime();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
		/*std::cout << "Framerate : " << floor(fps) << endl;
		std::cout << "**************" << endl;*/
		previousTime = currentTime;


		//End Draw Here
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				if (rectangle != NULL)
				{
					delete rectangle;
				}
				window.close();
				break;
			}
		}
		//User input object
		if (event.type == sf::Event::KeyPressed)
		{
			UI.PlayerInput(player, event);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{

			rectangle = new CreateRectangleFixture(world, b2_dynamicBody, MouseX, MouseY, 24, 24, 30.0f, 1.0f);
			
			
				//Display how many boxes there are and ID
				std::cout << "There are : " << boxFixtureCount << endl;
				boxFixtureCount++;
		
		}
		//Simulate the BOX2D world
		world.Step(1 / 60.f, 8, 3);
		//Creates physical objects in the world | Connect sprite texture to fixture
		for (b2Body* bodyIterator = world.GetBodyList(); bodyIterator != 0; bodyIterator = bodyIterator->GetNext())
		{
			if (bodyIterator->GetType() == b2_dynamicBody)
			{
				boxSpr.setPosition(scale * bodyIterator->GetPosition().x, scale * bodyIterator->GetPosition().y);
				boxSpr.setRotation(bodyIterator->GetAngle() * 180 / b2_pi);
				window.draw(boxSpr);
			}
			else
			{
				landSpr.setOrigin(400.f, 8.f);
				landSpr.setPosition(bodyIterator->GetPosition().x * scale, bodyIterator->GetPosition().y * scale);
				landSpr.setRotation(180 / b2_pi * bodyIterator->GetAngle());
				window.draw(landSpr);
			}
		}
		//Display engine window
		window.display();
	}
	return 0;
}



//Creates fixture physics land Method
void CreateLandFixture(b2World& World, float X, float Y)
{
	float scale = 30.0f;
	b2BodyDef bodyDef;
	bodyDef.position = b2Vec2(X / 30.f, Y / 30.f);
	bodyDef.type = b2_staticBody;
	b2Body* Body = World.CreateBody(&bodyDef);
	b2PolygonShape shape; 
	shape.SetAsBox((800.f) / scale,(16.f / 2) / scale);
	b2FixtureDef fixureDef;
	fixureDef.density = 1.f;
	fixureDef.friction = 0.7f;
	fixureDef.shape = &shape;
	Body->CreateFixture(&fixureDef);
}
////Creates fixture physics box Method
//void CreateBoxFixture(b2World& World, int mouseX, int mouseY)
//{
//	float scale = 30.0f;
//	b2BodyDef BodyDef;
//	BodyDef.position = b2Vec2(mouseX / scale, mouseY / scale);
//	BodyDef.type = b2_dynamicBody;
//	b2Body* Body = World.CreateBody(&BodyDef);
//	//BodyDef.gravityScale = 100.0f;
//	b2PolygonShape Shape;
//	Shape.SetAsBox((24.f / 2) / scale, (24.f / 2) / scale);
//	b2FixtureDef FixtureDef;
//	FixtureDef.density = 1.f;
//	FixtureDef.friction = 0.7f;
//	FixtureDef.restitution = 0.5f;
//	FixtureDef.shape = &Shape;
//	Body->CreateFixture(&FixtureDef);
//}