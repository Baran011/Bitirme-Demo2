
#include<SFML\Graphics.hpp>
#include<iostream>


class Button {

public:
	Button(){}

	Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor,sf::Texture texture1) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);

		
		button.setSize(size);
		button.setFillColor(bgColor);
		button.setTexture(&texture1);
	}

	void setFont(sf::Font &font) {
		text.setFont(font);
	}

	void setBackColor(sf::Color color) {
		button.setFillColor(color);
	}
	void setTextColor(sf::Color color) {
		text.setFillColor(color);               //setColor
	}

	void setPosition(sf::Vector2f pos) {
		button.setPosition(pos);

		float xPos = (pos.x + button.getLocalBounds().width / 3) - (text.getLocalBounds().width / 2);
		float yPos = (pos.y + button.getLocalBounds().height / 3) - (text.getLocalBounds().height / 2);
		text.setPosition({ xPos,yPos });
	}
	void setTexture1(sf::Texture texture1) {

		button.setTexture(&texture1);

	}

	void drawTo(sf::RenderWindow &window2) {
		window2.draw(button);
		window2.draw(text);
	}

	bool isMouseOver(sf::RenderWindow & window2) {
		float mouseX = sf::Mouse::getPosition(window2).x;
		float mouseY = sf::Mouse::getPosition(window2).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

		if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
			return true;
		}
		return false;
	}
private:
	sf::RectangleShape button;
	sf::Text text;
};