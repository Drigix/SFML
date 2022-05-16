#include "Sound.h"

void Sound::setMusic()
{
	this->music.openFromFile(this->vectorOfSongs[numberOfSong]);
}

void Sound::setBuffer(std::string file)
{
	this->buffer.loadFromFile(file);
}

sf::SoundBuffer Sound::getBuffer()
{
	return this->buffer;
}

void Sound::playMusic()
{
	this->music.setVolume(20);
	this->music.play();
}

void Sound::playEffect()
{
	this->soundEffect.setBuffer(this->buffer);
	this->soundEffect.setVolume(30);
	this->soundEffect.play();
}

void Sound::turnUpVolume()
{
	float volume= this->music.getVolume() /0.99f;
	this->music.setVolume(volume);
}

void Sound::turnDownVolume()
{
	float volume = this->music.getVolume() *0.99f;
	this->music.setVolume(volume);
}

void Sound::changeSong(Button& leftSong, Button& rightSong)
{
	if (leftSong.isPressed())
	{
		if (numberOfSong == 0)
		{
			numberOfSong = vectorOfSongs.size()-1;
		}
		else
		{
			numberOfSong--;
		}
		setMusic();
		playMusic();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	else if (rightSong.isPressed())
	{
		if (numberOfSong == vectorOfSongs.size()-1)
		{
			numberOfSong = 0;
		}
		else
		{
			numberOfSong++;
		}
		setMusic();
		playMusic();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Sound::runThreads(Button& leftSong, Button& rightSong)
{
	std::thread t1(&Sound::changeSong, this, std::ref(leftSong), std::ref(rightSong));
	t1.join();
}

void Sound::ifStop()
{
	sf::SoundSource::Status status=this->music.getStatus();
	if (status!=2) 
	{
		if (numberOfSong == vectorOfSongs.size() - 1)
		{
			numberOfSong = 0;
		}
		else
		{
			numberOfSong++;
		}
		setMusic();
		playMusic();
	}
}