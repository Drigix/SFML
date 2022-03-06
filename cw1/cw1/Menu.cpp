#include "Menu.h"

 
void Menu::loadRecords(string& file,map<int,string>&contener)
{
    ifstream read(file);
    if (read)
    {
        string nick;
        int points;
        while (read)
        {
            getline(read, nick);
            read >> points;
            read.ignore(numeric_limits<streamsize>::max(), '\n');
            contener.emplace(points, nick);
        }
        read.close();
    }
}

bool Menu::loadFont()
{
    if (!this->font.loadFromFile("Fonts/!!! Handwritingg _3.ttf"))
    {
        return false;
    }
    return true;
}

sf::Font Menu::getFont(Menu menu_object)
{
    return menu_object.font;
}

bool Menu::loadTexture()
{
    if (!this->texture.loadFromFile("art.jpg"))
    {
        cout << "Could not load enemy texture";
        return false;
    }
    return true;
}

void Menu::setSprite()
{
    this->enemySprite.setTexture(this->texture);
}

sf::Sprite Menu::getSprite(Menu menu_object)
{
    return menu_object.enemySprite;
}

void Menu::udpadeMousePosition(sf::RenderWindow* window)
{
    this->mousePositionView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

void Menu::showRecords(sf::RenderWindow*& window, map<int, string>& contener,Menu menu)
{
    int number = 10, positionX = 100, positionY = 480;
    sf::Font font=menu.font;
    for (auto& it : contener)
    {
        stringstream ss;
        ss << number<<". "<<it.second << "  " << it.first;
        string show = ss.str();
        sf::Text text(show, font);
        text.setCharacterSize(60);
        text.setStyle(sf::Text::Bold);
        text.setFillColor(sf::Color::Red);
        text.setPosition(positionX, positionY);
        window->draw(text);
        number--;
        positionY -= 50;
    }
}

bool Menu::goToRecords(sf::RenderWindow*& window,Przycisk back,Menu menu, map<int, string>& contener)
{
    while (true)
    {
        window->clear(sf::Color::Black);
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        window->draw(menu.enemySprite);
        showRecords(window, contener, menu);
        menu.udpadeMousePosition(window);
        back.update(menu.mousePositionView);
        window->draw(back);
        if (back.isPressed() == true)
        {
            return false;
        }
        window->display();
   }
}

void Menu::checkButtonClick(sf::RenderWindow*& window,Menu menu,Game&game_object,Przycisk play, Przycisk records, Przycisk quit, Przycisk back)
{
    Game game;
    if (play.isPressed() == true)
    {
        while (true)
        {
            game.gameLoop(window,game_object,menu.font,menu);
        }
    }
    else if (records.isPressed() == true)
    {
        string file = "records.txt";
        map<int, string> contener;
        loadRecords(file, contener);
        while (true)
        {
            goToRecords(window, back, menu,contener);
            if (goToRecords(window, back, menu,contener) == false)
            {
                break;
            }
        }
    }
    else if (quit.isPressed() == true)
    {
        window->close();
    }
}

void Menu::goToMenu()
{
    Menu menu;
    Game object;
    int windowHeight = 600, windowWidth = 800;
    sf::RenderWindow* window= new sf::RenderWindow(sf::VideoMode(windowWidth,windowHeight),"xd");
    window->setFramerateLimit(60);
    object.addBlocks(object);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }
        window->clear(sf::Color::Black);
        if (menu.loadFont() == true && menu.loadTexture()==true)
        {
            window->clear(sf::Color::Black);
            menu.setSprite();
            Przycisk play(330, 200, 100, 50, menu.font, "PLAY", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            Przycisk records(330, 300, 100, 50, menu.font, "RECORDS", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            Przycisk quit(330, 400, 100, 50, menu.font, "QUIT", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            Przycisk back(550, 400, 100, 50, menu.font, "BACK", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
            menu.udpadeMousePosition(window);
            play.update(menu.mousePositionView);
            records.update(menu.mousePositionView);
            quit.update(menu.mousePositionView);
            window->draw(menu.enemySprite);
            window->draw(play);
            window->draw(records);
            window->draw(quit);
            checkButtonClick(window,menu,object, play, records, quit, back);
        }
        window->display();
    }
}

