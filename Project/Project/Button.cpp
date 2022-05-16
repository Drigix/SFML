#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = buttonIdle;

    this->buttonShape.setPosition(sf::Vector2f(x, y));
    this->buttonShape.setSize(sf::Vector2f(width, height));

    this->font = font;
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Red);
    this->text.setCharacterSize(30);
    this->text.setPosition(this->buttonShape.getPosition().x + (this->buttonShape.getGlobalBounds().width / 2.f) - (this->text.getGlobalBounds().width / 2.f),
        this->buttonShape.getPosition().y + (this->buttonShape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f));

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->buttonShape.setFillColor(this->idleColor);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->buttonShape, state);
    target.draw(this->text, state);
}

bool Button::isPressed()
{
    if (this->buttonState == buttonPressed)
    {
        return true;
    }
    return false;
}

void Button::update(sf::Vector2f mousePosition)
{
    this->buttonState = buttonIdle;
    if (this->buttonShape.getGlobalBounds().contains(mousePosition))
    {
        this->buttonState = buttonHover;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = buttonPressed;
        }
    }

    switch (this->buttonState)
    {
    case buttonIdle:
        this->buttonShape.setFillColor(this->idleColor);
        break;
    case buttonHover:
        this->buttonShape.setFillColor(this->hoverColor);
        break;
    case buttonPressed:
        this->buttonShape.setFillColor(this->activeColor);
        break;

    default:
        this->buttonShape.setFillColor(sf::Color::Red);
        break;
    }
}