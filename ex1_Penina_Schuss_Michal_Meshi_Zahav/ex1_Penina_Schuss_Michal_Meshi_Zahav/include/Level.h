#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Information.h"
#include "Board.h"

class Level
{
public:
	Level() = default;
	Level(int, int);	
	void startLevel(sf::RenderWindow&, std::string);
	//~Level();
private:
	Board m_board;
	Information m_information;
	sf::Font m_font;
	sf::Text m_text;
	Player* current_player;
};