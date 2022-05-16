#pragma once
#include <SFML/Graphics.hpp>
#include<fstream>
#include<filesystem>
#include<ranges>
#include<sstream>
#include "Game.h"
#include "Button.h"

class Game;

class Menu:public Game
{
public:
	Menu(int width, int height, std::string name, sf::Font font) : Game(width, height, name, font) {};

	void goToMenu();

	void update(Button&play, Button& records, Button& quit, Textbox&textArcanoid,Button&back, Button& backGame, Button& quitGame, Button& options);
	void updateMusic(Button& minusVolume, Button& plusVolume);

	void checkButtonClick(Button& play, Button& records, Button& quit, Button&back, Button& backGame, Button& quitGame, Button& options);

	void goToRecords(Button&back);
	void goToOptions(Button& back);
	
	void showRecords();
};

