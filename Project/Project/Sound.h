#pragma once
#include"SFML/Audio.hpp"
#include"Button.h"
#include<iostream>
#include<fstream>
#include<filesystem>
#include "File.h"

enum status{play=1,stop};

class Sound
{
	sf::Music music;
	sf::SoundBuffer buffer;
	sf::Sound soundEffect;
	//std::vector<std::string> vectorOfSongs;
	int numberOfSong = 0;
public:
	std::vector<std::string> vectorOfSongs;
	void setMusic();
	void setBuffer(std::string file);
	sf::SoundBuffer getBuffer();
	void playMusic();
	void playEffect();

	void turnUpVolume();
	void turnDownVolume();

	void changeSong(Button& leftSong, Button& rightSong);
	void runThreads(Button& leftSong, Button& rightSong);

	void ifStop();
};

