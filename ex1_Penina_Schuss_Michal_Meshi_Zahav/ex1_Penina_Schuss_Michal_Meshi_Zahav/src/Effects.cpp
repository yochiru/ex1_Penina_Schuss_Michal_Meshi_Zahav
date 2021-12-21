#include "Effects.h"
#include "macros.h"
//#include <iostream>

Effects& Effects::instance() {
	static Effects inst;
	return inst;
}
//==============================================================================
Effects::Effects()
{
	m_textureVec.resize(17);
	m_textureVec[0].loadFromFile(KING_PICTURE);
	m_textureVec[1].loadFromFile(KING_MARKER_PICTURE);
	m_textureVec[2].loadFromFile(MAGE_PICTURE);
	m_textureVec[3].loadFromFile(MAGE_MARKER_PICTURE);
	m_textureVec[4].loadFromFile(WARRIOR_PICTURE);
	m_textureVec[5].loadFromFile(WARRIOR_MARKER_PICTURE);
	m_textureVec[6].loadFromFile(THIEF_PICTURE);
	m_textureVec[7].loadFromFile(THIEF_MARKER_PICTURE);
	m_textureVec[8].loadFromFile(WALL_PICTURE);
	m_textureVec[9].loadFromFile(FIRE_PICTURE);
	m_textureVec[10].loadFromFile(ORK_PICTURE);
	m_textureVec[11].loadFromFile(KEY_PICTURE);
	m_textureVec[12].loadFromFile(TELEPORT_PICTURE);
	m_textureVec[13].loadFromFile(THRONE_PICTURE);
	m_textureVec[14].loadFromFile(GATE_PICTURE);
	m_textureVec[15].loadFromFile(PRESENT_PICTURE);
	m_textureVec[16].loadFromFile(DWARF_PICTURE);

	/*sf::RenderWindow n(sf::VideoMode(1500, 200), "f");
	sf::Sprite s(getTexture(2));
	n.draw(s);
	n.display();
	int i;
	std::cin >> i;*/
}
//==============================================================================
void Effects::setSprite(int index, sf::Sprite& spr)
{
	return spr.setTexture(m_textureVec[index]);
}

//sf::Texture Effects::getTexture(int index)
//{
//	return m_textureVec[index];
//}
//==============================================================================