#include "Thief.h"
#include "macros.h"

Thief::Thief(const sf::Vector2f& place, const sf::Vector2f& to_scale)
	:Player(place, THIEF_PLACE, to_scale)
{}