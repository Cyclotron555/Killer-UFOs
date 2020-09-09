#include "ObjectSetter.h"



//Sets a sprite's origin
void ObjectSetter::CenterSpriteOrigin(sf::Sprite& sprite)
{
	sprite.setOrigin(sf::Vector2f((sprite.getTexture()->getSize().x) / 2, (sprite.getTexture()->getSize().y) / 2));
}
//Changes a sprite origin
void ObjectSetter::ChangeSpriteOrigin(sf::Sprite& sprite, float originX, float originY)
{
	sprite.setOrigin(sf::Vector2f(originX, originY));
}
