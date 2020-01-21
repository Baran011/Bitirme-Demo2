#pragma once
#include <SFML/Graphics.hpp>

class oyunlar : public sf::Drawable
{
public:
	oyunlar();
	void draw(sf::RenderTarget& target, sf::RenderStates)const;
	~oyunlar();
};

