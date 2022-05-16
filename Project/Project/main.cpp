#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    sf::Font font;
    if (font.loadFromFile("Fonts/!!! Handwritingg _3.ttf"))
    {
        Menu menu(800, 600, "Arcanoid", font);
        menu.goToMenu();
    }
    return 0;
}