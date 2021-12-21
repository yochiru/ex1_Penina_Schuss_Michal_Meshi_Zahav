#include "Object.h"
#include "Effects.h"


Object::Object(const sf::Vector2f& place, const int index, const sf::Vector2f& to_scale)
//:m_mySprite(Effects::instance().getTexture(index))
{
	Effects::instance().setSprite(index, m_mySprite);
	m_mySprite.setPosition(place);
	m_mySprite.scale(to_scale);
}