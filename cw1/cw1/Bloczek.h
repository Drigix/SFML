#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Bloczek :public sf::Drawable
{
public:
	Bloczek(float x, float y, float w, float h);

	sf::Vector2f getPositionOfBlock();
	sf::Vector2f getSize();

	float right();
	float left();
	float up();
	float down();

	bool isDestroyed();
	void destroy();
private:
	sf::RectangleShape rectangles;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
	bool destroyed = false;
};

