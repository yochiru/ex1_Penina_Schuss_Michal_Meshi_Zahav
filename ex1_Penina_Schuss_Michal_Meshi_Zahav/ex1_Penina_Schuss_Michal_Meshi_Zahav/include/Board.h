#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Object.h"
#include "macros.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Wall.h"
#include "Fire.h"
#include "Ork.h"
#include "Gate.h"
#include "Throne.h"
#include "Key.h"
#include "Teleport.h"
#include "Dwarf.h"

class Board
{
public:
	void readingFromFileAndUpdate(std::string);
	void assignObject(char, int, int, int, int);
	void print(sf::RenderWindow& window);
	void setPlayer(Player* player_to_change, int index);
private:
	std::vector<std::vector<StaticOb*>> m_staticArr;
	std::vector<Player*> m_plyerArr;
	std::vector<Dwarf*> m_dwarfArr;
};