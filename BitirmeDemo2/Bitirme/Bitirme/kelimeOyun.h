#pragma once
#include "SFML/Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 9


class kelimeOyun
{
public:
	kelimeOyun();
	~kelimeOyun();
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font font1;
	sf::Text kelime[MAX_NUMBER_OF_ITEMS];

};

