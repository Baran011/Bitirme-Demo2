#pragma once
#include <SFML/Graphics.hpp>

class �lkOyun : public sf::Drawable
{
public:
	�lkOyun();
	void draw(sf::RenderTarget& target, sf::RenderStates)const;
	~�lkOyun();
};

