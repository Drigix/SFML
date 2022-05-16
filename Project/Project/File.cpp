#include "File.h"

void File::loadTexturesFromFile(std::vector<std::string>& vectorTextureOfBackground)
{
	std::filesystem::path p("texturesBackground.txt");
	if (!std::filesystem::exists(p))
	{
		std::cout << "FILE" << p << "NOT EXISTS!" << std::endl;
	}
	else
	{
		std::ifstream read(p);
		if (read)
		{
			std::string nameTextureOfBackground;
			while (read >> nameTextureOfBackground)
			{
				vectorTextureOfBackground.push_back(nameTextureOfBackground);
			}
			read.close();
		}
	}
}

void File::loadSongsFromFile(std::vector<std::string>& vectorOfSongs)
{
	std::filesystem::path p("songs.txt");
	if (!std::filesystem::exists(p))
	{
		std::cout << "FILE" << p << "NOT EXISTS!" << std::endl;
	}
	else
	{
		std::ifstream read(p);
		if (read)
		{
			std::string nameOfSong;
			while (read >> nameOfSong)
			{
				vectorOfSongs.push_back(nameOfSong);
			}
			read.close();
		}
	}
}

void File::loadRecordsFromFile(std::vector<std::pair<int, std::string>>&vectorOfRecords)
{
	std::filesystem::path p("records.txt");
	if (!std::filesystem::exists(p))
	{
		std::ofstream open(p);
	}
	else
	{
		std::ifstream read(p);
		if (read)
		{
			std::string nick;
			int points;
			while (read >> nick && read >> points)
			{
				vectorOfRecords.push_back({ points, nick });
			}
			read.close();
		}
	}
}

void File::runAllThreads(std::vector<std::string>& vectorTextureOfBackground, std::vector<std::string>& vectorOfSongs,std::vector<std::pair<int, std::string>>& vectorOfRecords)
{
	std::thread t1(&File::loadTexturesFromFile,this, std::ref(vectorTextureOfBackground));
	std::thread t2(&File::loadSongsFromFile,this, std::ref(vectorOfSongs));
	std::thread t3(&File::loadRecordsFromFile,this,std::ref(vectorOfRecords));
	t1.join();
	t2.join();
	t3.join();
}