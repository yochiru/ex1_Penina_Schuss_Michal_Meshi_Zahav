#include "Throne.h"
#include "macros.h"

Throne::Throne(const sf::Vector2f& place, const sf::Vector2f& to_scale)
	:StaticOb(place, THRONE_PLACE, to_scale)
{}