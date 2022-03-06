#include "Paleta.h"

Pallete::Pallete(float x, float y)
{
	rectangle.setPosition(x, y);
	rectangle.setSize({ this->widthOfRectangle,this->hightOfRectangle });
	rectangle.setFillColor(sf::Color::White);
	rectangle.setOrigin(widthOfRectangle/2 , hightOfRectangle/2 );
}

void Pallete::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->rectangle, state);
}


void Pallete::movePallete()
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

float Pallete::left()
{
	return this->rectangle.getPosition().x - rectangle.getSize().x /2.f;
}

float Pallete::right()
{
	return this->rectangle.getPosition().x + rectangle.getSize().x / 2.f;
}

float Pallete::up()
{
	return this->rectangle.getPosition().y - rectangle.getSize().y / 2.f;
}

float Pallete::down()
{
	return this->rectangle.getPosition().y + rectangle.getSize().y / 2.f;
}

sf::Vector2f Pallete::getPositionOfPallete()
{
	return rectangle.getPosition();
}