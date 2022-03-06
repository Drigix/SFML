#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
class Pallete :public sf::Drawable
{
public:
	Pallete(float x, float y);

	
	void movePallete();

	float right();
	float left();
	float up();
	float down();

	sf::Vector2f getPositionOfPallete();

private:
	sf::RectangleShape rectangle;
	const float widthOfRectangle=80.0;
	const float hightOfRectangle=20.0;
	const float speedOfRectangle = 6.0;
	sf::Vector2f speed{ speedOfRectangle,0.0 };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

