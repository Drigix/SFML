#include "Platform.h"


Platform::Platform(float x, float y, float widthOfRectangle,float highOfRectangle,float speedOfRectangle)
{
	this->widthOfRectangle = widthOfRectangle;
	this->hightOfRectangle = highOfRectangle;
	this->speedOfRectangle = speedOfRectangle;
	this->speed = { speedOfRectangle,0 };
	rectangle.setPosition(x, y);
	rectangle.setSize({ this->widthOfRectangle,this->hightOfRectangle });
	rectangle.setOrigin(widthOfRectangle / 2, hightOfRectangle / 2);

	this->texture.loadFromFile("Texture/platform.png");
	this->rectangle.setTexture(&this->texture);
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->rectangle, state);
}

void Platform::movePlatform()
{
	rectangle.move(this->speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->left() > 0)
	{
		speed.x = -speedOfRectangle;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->right() < 800)
	{
		speed.x = speedOfRectangle;
	}
	else
	{
		speed.x = 0;
	}
}

float Platform::left()
{
	return this->rectangle.getPosition().x - rectangle.getSize().x / 2.f;
}

float Platform::right()
{
	return this->rectangle.getPosition().x + rectangle.getSize().x / 2.f;
}

float Platform::up()
{
	return this->rectangle.getPosition().y - rectangle.getSize().y / 2.f;
}

float Platform::down()
{
	return this->rectangle.getPosition().y + rectangle.getSize().y / 2.f;
}

sf::Vector2f Platform::getPosition()
{
	return this->rectangle.getPosition();
}