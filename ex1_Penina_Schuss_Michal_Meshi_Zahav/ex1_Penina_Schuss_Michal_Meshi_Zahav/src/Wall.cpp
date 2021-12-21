#include "Wall.h"
#include "macros.h"

Wall::Wall(const sf::Vector2f& place, const sf::Vector2f& to_scale)
	:StaticOb(place, WALL_PLACE, to_scale)
{}