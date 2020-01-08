#include "Item.h"
Item::Item(sf::Vector2f size) : 
		match(NULL), 
		isDraw(true), 
		sf::RectangleShape(size)
{	}

bool Item::getIsDraw()const { return isDraw; }

void Item::setIsDraw(bool isDraw) { this->isDraw = isDraw; }

const Item* Item::getMatch()const { return match; }

void Item::setMatch(Item* match) { this->match = match; }

bool Item::checkMatch(Item* item)const { return match == item; }
