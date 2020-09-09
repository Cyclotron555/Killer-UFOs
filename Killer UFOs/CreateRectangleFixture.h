#pragma once
#include <Box2D.h>
class CreateRectangleFixture
{
public:
	CreateRectangleFixture();
	CreateRectangleFixture(b2World& world, b2BodyType fixtureType/*Static or Dynamyc*/, float creationPositionX,
		float creationPositionY, float dimentionX, float dimentionY, float fixtureScale, float fixtureDensity);
};

