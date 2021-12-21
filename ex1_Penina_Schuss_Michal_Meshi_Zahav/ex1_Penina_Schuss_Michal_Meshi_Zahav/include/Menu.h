#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Menu
{
public:
	Menu();
    void display();
	void userSelection();
	
private:
	int  realizeWantedButton(sf::Vector2f);
	void updatingToDiffrentButton(std::string, int);
	sf ::RenderWindow m_windowMenu;
	sf::Texture m_texture;
	sf::Sprite m_background;
	sf::RectangleShape m_button;
	sf::Font m_font;
	sf::Text m_text;
	Game m_game;
};