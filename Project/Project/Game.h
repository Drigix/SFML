#pragma once
#include <SFML/Graphics.hpp>
#include"SFML/Audio.hpp"
#include<iostream>
#include<vector>
#include<sstream>
#include<thread>
#include<Windows.h>
#include<fstream>
#include<chrono>
#include "Draw.h"
#include "Ball.h"
#include "Platform.h"
#include "Blocks.h"
#include "Textbox.h"
#include"Button.h"
#include"Sound.h"
#include"Texture.h"
#include"File.h"

class Textbox;



class Game
{
	std::vector<Blocks> vectorOfBlocks;
	bool backIsPressed = false;
	bool checkFreeze = true;
	int points = 0;
protected:
	sf::RenderWindow* window;
	sf::Font font;
	Texture texture;
	sf::Sprite sprite;
	sf::Vector2f mousePositionView;
	std::vector<std::pair<int, std::string>>vectorOfRecords;
	Sound soundEffect;
	Sound soundEffect2;
public:
	Game(int width, int height, std::string name,sf::Font font);
	~Game();

	bool setSprite();
	sf::Sprite getSprite();

	void gameLoop(Button& back, Button& quit);
	void freezeTime(Ball& ball, Platform& platform);

	void update(Ball& ball, Platform& platform);
	
	void updateMousePosition();
	void checkButtonClickAfterGame(Button&back,Button&quit);

	bool checkTouch(Platform& platform, Ball& ball);
	bool checkTouch2(Ball& ball,Blocks&blocks);

	void addBlocks(Blocks& blocks);
	void printBlocks();

	void gameOver(sf::Event& event, Textbox& text2, Button& back, Button& quit);
	static void saveScore(sf::RenderWindow*& window, std::vector<std::pair<int, std::string>>& cointainer);
	static bool checkScore(std::vector<std::pair<int, std::string>>& cointainer, int points, std::string name);

	Textbox printPoints();
	Textbox printScore();

	void addPoints();
	void removeBlocks();

	void manageSound();
	void turnUpVolume();
	void turnDownVolume();
	Sound& getSound();
};

