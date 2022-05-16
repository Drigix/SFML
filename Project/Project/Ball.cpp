#include "Ball.h"
#include<iostream>


Ball::Ball(float x, float y, float radiusOfBall, float speedOfBall)
{
	this->radiusOfBall = radiusOfBall;
	this->speedOfBall = speedOfBall;
	this->speed = { this->speedOfBall,this->speedOfBall };
	this->circle.setPosition(x, y);
	this->circle.setRadius(this->radiusOfBall);
	this->circle.setOrigin(this->radiusOfBall, this->radiusOfBall);

	this->texture.loadFromFile("Texture/ball.png");
	this->circle.setTexture(&this->texture);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->circle, state);
}

bool Ball::moveBall(Sound& soundEffect)
{
	circle.move(this->speed);
	if (this->left() < 0)
	{
		soundEffect.playEffect();
		this->speed.x = speedOfBall;
	}
	else if (this->right() > 800)
	{
		soundEffect.playEffect();
		this->speed.x = -speedOfBall;
	}
	if (this->up() < 0)
	{
		soundEffect.playEffect();
		this->speed.y = speedOfBall;
	}
	else if (this->down() > 600)
	{
		return false;
	}
}

float Ball::left()
{
	return this->circle.getPosition().x - circle.getRadius();
}

float Ball::right()
{
	return this->circle.getPosition().x + circle.getRadius();
}

float Ball::down()
{
	return this->circle.getPosition().y + circle.getRadius();
}

float Ball::up()
{
	return this->circle.getPosition().y - circle.getRadius();
}

sf::Vector2f Ball::getPosition()
{
	return this->circle.getPosition();
}

void Ball::moveLeft()
{
	this->speed.x = -speedOfBall;
}

void Ball::moveRight()
{
	this->speed.x = speedOfBall;
}

void Ball::moveUp()
{
	this->speed.y = -speedOfBall;
}

void Ball::moveDown()
{
	this->speed.y = speedOfBall;
}

void Ball::changeSpeed()
{
	this->speedOfBall++;
}

void Ball::stopBall()
{
	this->speedOfBall = 0;
}