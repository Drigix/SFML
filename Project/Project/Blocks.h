#pragma once
#include <SFML/Graphics.hpp>
#include "Draw.h"
#include "Position.h"

class Blocks: public Draw, public Position
{
	sf::RectangleShape rectangles;
	sf::Texture texture;

	float width;
	float height;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

	bool isDestroy = false;
public:
	Blocks(float x, float y, float width, float height);

	void changeParam(float x, float y, float width, float height);

	float right();
	float left();
	float up();
	float down();

	sf::Vector2f getPosition();

	bool isDestroyed();
	void destroy();
};

