#include "Bloczek.h"

Bloczek::Bloczek(float x, float y, float w, float h)
{
	rectangles.setPosition(x, y);
	rectangles.setSize({ w,h });
	rectangles.setFillColor(sf::Color::Red);
	rectangles.setOrigin(w / 2, h / 2);
}

void Bloczek::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->rectangles, state);
}

sf::Vector2f Bloczek::getPositionOfBlock()
{
	return rectangles.getPosition();
}

sf::Vector2f Bloczek::getSize()
{
	return rectangles.getSize();
}

float Bloczek::left()
{
	return this->rectangles.getPosition().x - rectangles.getSize().x / 2.f;
}

float Bloczek::right()
{
	return this->rectangles.getPosition().x + rectangles.getSize().x / 2.f;
}

float Bloczek::up()
{
	return this->rectangles.getPosition().y - rectangles.getSize().y / 2.f;
}

float Bloczek::down()
{
	return this->rectangles.getPosition().y + rectangles.getSize().y / 2.f;
}

bool Bloczek::isDestroyed()
{
	return this->destroyed;
}

void Bloczek::destroy()
{
	this->destroyed = true;
}