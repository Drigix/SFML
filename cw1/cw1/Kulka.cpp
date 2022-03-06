#include "Kulka.h"
Ball::Ball(double x, double y)
{
	circle.setPosition(x, y);
	circle.setRadius(this->radiusOfBall);
	circle.setFillColor(sf::Color::Green);
	circle.setOrigin(this->radiusOfBall, this->radiusOfBall);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->circle, state);
}



bool Ball::moveBall()
{
	circle.move(this->speed);
	if (this->left() < 0)
	{
		speed.x = speedOfBall;
	}
	else if (this->right() > 800)
	{
		speed.x = -speedOfBall;
	}
	if (this->up() < 0)
	{
		speed.y = speedOfBall;
	}
	else if (this->down() > 600)
	{
		return false;
	}
}

void Ball::changeSpeed(Ball& object_ball)
{
	object_ball.speedOfBall ++;
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

 void Ball::moveDown()
 {
	 this->speed.y = speedOfBall;
 }

 void Ball::moveUp()
 {
	 this->speed.y = -speedOfBall;
 }

 void Ball::moveRight()
 {
	 this->speed.x = speedOfBall;
 }

 void Ball::moveLeft()
 {
	 this->speed.x = -speedOfBall;
 }

 sf::Vector2f Ball::getPositionOfBall()
 {
	 return circle.getPosition();
 }