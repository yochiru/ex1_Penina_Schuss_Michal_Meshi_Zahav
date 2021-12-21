#pragma once
#include "Player.h"
//#include <SFML/Graphics.hpp>

class King : public Player
{
public:
	King(const sf::Vector2f&, const sf::Vector2f&);
	King() = default;
};