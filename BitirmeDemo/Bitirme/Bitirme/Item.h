#pragma once
#include <SFML/Graphics.hpp>

class Item :public sf::RectangleShape {
	bool isDraw;
	Item* match;
public:
	Item(sf::Vector2f size = sf::Vector2f(0, 0));
	bool getIsDraw()const;
	void setIsDraw(bool isDraw);
	const Item* getMatch()const;
	void setMatch(Item* match);
	template<typename Vec>
	bool isOnPos(Vec pos)const;
	bool checkMatch(Item* item)const;
};

template<typename Vec>
bool Item::isOnPos(Vec pos)const
{
	return
		isDraw &&
		sf::RectangleShape::getGlobalBounds().contains(static_cast<sf::Vector2f>(pos));
}