#pragma once
#include<iostream>
#include<fstream>
#include<filesystem>
#include<thread>
#include "Texture.h"
#include "Sound.h"

class File
{
public:
	void loadTexturesFromFile(std::vector<std::string>& vectorTextureOfBackground);
	void loadSongsFromFile(std::vector<std::string>& vectorOfSongs);
	void loadRecordsFromFile(std::vector<std::pair<int, std::string>>&vectorOfRecords);

	void runAllThreads(std::vector<std::string>&vectorTextureOfBackground, std::vector<std::string>& vectorOfSongs ,std::vector<std::pair<int, std::string>>&vectorOfRecords);
};

