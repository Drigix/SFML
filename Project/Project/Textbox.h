#pragma once
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Game.h"
#include <iostream>
#include<Windows.h>
#include <sstream>
#include<chrono>
#include<thread>
#include <regex>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox:public Draw
{
	sf::Text textbox;
	std::ostringstream ss;
	bool isSelected;
	bool isSaved=false;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Textbox(int size,sf::Color color,bool selected,sf::Vector2f position, sf::Font& font);
	Textbox(std::string name, int size, sf::Color color, sf::Vector2f position, sf::Font& font);

	void setString(std::string str);

	void typedOn(sf::Event input,sf::RenderWindow*&window, std::vector<std::pair<int, std::string>>&cointainer, int points);
	void inputText(int charTyped, sf::RenderWindow*& window, std::vector<std::pair<int, std::string>>&cointainer,int points);
	void deleteLastChar();

	bool checkNick();
};

