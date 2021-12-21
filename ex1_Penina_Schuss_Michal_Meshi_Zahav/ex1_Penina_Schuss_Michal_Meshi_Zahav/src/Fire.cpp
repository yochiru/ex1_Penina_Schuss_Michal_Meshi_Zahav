#include "Fire.h"
#include "macros.h"

Fire::Fire(const sf::Vector2f& place, const sf::Vector2f& to_scale)
	:StaticOb(place, FIRE_PLACE, to_scale)
{}