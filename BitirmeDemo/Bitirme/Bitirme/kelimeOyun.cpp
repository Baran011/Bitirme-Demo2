#include "kelimeOyun.h"
#include "oyunlar.h"
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
#include <SFML/Audio.hpp>
#include "kelimeOyun.h"
#include <ctime>
#include"Queue1.h"
#include<Windows.h>
#include<string>

kelimeOyun::kelimeOyun()
{
	dqueue d;

	sf::Texture arkaplan;
	sf::Text puan;
	sf::Text textDogru;
	int skor = 0;
	int enfazlax=485, enAzx =90;
	int enfazlay =1050, enAzy = 185;

	sf::RenderWindow  window(sf::VideoMode(1400, 1080), "Kelime Oyunu");
	
	if (!font1.loadFromFile("arial.ttf"))
	{
		std::cout << "font yüklenemedi" << std::endl;
	}

	if (arkaplan.loadFromFile("images/kelimeOyun/background.jpg") == false)
	{
		std::cout << "resim yüklenemedi" << std::endl;
	}

	sf::Sprite sprite;
	sf::Vector2u size = arkaplan.getSize();
	sprite.setTexture(arkaplan);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(670, 540);
	sprite.setScale(2.5, 2.5);

	if (!font1.loadFromFile("arial.ttf"))
	{
		std::cout << "font yüklenemedi" << std::endl;
	}
	//std::string s = std::to_string(skor);
	puan.setFont(font1);
	puan.setFillColor(sf::Color::Black);
	puan.setString(std::to_string(skor));
	puan.setPosition(sf::Vector2f(190, 740));
	puan.setCharacterSize(60);
	puan.setStyle(sf::Text::Bold);

	textDogru.setFont(font1);
	textDogru.setFillColor(sf::Color::Black);
	textDogru.setString("Skor:");
	textDogru.setPosition(sf::Vector2f(135, 640));
	textDogru.setCharacterSize(55);
	textDogru.setStyle(sf::Text::Bold);

	kelime[0].setString("Eve");
	kelime[1].setString("Gitmek");
	kelime[2].setString("Istiyorum");
	kelime[3].setString("Senle");
	kelime[4].setString("Oyun");
	kelime[5].setString("Oynamayi");
	kelime[6].setString("Seviyorum");
	kelime[7].setString("Annemi");
	kelime[8].setString("Cok");

	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("sounds/kelimeSound.wav"))
	{
		std::cout << "Müzik yüklenemedi" << std::endl;
	}

	sf::Sound sound;
	sound.setBuffer(buffer);

	sound.play();
	sound.setLoop(true);


	srand(time(0));

	for (int i = 0; i <MAX_NUMBER_OF_ITEMS; i++)
	{
		kelime[i].setFont(font1);
		//kelime[i].setFillColor(sf::Color::Black);
		//kelime[i].setString("Eve");
		kelime[i].setPosition(sf::Vector2f(rand() % (enfazlay - enAzy + 1) + enAzy, rand() % (enfazlax - enAzx + 1) + enAzx));
		kelime[i].setCharacterSize(40);
		kelime[i].setStyle(sf::Text::Bold );

	}
	
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case::sf::Keyboard::Escape:
					/////////////////////////
					window.close();
					sound.stop();
					oyunlar::oyunlar();
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				if (sf::Mouse::getPosition(window).y > kelime[0].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[0].getGlobalBounds().height + kelime[0].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[0].getGlobalBounds().width + kelime[0].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[0].getGlobalBounds().left)
				{
					kelime[0].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[0].setFillColor(sf::Color::Black);
				}
				if (sf::Mouse::getPosition(window).y > kelime[1].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[1].getGlobalBounds().height + kelime[1].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[1].getGlobalBounds().width + kelime[1].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[1].getGlobalBounds().left)
				{
					kelime[1].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[1].setFillColor(sf::Color::Black);
				}if (sf::Mouse::getPosition(window).y > kelime[2].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[2].getGlobalBounds().height + kelime[2].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[2].getGlobalBounds().width + kelime[2].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[2].getGlobalBounds().left)
				{
					kelime[2].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[2].setFillColor(sf::Color::Black);
				}if (sf::Mouse::getPosition(window).y > kelime[3].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[3].getGlobalBounds().height + kelime[3].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[3].getGlobalBounds().width + kelime[3].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[3].getGlobalBounds().left)
				{
					kelime[3].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[3].setFillColor(sf::Color::Black);
				}if (sf::Mouse::getPosition(window).y > kelime[4].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[4].getGlobalBounds().height + kelime[4].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[4].getGlobalBounds().width + kelime[4].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[4].getGlobalBounds().left)
				{
					kelime[4].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[4].setFillColor(sf::Color::Black);
				}if (sf::Mouse::getPosition(window).y > kelime[5].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[5].getGlobalBounds().height + kelime[5].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[5].getGlobalBounds().width + kelime[5].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[5].getGlobalBounds().left)
				{
					kelime[5].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[5].setFillColor(sf::Color::Black);
				}if (sf::Mouse::getPosition(window).y > kelime[6].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[6].getGlobalBounds().height + kelime[6].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[6].getGlobalBounds().width + kelime[6].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[6].getGlobalBounds().left)
				{
					kelime[6].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[6].setFillColor(sf::Color::Black);
				}if (sf::Mouse::getPosition(window).y > kelime[7].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[7].getGlobalBounds().height + kelime[7].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[7].getGlobalBounds().width + kelime[7].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[7].getGlobalBounds().left)
				{
					kelime[7].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[7].setFillColor(sf::Color::Black);
				}if (sf::Mouse::getPosition(window).y > kelime[8].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[8].getGlobalBounds().height + kelime[8].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[8].getGlobalBounds().width + kelime[8].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[8].getGlobalBounds().left)
				{
					kelime[8].setFillColor(sf::Color::Red);
				}
				else
				{
					kelime[8].setFillColor(sf::Color::Black);
				}
				break;
				//Kuyruða Ekleme Kýsmý
				case sf::Event::MouseButtonPressed:
				if (sf::Mouse::getPosition(window).y > kelime[0].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[0].getGlobalBounds().height + kelime[0].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[0].getGlobalBounds().width + kelime[0].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[0].getGlobalBounds().left) {
					
					kelime[0].setFillColor(sf::Color::Green);
					kelime[0].setStyle(sf::Text::Underlined);
					d.add('E'); d.add('v');  d.add('e');
					
					//printQueue();
				}else if (sf::Mouse::getPosition(window).y > kelime[1].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[1].getGlobalBounds().height + kelime[1].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[1].getGlobalBounds().width + kelime[1].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[1].getGlobalBounds().left) {

					kelime[1].setFillColor(sf::Color::Green);
					kelime[1].setStyle(sf::Text::Underlined);
					
					d.add('G'); d.add('i'); d.add('t'); d.add('m'); d.add('e');  d.add('k');
					
					//printQueue();
					//printQueue();
				}
				else if (sf::Mouse::getPosition(window).y > kelime[2].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[2].getGlobalBounds().height + kelime[2].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[2].getGlobalBounds().width + kelime[2].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[2].getGlobalBounds().left) {

					
					kelime[2].setFillColor(sf::Color::Green);
					kelime[2].setStyle(sf::Text::Underlined);
					d.add('I'); d.add('s'); d.add('t'); d.add('i'); d.add('y'); d.add('o'); d.add('r'); d.add('u');  d.add('m');
					
					//printQueue();
				}
				else if (sf::Mouse::getPosition(window).y > kelime[3].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[3].getGlobalBounds().height + kelime[3].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[3].getGlobalBounds().width + kelime[3].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[3].getGlobalBounds().left) {

					
					kelime[3].setFillColor(sf::Color::Green);
					kelime[3].setStyle(sf::Text::Underlined);
					d.add('S'); d.add('e'); d.add('n'); d.add('l');  d.add('e');
					
					//printQueue();
				}
				else if (sf::Mouse::getPosition(window).y > kelime[4].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[4].getGlobalBounds().height + kelime[4].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[4].getGlobalBounds().width + kelime[4].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[4].getGlobalBounds().left) {

					
					kelime[4].setFillColor(sf::Color::Green);
					kelime[4].setStyle(sf::Text::Underlined);
					d.add('O'); d.add('y'); d.add('u');  d.add('n');
					
					//printQueue();
				}
				else if (sf::Mouse::getPosition(window).y > kelime[5].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[5].getGlobalBounds().height + kelime[5].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[5].getGlobalBounds().width + kelime[5].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[5].getGlobalBounds().left) {

					
					kelime[5].setFillColor(sf::Color::Green);
					kelime[5].setStyle(sf::Text::Underlined);
					d.add('O'); d.add('y'); d.add('n'); d.add('a'); d.add('m'); d.add('a'); d.add('y');  d.add('i');
					
					//printQueue();
				}
				else if (sf::Mouse::getPosition(window).y > kelime[6].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[6].getGlobalBounds().height + kelime[6].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[6].getGlobalBounds().width + kelime[6].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[6].getGlobalBounds().left) {

					
					kelime[6].setFillColor(sf::Color::Green);
					kelime[6].setStyle(sf::Text::Underlined);
					d.add('S'); d.add('e'); d.add('v'); d.add('i'); d.add('y'); d.add('o'); d.add('r'); d.add('u');  d.add('m');
					
					//printQueue();
				}
				else if (sf::Mouse::getPosition(window).y > kelime[7].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[7].getGlobalBounds().height + kelime[7].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[7].getGlobalBounds().width + kelime[7].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[7].getGlobalBounds().left) {

					
					kelime[7].setFillColor(sf::Color::Green);
					kelime[7].setStyle(sf::Text::Underlined);
					d.add('A'); d.add('n'); d.add('n'); d.add('e'); d.add('m');  d.add('i');
					
					//printQueue();
				}
				else if (sf::Mouse::getPosition(window).y > kelime[8].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).y < kelime[8].getGlobalBounds().height + kelime[8].getGlobalBounds().top &&
					sf::Mouse::getPosition(window).x < kelime[8].getGlobalBounds().width + kelime[8].getGlobalBounds().left &&
					sf::Mouse::getPosition(window).x > kelime[8].getGlobalBounds().left) {

					
					kelime[8].setFillColor(sf::Color::Green);
					kelime[8].setStyle(sf::Text::Underlined);
					d.add('C'); d.add('o');  d.add('k');
					
					//printQueue();
					
				}
				
				break;
			}
			switch (event.key.code)
			{
			case sf::Keyboard::Enter:
				kelime[0].setStyle(sf::Text::Bold);
				kelime[1].setStyle(sf::Text::Bold);
				kelime[2].setStyle(sf::Text::Bold);
				kelime[3].setStyle(sf::Text::Bold);
				kelime[4].setStyle(sf::Text::Bold);
				kelime[5].setStyle(sf::Text::Bold);
				kelime[6].setStyle(sf::Text::Bold);
				kelime[7].setStyle(sf::Text::Bold);
				kelime[8].setStyle(sf::Text::Bold);
				
				d.display();
				//bool a;
				d.dogruMu();
				
				 d.ret();
				d.del();
			break;
							
			}
		}
		puan.setString(std::to_string(d.ret()));
		window.clear();
		window.draw(sprite);
		
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			window.draw(kelime[i]);
		}
		window.draw(puan);
		window.draw(textDogru);
		window.display();
	}
	
}


kelimeOyun::~kelimeOyun()
{
}
