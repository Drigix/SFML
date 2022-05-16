#pragma once

class Position
{
public:
    virtual float right()=0;
    virtual float left()=0;
    virtual float up()=0;
    virtual float down()=0;

    virtual sf::Vector2f getPosition() = 0;
};