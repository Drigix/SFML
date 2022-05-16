#include "Textbox.h"

Textbox::Textbox(int size, sf::Color color, bool selected, sf::Vector2f position, sf::Font& font)
{
	this->textbox.setFont(font);
	this->textbox.setCharacterSize(size);
	this->textbox.setFillColor(color);
	this->isSelected = selected;
	this->textbox.setPosition(position);
	if (selected) {
		textbox.setString("_");
	}
	else
	{
		textbox.setString("");
	}
}

Textbox::Textbox(std::string name, int size, sf::Color color, sf::Vector2f position, sf::Font& font)
{
	this->textbox.setString(name);
	this->textbox.setFont(font);
	this->textbox.setCharacterSize(size);
	this->textbox.setFillColor(color);
	this->textbox.setPosition(position);
	this->isSelected = false;
}

void Textbox::setString(std::string str)
{
	this->textbox.setString(str);
}

void Textbox::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->textbox, state);
}

void Textbox::deleteLastChar()
{
	std::string text = ss.str();
	std::string newText = "";
	for (size_t i = 0; i < text.length()-1; i++)
	{
		newText += text[i];
	}
	ss.str("");
	ss << newText;
	textbox.setString(ss.str());
}

void Textbox::typedOn(sf::Event input, sf::RenderWindow*& window, std::vector<std::pair<int, std::string>>&cointainer,int points)
{
	if (isSelected)
	{
		int charTyped = input.text.unicode;
		if (charTyped < 128)
		{
			if (ss.str().length() <= 30)
			{
				inputText(charTyped,window,cointainer,points);
			}
			else if (ss.str().length() > 30 && charTyped == DELETE_KEY)
			{
				deleteLastChar();
			}
		}
	}
}

bool Textbox::checkNick()
{
	std::regex correctNick("^([A-Z a-z 0-9]){1,19}$");
	if (std::regex_match(ss.str(), correctNick))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Textbox::inputText(int charTyped, sf::RenderWindow*& window, std::vector<std::pair<int, std::string>>&cointainer,int points)
{
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY && isSaved == false)
	{
		ss << static_cast<char>(charTyped);
	}
	else if(charTyped==DELETE_KEY&& isSaved == false)
	{
		if (ss.str().length() > 0)
		{
			deleteLastChar();
		}
	}
	else if (charTyped == ENTER_KEY && isSaved==false)
	{
		if (checkNick())
		{
			if (!Game::checkScore(cointainer, points, ss.str()))
			{
				cointainer.push_back({ points, ss.str() });
				Game::saveScore(window, cointainer);
			}
			ss.str("");
			ss << "YOUR SCORE SAVED!";
			isSaved = true;
		}
		else
		{
			ss.str("");
			ss << "WRONG NAME, TRY AGAIN!";
			//Sleep(2000);
			ss.str("");
		}
	}
	else if (charTyped == ESCAPE_KEY)
	{
		std::cout << "escape";
	}
	textbox.setString(ss.str() + "_");
}