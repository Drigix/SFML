#pragma once
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Position.h"

class Platform : public Draw
{
	sf::RectangleShape rectangle;
	float widthOfRectangle;
	float hightOfRectangle;
	float speedOfRectangle;
	sf::Vector2f speed;
	sf::Texture texture;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

public:
	Platform(float x, float y,
		float widthOfRectangle, float highOfRectangle,
		float speedOfRectangle);

	void movePlatform();

	float right();
	float left();
	float up();
	float down();

	sf::Vector2f getPosition();
};

