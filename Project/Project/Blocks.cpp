#include "Blocks.h"

Blocks::Blocks(float x, float y, float width, float height)
{
	this->width = width;
	this->height = height;
	rectangles.setPosition(x, y);
	rectangles.setSize({ this->width,this->height });
	rectangles.setOrigin(width / 2, height / 2);

	this->texture.loadFromFile("Texture/blocks.png");
	this->rectangles.setTexture(&this->texture);
}

void Blocks::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->rectangles, state);
}

void Blocks::changeParam(float x, float y, float width, float height)
{
	this->width = width;
	this->height = height;
	rectangles.setPosition(x, y);
	rectangles.setSize({ this->width,this->height });
	rectangles.setOrigin(width / 2, height / 2);
}

float Blocks::left()
{
	return this->rectangles.getPosition().x - rectangles.getSize().x / 2.f;
}

float Blocks::right()
{
	return this->rectangles.getPosition().x + rectangles.getSize().x / 2.f;
}

float Blocks::up()
{
	return this->rectangles.getPosition().y - rectangles.getSize().y / 2.f;
}

float Blocks::down()
{
	return this->rectangles.getPosition().y + rectangles.getSize().y / 2.f;
}

sf::Vector2f Blocks::getPosition()
{
	return rectangles.getPosition();
}

bool Blocks::isDestroyed()
{
	return this->isDestroy;
}

void Blocks::destroy()
{
	this->isDestroy = true;
}