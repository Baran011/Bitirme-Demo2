#pragma once
#include "Button.h"

Button::Button() : parent(0)
{
	//font.loadFromFile("arial.ttf");
	//text.setFont(font);
	//text.setCharacterSize(20);
	//text.setFillColor(sf::Color::Black);
	//text.setString("arif");
}

void Button::setParent(sf::RenderWindow* parent) {              ///////////////////// kullanýlacak yer
	this->parent = parent;
}
void Button::draw(sf::RenderTarget& target, sf::RenderStates)const {
	target.draw(shape);
	//target.draw(text);
}

void Button::setSize(sf::Vector2f size) {
	shape.setSize(size);
}


void Button::setPosition(sf::Vector2f pos) {
	shape.setPosition(pos);
}
void Button::setFillColor(sf::Color color) {
	shape.setFillColor(color);
}

void Button::setTexture(sf::Texture &texture) {
	shape.setTexture(&texture);
}

bool Button::isMouseOver()const {
	return parent && shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*parent)));
}

bool Button::isMouseClick(sf::Mouse::Button value)const {
	if (isMouseOver()) {
		if (parent)
			return sf::Mouse::isButtonPressed(value);
	}
	return false;
}