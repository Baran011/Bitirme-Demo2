#pragma once
#include <SFML/Graphics.hpp>

class ýlkOyun : public sf::Drawable
{
public:
	ýlkOyun();
	void draw(sf::RenderTarget& target, sf::RenderStates)const;
	~ýlkOyun();
};

