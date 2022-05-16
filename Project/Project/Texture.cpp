#include "Texture.h"


void Texture::setTexture()
{
	this->texture.loadFromFile(vectorTextureOfBackground[numberOfTexture]);
}

sf::Texture Texture::getTexture()
{
	return this->texture;
}

void Texture::setSprite()
{
	this->sprite.setTexture(this->texture);
}

sf::Sprite Texture::getSprite()
{
	return this->sprite;
}

void Texture::changeTexture(Button& leftTexture, Button& rightTexture)
{
	if (leftTexture.isPressed())
	{
		if (numberOfTexture == 0)
		{
			numberOfTexture = vectorTextureOfBackground.size() - 1;
		}
		else
		{
			numberOfTexture--;
		}
		setTexture();
		setSprite();
	}
	else if (rightTexture.isPressed())
	{
		if (numberOfTexture == vectorTextureOfBackground.size() - 1)
		{
			numberOfTexture = 0;
		}
		else
		{
			numberOfTexture++;
		}
		setTexture();
		setSprite();
	}
}

void Texture::changeBackgroud(Button& leftTexture, Button& rightTexture)
{
	if (leftTexture.isPressed())
	{
		if (this->numberOfTexture == 0)
		{
			this->numberOfTexture = this->vectorTextureOfBackground.size() - 1;
		}
		else
		{
			this->numberOfTexture--;
		}
		setTexture();
		setSprite();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	else if (rightTexture.isPressed())
	{
		if (this->numberOfTexture == this->vectorTextureOfBackground.size() - 1)
		{
			this->numberOfTexture = 0;
		}
		else
		{
			this->numberOfTexture++;
		}
		setTexture();
		setSprite();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}

void Texture::runThreads(Button& leftTexture, Button& rightTexture)
{
	std::thread t1(&Texture::changeBackgroud, this, std::ref(leftTexture), std::ref(rightTexture));
	t1.join();
}