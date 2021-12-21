#pragma once
#include <SFML/Graphics.hpp>

class Help {
public:
    static Help& instance();
	void openHelp();
	std::string ReturnString();
private:
	Help();
	sf::RenderWindow m_helpWindow;
	sf::Font m_font;
	sf::Text m_text;
};