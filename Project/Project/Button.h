    #pragma once
#include"Draw.h"

enum buttonState {buttonIdle=0,buttonHover,buttonPressed};

class Button:public Draw
{
    short unsigned buttonState;

    sf::RectangleShape buttonShape;
    sf::Font font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
public:
    Button(float x, float y, float width, float height,
        sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

    void update(sf::Vector2f mousePosition);
    bool isPressed();
};

