#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<filesystem>
#include "File.h"
#include "Button.h"


class Texture
{
	sf::Texture texture;
	sf::Sprite sprite;
	//std::vector<std::string>vectorTextureOfBackground;
	int numberOfTexture = 0;
public:
	std::vector<std::string>vectorTextureOfBackground;
	void setTexture();
	sf::Texture getTexture();
	void setSprite();
	sf::Sprite getSprite();
	void changeTexture(Button& leftTexture, Button& rightTexture);

	void changeBackgroud(Button& leftTexture, Button& rightTexture);
	void runThreads(Button& leftTexture, Button& rightTexture);
};

