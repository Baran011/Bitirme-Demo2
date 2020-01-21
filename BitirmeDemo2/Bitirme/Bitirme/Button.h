#pragma once
#include <SFML/Graphics.hpp>


class Button :public sf::Drawable
{
	sf::RenderWindow* parent;
	sf::RectangleShape shape;
	//sf::Text text;
	//sf::Font font;
public:
	Button();
	void setParent(sf::RenderWindow* parent);
	void draw(sf::RenderTarget& target, sf::RenderStates)const;
	void setSize(sf::Vector2f size);
	void setPosition(sf::Vector2f pos);
	void setFillColor(sf::Color color);
	void setTexture(sf::Texture &texture);
	bool isMouseOver()const;
	bool isMouseClick(sf::Mouse::Button value)const;
};