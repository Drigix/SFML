#pragma once
#include <SFML/Graphics.hpp>


class Draw : public sf::Drawable
{
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state)const override=0 ;
};