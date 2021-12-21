#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"

class Game {
public:
	Game();
	void game();
private:
	Level* m_currentLevel;
	sf::RenderWindow m_window;
};
	