#include "Game.h"

template<class T1, class T2> bool check(T1& A, T2& B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.down() >= B.up() && A.up() <= B.down();
}

bool Game::checkTouch(Platform& platform, Ball& ball)
{
    if (!check(platform, ball))
    {
        return false;
    }
    else
    {
        this->soundEffect2.playEffect();
        ball.moveUp();
        if (platform.getPosition().x > ball.getPosition().x)
        {
            ball.moveLeft();
        }
        else if (platform.getPosition().x < ball.getPosition().x)
        {
            ball.moveRight();
        }
    }
}

bool Game::checkTouch2(Ball& ball, Blocks& blocks)
{
    if (!check(ball, blocks))
    {
        return false;
    }
    blocks.destroy();
    addPoints();
    
    float hitsFromLeft(ball.right() - blocks.left());
    float hitsFromRight(blocks.right() - ball.left());
    float hitsFromTop(ball.down() - blocks.up());
    float hitsFromDown(blocks.down() - ball.up());

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

Game::Game(int width, int height, std::string name, sf::Font font)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), name);
    this->font = font;
}

Game::~Game()
{
    delete this->window;
}

bool Game::setSprite()
{
    this->sprite = texture.getSprite();
    return true;
}

sf::Sprite Game::getSprite()
{
    return this->sprite;
}

void Game::updateMousePosition()
{
    this->mousePositionView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

void Game::addBlocks(Blocks&blocks)
{
    float blocksX = 10, blocksY = 4, blockWidth = 70, blockHeight = 20;
    for (int i = 0; i < blocksY; i++)
    {
        for (int j = 0; j < blocksX; j++)
        {
            blocks.changeParam((j + 0.5) * (blockWidth + 10), (i + 1) * (blockHeight + 10), blockWidth, blockHeight);
            this->vectorOfBlocks.emplace_back(blocks);
        }
    }
}

void Game::printBlocks()
{
    for (auto& Block : this->vectorOfBlocks)
    {
        this->window->draw(Block);
    }
}

Textbox Game::printPoints()
{
    std::stringstream ss;
    ss << "Points:" << this->points;
    Textbox textPoints(ss.str(), 50, sf::Color::Red, { 620,545 }, this->font);
    return textPoints;
}

Textbox Game::printScore()
{
    std::stringstream ss;
    ss << "Your score:" << this->points;
    Textbox textPoints(ss.str(), 70, sf::Color::Red, { 240,180 }, this->font);
    return textPoints;
}

void Game::addPoints()
{
    this->points++;
}

void Game::removeBlocks()
{
    auto iterator = remove_if(begin(this->vectorOfBlocks), end(this->vectorOfBlocks), [](Blocks& block) {return block.isDestroyed(); });
    this->vectorOfBlocks.erase(iterator, end(this->vectorOfBlocks));
}

void Game::checkButtonClickAfterGame(Button& back, Button& quit)
{
    if (quit.isPressed())
    {
        this->window->close();
    }
    else if (back.isPressed())
    {
        this->backIsPressed = true;
    }
}

void Game::gameOver(sf::Event& event, Textbox& text2, Button& back, Button& quit)
{
    Textbox text("GAME OVER!", 100, sf::Color::Red, { 120,40 }, this->font);

    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Black);
    shape.setSize({ 600, 50 });
    shape.setPosition(80, 350);
    shape.setOutlineThickness(2);
    shape.setOutlineColor(sf::Color::White);

    updateMousePosition();
    back.update(this->mousePositionView);
    quit.update(this->mousePositionView);

    checkButtonClickAfterGame(back, quit);

    this->window->draw(this->sprite);
    this->window->draw(back);
    this->window->draw(quit);
    this->window->draw(shape);
    this->window->draw(text);
    this->window->draw(printScore());
    this->window->draw(text2);
}

bool Game::checkScore(std::vector<std::pair<int, std::string>>& cointainer, int points, std::string name)
{
    std::pair p = { points,name };
    for (int i = 0; i < cointainer.size(); i++)
    {
        if (cointainer[i] == p)
        {
            return true;
        }
    }
    return false;
}

void Game::saveScore(sf::RenderWindow*& window, std::vector<std::pair<int, std::string>>& cointainer)
{
    std::ofstream file("records.txt");
    if (file)
    {
        std::vector<std::pair<int, std::string>>::iterator it;
        for (it = cointainer.begin(); it != cointainer.end(); it++)
        {
            file << it->second << std::endl << it->first << std::endl;
        }
        file.close();
    }
}

void Game::update(Ball& ball, Platform& platform)
{
    this->window->draw(this->sprite);
    checkTouch(platform, ball);
    for (auto& block : vectorOfBlocks)
    {
        if (checkTouch2(ball, block))
        {
            break;
        }
    }
    removeBlocks();
    this->window->draw(ball);
    this->window->draw(platform);
    printBlocks();
    if (this->checkFreeze)
    {
        freezeTime(ball,platform);
        this->checkFreeze=false;
    }
    this->soundEffect.ifStop();
    this->window->draw(printPoints());
    ball.moveBall(this->soundEffect2);
    platform.movePlatform();
}

void Game::freezeTime(Ball& ball, Platform& platform)
{
    Textbox text("", 130, sf::Color::Red, { 360,250 }, this->font);
    for (int i = 3; i > 0; i--)
    {
        std::stringstream ss;
        ss << i;
        text.setString(ss.str());
        this->window->clear(sf::Color::Black);
        this->window->draw(this->sprite);
        this->window->draw(ball);
        this->window->draw(platform);
        printBlocks();
        this->window->draw(text);
        this->window->display();
        Sleep(1000);
    }
}

void Game::manageSound()
{
    this->soundEffect.setMusic();
    this->soundEffect2.setBuffer("Sound/GameOver-Sound.wav");
    this->soundEffect.playMusic();
}

void Game::turnUpVolume()
{
    this->soundEffect.turnUpVolume();
}

void Game::turnDownVolume()
{
    this->soundEffect.turnDownVolume();
}

Sound &Game::getSound()
{
    return this->soundEffect2;
}


void Game::gameLoop(Button&back,Button&quit)
{
    this->window->setFramerateLimit(60);
    Ball ball(400, 300, 10, 1);
    Platform platform(400, 540, 80, 20, 7);
    Blocks blocks(0, 0, 0, 0);
    Textbox text2(40, sf::Color::Red, true, { 100,350 }, this->font);
    while (this->window->isOpen())
    {
        this->window->clear(sf::Color::Black);
        sf::Event event;
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window->close();
            }
            else if (event.type == sf::Event::TextEntered)
            {
                text2.typedOn(event, this->window,this->vectorOfRecords,this->points);
            }
        }
        if (this->backIsPressed)
        {
            this->backIsPressed = false;
            this->checkFreeze = true;
            this->points = 0;
            this->vectorOfBlocks.clear();
            break;
        }
        if (this->vectorOfBlocks.empty())
        {
            addBlocks(blocks);
            ball.changeSpeed();
        }
        if (ball.moveBall(this->soundEffect2) == false)
        {
            ball.stopBall();
            gameOver(event, text2,back,quit);
        }
        else
        {
            update(ball, platform);
        }
        this->window->display();
    }

}