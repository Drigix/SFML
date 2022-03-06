#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include<sstream>
#include<vector>
#include "Przycisk.h"
#include"Menu.h"



template<class T1,class T2> bool check(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.down() >= B.up() && A.up() <= B.down();
}

/*
bool checkTouch(Pallete& pallete1, Ball& ball1)
{
    if (!check(pallete1, ball1))
    {
        return false;
    }
    else
    {
        ball1.moveUp();

        if (ball1.getPositionOfBall().x < pallete1.getPositionOfPallete().x)
        {
            ball1.moveLeft();
        }
        else if (ball1.getPositionOfBall().x > pallete1.getPositionOfPallete().x)
        {
            ball1.moveRight();
        }
    }
}

bool checkTouch(Bloczek& block, Ball& ball1)
{
    if (!check(block, ball1))
    {
        return false;
    }
    block.destroy();
}
*/

/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    Ball ball1(400, 300);
    Pallete pallete1(400, 550);
    int blocksX=10, blocksY=4, blockWidth=60, blockHeight=20;
    window.setFramerateLimit(60);
    std::vector<Bloczek> blocks;
    for (int i = 0; i < blocksY; i++)
    {
        for (int j = 0; j < blocksX; j++)
        {
            blocks.emplace_back((j+1) * (blockWidth + 10), (i+2) * (blockHeight + 5),blockWidth,blockHeight);
        }
    }
    while (window.isOpen())
    {
        sf::Event event;
        window.clear(sf::Color::Black);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Font font;
        if (!font.loadFromFile("Fonts/Winter Insight.otf"))
        {
            throw("COULD NOT LOAD FONT!");
        }
        else
        {
            Przycisk play(330, 200, 100, 50, font, "PLAY", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            Przycisk records(330, 300, 100, 50, font, "RECORDS", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            Przycisk quit(330, 400, 100, 50, font, "QUIT", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            Przycisk back(330, 200, 100, 50, font, "BACK", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            sf::Vector2i mousePositionScreen = sf::Mouse::getPosition();
            sf::Vector2i mousePositionWindow = sf::Mouse::getPosition(window);
            sf::Vector2f mousePositionView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            play.update(mousePositionView);
            records.update(mousePositionView);
            quit.update(mousePositionView);
            window.draw(play);
            window.draw(records);
            window.draw(quit);
            if (play.isPressed()==true)
            {
                while (true)
                {
                    window.clear(sf::Color::Black);
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            window.close();
                    }
                    if (ball1.moveBall() == false)
                    {
                        window.clear(sf::Color::Black);
                        sf::Text text("GAME OVER!", font);
                        text.setCharacterSize(200);
                        text.setStyle(sf::Text::Bold);
                        text.setFillColor(sf::Color::Red);
                        text.setPosition(100, 200);
                        window.draw(text);
                    }
                    else
                    {
                        pallete1.movePallete();
                        checkTouch(pallete1, ball1);
                        window.draw(ball1);
                        window.draw(pallete1);
                        for (auto& Bloczek : blocks)
                        {
                            window.draw(Bloczek);
                        }
                    }
                    window.display();
                }
            }
            else if (quit.isPressed() == true)
            {
                window.close();
            }
            else if (records.isPressed() == true)
            {
                while (true)
                {
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                            window.close();
                    }
                    window.clear(sf::Color::Black);
                    string file = "records.txt";
                    map<string, int>contener;
                    Menu::loadRecords(file, contener);
                    for (auto& it : contener)
                    {
                        stringstream ss;
                        ss << "1." << it.first << " " << it.second;
                        string show = ss.str();
                        sf::Text text(show, font);
                        text.setCharacterSize(60);
                        text.setStyle(sf::Text::Bold);
                        text.setFillColor(sf::Color::Red);
                        text.setPosition(100, 200);
                        window.draw(text);
                    }
                    back.update(mousePositionView);
                    window.draw(back);
                    window.display();
                }
            }
        }
        window.display();
    }
    return 0;
}
*/

int main()
{
    Menu menu;
    menu.goToMenu();
    return 0;
}