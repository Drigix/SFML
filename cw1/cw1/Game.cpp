#include "Game.h"

template<class T1, class T2> bool check(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.down() >= B.up() && A.up() <= B.down();
}

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

bool checkTouch(Bloczek& block, Ball& ball, Game&game_object)
{
    if (!check(block, ball))
    {
        return false;
    }
    block.destroy();
    game_object.addPoint(game_object);
    float hitsFromLeft(ball.right() - block.left());
    float hitsFromRight(block.right() - ball.left());
    float hitsFromTop(ball.down() - block.up());
    float hitsFromDown(block.down() - ball.up());

    bool ballFromLeft(hitsFromLeft < hitsFromRight);
    bool ballFromTop(hitsFromTop < hitsFromDown);

    float minX(ballFromLeft ? hitsFromLeft : hitsFromRight);
    float minY(ballFromTop ? hitsFromTop : hitsFromDown);
    if (minX < minY)
    {
        ballFromLeft ? ball.moveLeft() : ball.moveRight();
    }
    else
    {
        ballFromTop ? ball.moveUp() : ball.moveDown();
    }
}

void Game::printGameOver(sf::RenderWindow*& window,sf::Text& text)
{
    text.setCharacterSize(100);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition(100, 200);
    window->draw(text);
}

void Game::addBlocks(Game& object)
{
    int blocksX = 10, blocksY = 4, blockWidth = 60, blockHeight = 20;
    for (int i = 0; i < blocksY; i++)
    {
        for (int j = 0; j < blocksX; j++)
        {
            object.contener2.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
        }
    }
}

void Game::removeBlocks(Game& game_object)
{
    auto iterator = remove_if(begin(game_object.contener2), end(game_object.contener2), [](Bloczek& block) {return block.isDestroyed(); });
    game_object.contener2.erase(iterator, end(game_object.contener2));
}

void Game::printBlocks(sf::RenderWindow*& window, Game game_object)
{
    for (auto& Bloczek : game_object.contener2)
    {
        window->draw(Bloczek);
    }
}

void Game::printPoints(sf::RenderWindow*& window,sf::Font font,Game game_object)
{
    stringstream ss;
    ss << "Points: " << game_object.points;
    string show = ss.str();
    sf::Text text(show, font);
    text.setCharacterSize(50);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition(600, 530);
    window->draw(text);
}

void Game::addPoint(Game&game_object)
{
    game_object.points++;
}

void Game::gameOver(sf::RenderWindow*&window,sf::Font font,sf::Event& event,vector<string>&inputFromPlayer)
{
    sf::String playerInput;
    sf::Text text("GAME OVER!", font);
    int positionX = 100, positionY = 400;
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128)
        {
            playerInput += event.text.unicode;
            if (event.text.unicode != 8)
            {
                inputFromPlayer.push_back(playerInput);
            }
            else
            {
                inputFromPlayer.pop_back();
            }
        }
    }
    printGameOver(window, text);
    for (auto& it : inputFromPlayer)
    {
        sf::Text text(it, font);
        text.setPosition(positionX,positionY);
        positionX += 10;
        window->draw(text);
    }
}

void Game::gameLoop(sf::RenderWindow*& window,Game&game_object,sf::Font font,Menu menu_object)
{
    Ball ball(400, 300);
    Pallete pallete(400, 550);
    vector<string> inputFromPlayer;
    while (true)
    {
        window->clear(sf::Color::Black);
        sf::Event event;
        sf::String playerInput;
        window->draw(menu_object.getSprite(menu_object));
        if (game_object.contener2.empty())
        {
            game_object.addBlocks(game_object);
            ball.changeSpeed(ball);
        }
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        if (ball.moveBall() == false)
        {
           gameOver(window, menu_object.getFont(menu_object), event, inputFromPlayer);
        }
        else
        {
            pallete.movePallete();
            checkTouch(pallete, ball);
            for (auto& block : game_object.contener2)
            {
                if (checkTouch(block, ball,game_object))
                {
                    break;
                }
            }
            game_object.removeBlocks(game_object);
            window->draw(ball);
            window->draw(pallete);
            game_object.printBlocks(window, game_object);
            game_object.printPoints(window, menu_object.getFont(menu_object), game_object);
        }
        window->display();
    }
}