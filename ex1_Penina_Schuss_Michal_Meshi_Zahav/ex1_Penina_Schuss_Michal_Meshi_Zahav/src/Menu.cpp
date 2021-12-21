#include "Menu.h"
#include "macros.h"
#include "Help.h"

//========================================================== 
Menu::Menu()
	:m_windowMenu(sf::VideoMode(WIDTH_WINDOW_SIZE, LENGTH_WINDOW_SIZE), "menu"), m_button(sf::Vector2f(250, 200))
{
	m_texture.loadFromFile("save_the_king.jpg");
	m_background.setTexture(m_texture);
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	m_text.setFont(m_font);
	std::string b = "help";
	updatingToDiffrentButton(b, 1);
	;
}
//==========================================================
; void Menu::display()
{
	m_windowMenu.draw(m_background);
	
	/*m_texture.loadFromFile("play.png");
	m_background.setTexture(m_texture);
	m_background.setPosition(sf::Vector2f(375, 500));
	m_windowMenu.draw(m_background);
	m_texture.loadFromFile("exit.png");
	m_background.setTexture(m_texture);
	m_background.setPosition(sf::Vector2f(750, 500));
	m_windowMenu.draw(m_background);
	m_texture.loadFromFile("help.png");
	m_background.setTexture(m_texture);
	m_background.setPosition(sf::Vector2f(1100, 500));
	m_windowMenu.draw(m_background);*/

	m_windowMenu.draw(m_button);
	m_windowMenu.draw(m_text);
	updatingToDiffrentButton("new game",2 );
	m_windowMenu.draw(m_button);
	m_windowMenu.draw(m_text);
	updatingToDiffrentButton("exit", 3);
	m_windowMenu.draw(m_button);
	m_windowMenu.draw(m_text);
	m_windowMenu.display();
}
//==========================================================
void Menu::updatingToDiffrentButton(std::string string, int i)
{
	m_text.setString(string);
	m_text.setFillColor(sf::Color::Black);
	m_text.setPosition(sf::Vector2f(75*i+ 250 * (i - 1), 500));
	m_button.setPosition(sf::Vector2f(62.5*i+250*(i-1),400));
}
//==========================================================
void Menu::userSelection(){
	while (m_windowMenu.isOpen()) {
		if (auto event = sf::Event{}; m_windowMenu.waitEvent(event) && sf::Event::MouseButtonReleased == event.type)
		{
			auto location = m_windowMenu.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			switch (realizeWantedButton(location)) 
			{
			case HELP:Help::instance().openHelp();
				break;
			case NEW_GAME:m_game.game();
				break;
			case EXIT: exit(1);
				break;
			}
		}
			
	}
}

//==========================================================
int Menu::realizeWantedButton(sf::Vector2f location)
{
	if (location.y < 400 && location.y>600)
		return 0;
	int wanted_button = 1 + (location.x / 312.5);
	if (location.x > 62.5 * wanted_button)
		return wanted_button;
	return 0;
}