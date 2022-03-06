#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<vector>
#include "Menu.h"
#include "Kulka.h"
#include "Paleta.h"
#include "Bloczek.h"

class Menu;

class Game
{
    vector<Bloczek> contener2;
    int points = 0;
public:
    void gameLoop(sf::RenderWindow*& window,Game&game_object,sf::Font font,Menu menu_object);
    static void gameOver(sf::RenderWindow*& window,sf::Font font, sf::Event&event, vector<string>&inputFromPlayer);
    static void printGameOver(sf::RenderWindow*& window,sf::Text& text);
    void addBlocks(Game&object);
    void removeBlocks(Game& game_object);
    void printBlocks(sf::RenderWindow*& window,Game game_object);
    void printPoints(sf::RenderWindow*&window,sf::Font font,Game game_object);
    void addPoint(Game&game_object);
};

