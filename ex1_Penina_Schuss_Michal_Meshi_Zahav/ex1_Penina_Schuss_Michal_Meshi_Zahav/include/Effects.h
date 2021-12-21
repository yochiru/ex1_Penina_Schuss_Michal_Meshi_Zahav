#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Effects {
public:
	static Effects& instance();
	void setSprite(int index, sf::Sprite&);
private:
	Effects();
	std::vector<sf::Texture> m_textureVec;
};