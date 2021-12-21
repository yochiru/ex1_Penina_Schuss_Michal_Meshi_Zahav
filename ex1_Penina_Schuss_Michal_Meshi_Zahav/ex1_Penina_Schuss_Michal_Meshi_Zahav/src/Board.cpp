#include "Board.h"


void Board::readingFromFileAndUpdate(std::string name_level)
{
    std::ifstream file;
    file.open(name_level);
    if (!file.is_open())
    {
        std::cerr << "Cannot open input file\n";  //צריך להוריד את זה כי לא יהיה טרמינל
        exit(EXIT_FAILURE);
    }
    char character;
    int rows, cols;
    file >> rows >> cols;
    m_staticArr.resize(rows, std::vector<StaticOb*>(cols));
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            character = file.get();
            assignObject(character, row, col, rows, cols);
        }
    }
    file.close();
}
//=========================================
void Board::assignObject(char character, int row, int col, int rows, int cols)
{
    //לגבי המטריצה הסטטית אפשר מראש לבנות אותה בגודל שהתקבל מהקובץ ולאתחל הכל לנאל ואז פה לא נצטרך להתעסק עם הנאל
    sf::Vector2f to_scale(1.f / cols, 1.f / rows);
    switch (character)
    {
    case KING: {
        King* king = new (std::nothrow) King(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_plyerArr.push_back(king);
        m_staticArr[row][col] = nullptr;
        break;
    }
    case MAGE: {
        Mage* mage = new (std::nothrow) Mage(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_plyerArr.push_back(mage);
        m_staticArr[row][col] = nullptr;
        break;
    }
    case WARRIOR: {
        Warrior* warrior = new (std::nothrow) Warrior(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_plyerArr.push_back(warrior);
        m_staticArr[row][col] = nullptr;
        break;
    }
    case THIEF: {
        Thief* thief = new (std::nothrow) Thief(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_plyerArr.push_back(thief);
        m_staticArr[row][col] = nullptr;
        break;
    }
    case WALL: {
        Wall* wall = new (std::nothrow) Wall(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_staticArr[row][col] = wall;
        break;
    }
    case FIRE: {
        Fire* fire = new (std::nothrow) Fire(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_staticArr[row][col] = fire;
        break;
    }
    case ORK: {
        Ork* ork = new (std::nothrow) Ork(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_staticArr[row][col] = ork;
        break;
    }
    case KEY: {
        Key* key = new (std::nothrow) Key(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_staticArr[row][col] = key;
        break;
    }
            /*case TELEPORT: {
                Teleport* teleport = new (std::nothrow) Teleport(sf::Vector2f);
                m_staticArr[row].push_back(teleport);
                break;
            }*/
    case THRONE: {
        Throne* throne = new (std::nothrow) Throne(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_staticArr[row][col] = throne;
        break;
    }
    case GATE: {
        Gate* gate = new (std::nothrow) Gate(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_staticArr[row][col] = gate;
        break;
    }
    case DWARF: {
        Dwarf* dwarf = new (std::nothrow) Dwarf(sf::Vector2f(col * (WIDTH_WINDOW_SIZE / cols), row * (LENGTH_WINDOW_SIZE / rows)), to_scale);
        m_staticArr[row][col] = nullptr;
        m_dwarfArr.push_back(dwarf);
        break;
    }
    case EMPTY: {
        m_staticArr[row][col] = nullptr;
        break;
    }
    }
}
//=================================================================================================
void Board::print(sf::RenderWindow& window)
{
    sf::Texture tex;
    tex.loadFromFile("backGroundLevel.jpg");
    sf::Sprite spr(tex);
    window.draw(spr);

    for (int index_r=0; index_r < m_staticArr.size(); index_r++)
    {
        for (int index_c = 0; index_c < m_staticArr[index_r].size(); index_c++)
        {
            if(m_staticArr[index_r][index_c] != nullptr)
               window.draw(m_staticArr[index_r][index_c]->m_mySprite);
        }
    }
    for (int index_r = 0; index_r < m_dwarfArr.size(); index_r++)
        window.draw(m_dwarfArr[index_r]->m_mySprite);
    for (int index_r = 0; index_r < m_plyerArr.size(); index_r++)
        window.draw(m_plyerArr[index_r]->m_mySprite);
}
//=======================================================================================
void Board::setPlayer(Player* player_to_change, int index)
{
    player_to_change = m_plyerArr[index];
}