#include "Menu.h"

void Menu::showRecords()
{
	Textbox textRecords("Records", 100, sf::Color::Red, { 220,-10 }, this->font);
	int number = 1;
	float  positionX = 280, positionY = 100;

	std::ranges::sort(this->vectorOfRecords, std::ranges::greater{});

	this->window->draw(this->sprite);

	for (int i = 0; i < 10; i++)
	{
		std::stringstream ss;
		std::pair<int, std::string> p = this->vectorOfRecords[i];
		ss << number << ". " << p.second << "  " << p.first;
		std::string show = ss.str();
		Textbox text(ss.str(), 40, sf::Color::Red, { positionX,positionY }, this->font);
		this->window->draw(text);
		this->window->draw(textRecords);
		number++;
		positionY += 40;
	}
}

void Menu::goToRecords(Button&back)
{
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
		}
		showRecords();
		updateMousePosition();
		back.update(this->mousePositionView);
		this->window->draw(back);
		if (back.isPressed() == true)
		{
			break;
		}
		this->window->display();
	}
}

void Menu::updateMusic(Button& minusVolume, Button& plusVolume)
{
	if (minusVolume.isPressed() == true)
	{
		turnDownVolume();
	}
	else if (plusVolume.isPressed() == true)
	{
		turnUpVolume();
	}
}


void Menu::goToOptions(Button& back)
{
	Textbox textMusicVolume("Music Volume", 65, sf::Color::Red, { 210,10 }, this->font);
	Textbox textMusicSong("Music Song", 65, sf::Color::Red, { 240,160 }, this->font);
	Textbox textSetBackground("Background Art", 65, sf::Color::Red, { 180,320 }, this->font);
	Button minusVolume(280, 100, 50, 50, this->font, "-", sf::Color(150, 150, 150, 200), sf::Color(70, 70, 70, 255), sf::Color(20, 20, 20, 200));
	Button plusVolume(380, 100, 50, 50, this->font, "+", sf::Color(150, 150, 150, 200), sf::Color(70, 70, 70, 255), sf::Color(20, 20, 20, 200));
	Button leftSong(280, 260, 50, 50, this->font, "<", sf::Color(150, 150, 150, 200), sf::Color(70, 70, 70, 255), sf::Color(20, 20, 20, 200));
	Button rightSong(380, 260, 50, 50, this->font, ">", sf::Color(150, 150, 150, 200), sf::Color(70, 70, 70, 255), sf::Color(20, 20, 20, 200));
	Button backgroundLeft(260, 430, 100, 50, this->font, "<", sf::Color(150, 150, 150, 200), sf::Color(70, 70, 70, 255), sf::Color(20, 20, 20, 200));
	Button backgroundRight(380, 430, 100, 50, this->font, ">", sf::Color(150, 150, 150, 200), sf::Color(70, 70, 70, 255), sf::Color(20, 20, 20, 200));

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
		}
		updateMousePosition();
		minusVolume.update(this->mousePositionView);
		plusVolume.update(this->mousePositionView);
		leftSong.update(this->mousePositionView);
		rightSong.update(this->mousePositionView);
		backgroundLeft.update(this->mousePositionView);
		backgroundRight.update(this->mousePositionView);
		back.update(this->mousePositionView);
		updateMusic(minusVolume, plusVolume);
		this->soundEffect.runThreads(leftSong, rightSong);
		this->texture.runThreads(backgroundLeft, backgroundRight);
		this->window->draw(getSprite());
		this->window->draw(textMusicVolume);
		this->window->draw(textMusicSong);
		this->window->draw(textSetBackground);
		this->window->draw(minusVolume);
		this->window->draw(plusVolume);
		this->window->draw(leftSong);
		this->window->draw(rightSong);
		this->window->draw(backgroundLeft);
		this->window->draw(backgroundRight);
		this->window->draw(back);
		if (back.isPressed() == true)
		{
			break;
		}
		this->window->display();
	}
}

void Menu::checkButtonClick(Button& play, Button& records, Button& quit,Button&back, Button& backGame, Button& quitGame, Button& options)
{
	if (play.isPressed() == true)
	{
		while (true)
		{
			gameLoop(backGame,quitGame);
			break;
		}
	}
	else if (records.isPressed() == true)
	{
		while (true)
		{
			goToRecords(back);
			break;
		}
	}
	else if (options.isPressed() == true)
	{
		while (true)
		{
			goToOptions(back);
			break;
		}
	}
	else if (quit.isPressed() == true)
	{
		window->close();
	}
}

void Menu::update(Button& play, Button& records, Button& quit, Textbox& textArcanoid,Button&back, Button&backGame,Button&quitGame, Button& options)
{

	updateMousePosition();
	play.update(this->mousePositionView);
	records.update(this->mousePositionView);
	options.update(this->mousePositionView);
	quit.update(this->mousePositionView);

	this->window->draw(getSprite());
	this->window->draw(textArcanoid);
	this->window->draw(play);
	this->window->draw(records);
	this->window->draw(options);
	this->window->draw(quit);
	checkButtonClick(play, records, quit,back,backGame,quitGame,options);

}

void Menu::goToMenu()
{
	Textbox textArcanoid("Arcanoid", 100, sf::Color::Red, { 220,40 }, this->font);
	Button play(330, 160, 100, 50, this->font, "PLAY", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	Button records(330, 260, 110, 50, this->font, "RECORDS", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	Button options(330, 360, 100, 50, this->font, "OPTIONS", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	Button quit(330, 460, 100, 50, this->font, "QUIT", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	Button back(330, 520, 100, 50, this->font, "BACK", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	Button backGame(230, 530, 100, 50, this->font, "BACK", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	Button quitGame(430, 530, 100, 50, this->font, "QUIT", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	File file;
	file.runAllThreads(this->texture.vectorTextureOfBackground,this->soundEffect.vectorOfSongs,this->vectorOfRecords);
	texture.setTexture();
	texture.setSprite();
	manageSound();
	if (setSprite() == true)
	{
		while (this->window->isOpen())
		{
			sf::Event event;
			while (this->window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					this->window->close();
				}
				this->soundEffect.ifStop();

				this->window->clear(sf::Color::Black);

				update(play, records, quit, textArcanoid, back, backGame,quitGame,options);

				this->window->display();
			}
		}
	}
}
