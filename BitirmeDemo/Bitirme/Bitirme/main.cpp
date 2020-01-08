#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "oyunlar.h"
#include "film.h"
#include "ýlkOyun.h"
#include "kelimeOyun.h"

sf::Texture tabela;
sf::Texture arkaplan;


sf::CircleShape *girisTabela = nullptr;

int main()
{
	//kelimeOyun::kelimeOyun();

	
	void spriteEkle(sf::Sprite* yeniSprite); //+

	sf::RenderWindow  window(sf::VideoMode(1400, 1080), "Oyun Havuzu");

	Menu menu(window.getSize().x, window.getSize().y);   

	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer2;

	if (!buffer.loadFromFile("sounds/AnaEkran.wav"))
	{
		std::cout << "Müzik yüklenemedi" << std::endl;
	}
	                        
	if (!buffer2.loadFromFile("sounds/click.wav"))
	{
		std::cout << "Müzik yüklenemedi" << std::endl;
	}

	sf::Sound sound;
	sound.setBuffer(buffer);
	
	
	sf::Sound sound2;
	sound2.setBuffer(buffer2);

		
	
	

	if (arkaplan.loadFromFile("images/bg.jpg") == false)
	{
		std::cout << "resim yüklenemedi" << std::endl;
	}

	if (tabela.loadFromFile("images/signpost5.png") == false)
	{
		std::cout << "tabela resmi yüklenemedi" << std::endl;
	}


	sf::Sprite sprite;
	sf::Vector2u size = arkaplan.getSize();
	sprite.setTexture(arkaplan);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(670, 540);
	sprite.setScale(2,2);


	sf::RectangleShape daire(sf::Vector2f(120, 50));

	daire.setTexture(&tabela);

	daire.setSize(sf::Vector2f(200, 100));

	daire.setPosition(700, 200);

	
	sound.play();
	sound.setLoop(true);


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
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Space:
					sound.stop();
					window.close();
					film::film();
					break;
				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						std::cout << "Oyunlar Açýldý";
						window.close();
						sound.stop();
						sound2.play();
						oyunlar::oyunlar();

						break;
					case 1:
						std::cout << "Sohbet Baþladý";
						sound2.play();
						break;
					case 2:
						std::cout << "Ayarlar açýldý";
						sound2.play();
						break;
					case 3:
						window.close();
						break;
					}

					
				}
				break;

			case sf::Event::Closed:
				window.close();

				break;
			}
		}
		

		window.clear();


		window.draw(sprite);

		window.draw(daire);

		menu.draw(window);


		window.display();
	}
	

return 0;
	}
	
