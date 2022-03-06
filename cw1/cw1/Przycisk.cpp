#include "Przycisk.h"

Przycisk::Przycisk(float x, float y, float width, float height, sf::Font font, string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = button_Idle;

    button_shape.setPosition(sf::Vector2f(x, y));
    button_shape.setSize(sf::Vector2f( width, height ));

    this->font = font;
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Blue);
    this->text.setCharacterSize(30);
    this->text.setPosition(this->button_shape.getPosition().x +(this->button_shape.getGlobalBounds().width/2.f)- (this->text.getGlobalBounds().width / 2.f), 
        this->button_shape.getPosition().y + (this->button_shape.getGlobalBounds().height / 2.f) - (this->text.getGlobalBounds().height / 2.f));

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->button_shape.setFillColor(this->idleColor);
}

void Przycisk::render(sf::RenderTarget* target)
{
    target->draw(this->button_shape);
}

void Przycisk::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->button_shape, state);
    target.draw(this->text, state);
}

const bool Przycisk::isPressed() const
{
    if (this->buttonState == button_Pressed)
    {
        return true;
    }
    return false;
}

void Przycisk::update(sf::Vector2f mousePosition)
{
    this->buttonState = button_Idle;
    if (this->button_shape.getGlobalBounds().contains(mousePosition))
    {
        this->buttonState = button_Hover;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->buttonState = button_Pressed;
        }
    }

    switch (this->buttonState)
    {
    case button_Idle:
        this->button_shape.setFillColor(this->idleColor);
        break;
    case button_Hover:
        this->button_shape.setFillColor(this->hoverColor);
        break;
    case button_Pressed:
        this->button_shape.setFillColor(this->activeColor);
        break;

    default:
        this->button_shape.setFillColor(sf::Color::Red);
        break;
    }
}

