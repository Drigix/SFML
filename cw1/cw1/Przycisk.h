#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>

using namespace std;

enum button_states { button_Idle = 0, button_Hover, button_Pressed };

class Przycisk :public sf::Drawable
{
    short unsigned buttonState;

    sf::RectangleShape button_shape;
    sf::Font font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Przycisk(float x, float y, float width, float height, sf::Font font,string text,sf::Color idlecolor,sf::Color hoverColor,sf::Color activeColor);

    void render(sf::RenderTarget* target);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

    void update(sf::Vector2f mousePosition);
    const bool isPressed() const;
};

