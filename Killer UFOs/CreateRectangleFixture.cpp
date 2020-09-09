#include "CreateRectangleFixture.h"


//Constructor 1 [Empty to be used when adjusting object properties]
CreateRectangleFixture::CreateRectangleFixture() {}

//Constructor 2 [Overloaded with default parameters] 
CreateRectangleFixture::CreateRectangleFixture(b2World& world, b2BodyType fixtureType, float creationPositionX,
	float creationPositionY, float dimentionX, float dimentionY, float fixtureScale, float fixtureDensity)
{
	b2BodyDef bodyDef;
	b2PolygonShape rectShape;
	bodyDef.position = b2Vec2(creationPositionX / fixtureScale, creationPositionY / fixtureScale);
	bodyDef.type = fixtureType;
	b2Body* Body = world.CreateBody(&bodyDef);
	rectShape.SetAsBox((dimentionX / 2) / fixtureScale, (dimentionY / 2) / fixtureScale);
	b2FixtureDef fixtureDefine;
	fixtureDefine.density = 1.f;
	fixtureDefine.friction = 0.7f;
	fixtureDefine.restitution = 0.5f;
	fixtureDefine.shape = &rectShape;
	Body->CreateFixture(&fixtureDefine);
}
