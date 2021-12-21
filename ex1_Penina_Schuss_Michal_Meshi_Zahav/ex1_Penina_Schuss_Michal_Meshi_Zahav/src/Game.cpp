#include "Game.h"
#include <fstream>
#include<iostream>
#include "macros.h"

//===================================================================================
Game::Game()
	:m_window(sf::VideoMode(WIDTH_WINDOW_SIZE, LENGTH_WINDOW_SIZE), "save the king")
{}
//===================================================================================
void Game::game() {
	std::string name_file = "level1.txt";
	std::ifstream file;
	file.open("num of levels.txt");
	if (!file.is_open()) {
		std::cerr << "Cannot open input file\n";
		exit(EXIT_FAILURE);
	}
	int num_of_levels;
	file >> num_of_levels;
	for (int i = 1; i <= num_of_levels; i++)
	{
		m_currentLevel = new (std::nothrow) Level(i, num_of_levels);
		m_currentLevel->startLevel(m_window, name_file);
		delete m_currentLevel;
		name_file[5] = char(i + 49);
	} 
}