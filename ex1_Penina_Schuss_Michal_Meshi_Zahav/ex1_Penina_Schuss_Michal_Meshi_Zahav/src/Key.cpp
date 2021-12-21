#include "Key.h"
#include "macros.h"

Key::Key(const sf::Vector2f& place, const sf::Vector2f& to_scale)
	:StaticOb(place, KEY_PLACE, to_scale)
{}