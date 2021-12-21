#include "Gate.h"
#include "macros.h"

Gate::Gate(const sf::Vector2f& place, const sf::Vector2f& to_scale)
	:StaticOb(place, GATE_PLACE, to_scale)
{}