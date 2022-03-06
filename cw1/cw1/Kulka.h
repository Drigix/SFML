#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
class Ball :public sf::Drawable
{
public:
    Ball(double x, double y);

    bool moveBall();
    void changeSpeed(Ball& object_ball);

    float right();
    float left();
    float up();
    float down();

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    sf::Vector2f getPositionOfBall();

private:
    sf::CircleShape circle;
    const float radiusOfBall{ 10.0 };
    float speedOfBall{ 3.0 };
    sf::Vector2f speed  { speedOfBall, speedOfBall };
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};

