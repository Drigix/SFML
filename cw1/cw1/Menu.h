#pragma once
#include "Bloczek.h"
#include "Przycisk.h"
#include "Game.h"
#include<fstream>
#include<sstream>
#include<string>
#include<map>

using namespace std;

class Game;

class Menu
{
    sf::Font font;
    sf::Texture texture;
    sf::Sprite enemySprite;
    sf::Vector2f mousePositionView;
public:
    static void loadRecords(string& file, map<int, string>& contener);
    void goToMenu();
    bool loadFont();
    sf::Font getFont(Menu menu_object);
    bool loadTexture();
    void setSprite();
    sf::Sprite getSprite(Menu menu_object);
    void udpadeMousePosition(sf::RenderWindow* window);
    void checkButtonClick(sf::RenderWindow*& window,Menu menu,Game& game_object,Przycisk play, Przycisk records, Przycisk quit, Przycisk back);
    bool goToRecords(sf::RenderWindow*& window,Przycisk back, Menu menu, map<int, string>& contener);
    void showRecords(sf::RenderWindow*& window, map<int, string>& contener,Menu menu);
};
