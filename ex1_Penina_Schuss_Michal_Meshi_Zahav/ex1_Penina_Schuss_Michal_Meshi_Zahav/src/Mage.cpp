#include "Mage.h"
#include "macros.h"

Mage::Mage(const sf::Vector2f& place, const sf::Vector2f& to_scale)
	:Player(place, MAGE_PLACE, to_scale)
{}