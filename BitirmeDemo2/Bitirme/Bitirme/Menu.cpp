#include "Menu.h"
#include<iostream>


Menu::Menu(float width, float height)
{

	
	if(!font1.loadFromFile("arial.ttf"))
	{
		std::cout << "font yüklenemedi" << std::endl;
	}
	
	
	menu[0].setFont(font1);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Oyunlar");
	menu[0].setPosition(sf::Vector2f(100, height / (MAX_NUMBER_OF_ITEMS +1) * 1));
	menu[0].setCharacterSize(50);
	menu[0].setStyle(sf::Text::Bold | sf::Text::Underlined);

	menu[1].setFont(font1);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Sohbete Basla");
	menu[1].setPosition(sf::Vector2f(100, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[1].setCharacterSize(50);
	menu[1].setStyle(sf::Text::Bold | sf::Text::Underlined);

	menu[2].setFont(font1);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Ayarlar");
	menu[2].setPosition(sf::Vector2f(100, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu[2].setCharacterSize(50);
	menu[2].setStyle(sf::Text::Bold | sf::Text::Underlined);

	menu[3].setFont(font1);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Kapat");
	menu[3].setPosition(sf::Vector2f(100, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));
	menu[3].setCharacterSize(50);
	menu[3].setStyle(sf::Text::Bold | sf::Text::Underlined);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}