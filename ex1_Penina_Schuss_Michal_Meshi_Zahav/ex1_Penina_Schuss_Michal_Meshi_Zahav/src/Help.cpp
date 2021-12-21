#include "Help.h"
#include<fstream>
#include <iostream>
#include "macros.h"

Help& Help::instance() {
	static Help inst;
	return inst;
}

Help::Help()
	:m_helpWindow(sf::VideoMode(WIDTH_WINDOW_SIZE, LENGTH_WINDOW_SIZE), "help")
{
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	m_text.setFont(m_font);
	m_text.setString(ReturnString());
	m_text.setFillColor(sf::Color::Blue);
}

void Help::openHelp() {
	
	m_helpWindow.draw(m_text);
	m_helpWindow.display();
}

std::string Help::ReturnString()
{
	std::ifstream file;
	file.open("help.txt");
	if (!file.is_open()) 
	{
		std::cerr << "Cannot open input file\n";
		exit(EXIT_FAILURE);
	}
	std::string stringHelp;
	while (!file.eof())
	{
		stringHelp.push_back(file.get());
	}
	file.close();
	return stringHelp;
}


