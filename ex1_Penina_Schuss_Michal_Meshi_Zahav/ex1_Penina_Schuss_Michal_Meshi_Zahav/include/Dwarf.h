#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>

class Dwarf :public Object
{
public:
	Dwarf() = default;
	Dwarf(const sf::Vector2f&, const sf::Vector2f&);
};