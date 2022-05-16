#pragma once
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Position.h"
#include"Sound.h"

class Ball: public Draw,public Position
{
	sf::CircleShape circle;
	float radiusOfBall;
	float speedOfBall;
	sf::Vector2f speed;
	sf::Texture texture;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
	Ball(float x , float y, float radiusOfBall, float speedOfBall);

	bool moveBall(Sound&soundEffect);

	float right();
	float left();
	float up();
	float down();

	sf::Vector2f getPosition();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void changeSpeed();
	void stopBall();
};

