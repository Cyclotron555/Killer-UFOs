#include "ObjectSetter.h"



//Sets a sprite's origin
void ObjectSetter::SetObjectOrigin(sf::Sprite& sprite)
{
	sprite.setOrigin(sf::Vector2f((sprite.getTexture()->getSize().x) / 2, (sprite.getTexture()->getSize().y) / 2));
}
