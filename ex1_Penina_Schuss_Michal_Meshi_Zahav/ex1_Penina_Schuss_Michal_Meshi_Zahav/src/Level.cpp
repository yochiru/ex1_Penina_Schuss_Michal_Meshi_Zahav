#include "Level.h"
#include <fstream>
#include <iostream>
#include "macros.h"
#include <SFML/Graphics.hpp>

Level::Level(int i, int num_of_levels)
{
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	m_text.setFont(m_font);
	if (i != num_of_levels)
		m_text.setString("Champion!You have completed a level");
	else
		m_text.setString("you are the best! You've finished the game");
}
//=====================================================================
void Level::startLevel(sf::RenderWindow& window, std::string name_file)
{
    m_board.readingFromFileAndUpdate(name_file);
    bool king_on_throne = false;
    sf::Clock clock;
    const float dwarfSpeed = 100.f;
    m_board.setPlayer(current_player, 0);
    while (true)
    {
        window.clear();
        if (king_on_throne)
            window.draw(m_text);
        else
            m_board.print(window);
        window.display();
        if (king_on_throne)
            break;
        for (auto event = sf::Event{}; window.pollEvent(event); )
        {
            float deltaTime = clock.restart().asSeconds();
           /*להזיז את הגמדים*/
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
                break;
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::K: m_board.setPlayer(current_player, 0);
                    break;
                case sf::Keyboard::M: m_board.setPlayer(current_player, 1);
                    break;
                case sf::Keyboard::W: m_board.setPlayer(current_player, 2);
                    break;
                case sf::Keyboard::T: m_board.setPlayer(current_player, 3);
                    break;
                }
            }
            
        }
    }
    window.close();
}