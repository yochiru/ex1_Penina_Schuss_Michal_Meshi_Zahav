#pragma once
#include "Object.h"
//#include <SFML/Graphics.hpp>

class Player :public Object
{
public:
	Player() = default;
	Player(const sf::Vector2f&, const int, const sf::Vector2f&);
};