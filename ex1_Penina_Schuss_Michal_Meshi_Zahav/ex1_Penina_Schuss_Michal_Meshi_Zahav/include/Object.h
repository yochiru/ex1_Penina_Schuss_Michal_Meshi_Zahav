#pragma once
#include <SFML/Graphics.hpp>

class Object 
{
public:
	Object(const sf::Vector2f&, const int, const sf::Vector2f&);
	sf::Sprite m_mySprite;
};