#include "film.h"
#include "Button.h"
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
#include <SFML/Audio.hpp>
#include "kelimeOyun.h"
#include "ýlkOyun.h"
#include "oyunlar.h"
#include <ctime>
#include <chrono>
#include<Windows.h>
#ifndef SFEMOVIE_SAMPLE_MEDIA_INFO_HPP
#define SFEMOVIE_SAMPLE_MEDIA_INFO_HPP

#include <SFML/Movie.hpp>

#endif
using namespace std;


film::film()
{
	sf::RenderWindow window(sf::VideoMode(1400, 1080), "Render Texture");

	sf::Text zaman;
	sf::Text dead;
	sf::Texture arkaplan;
	sf::Texture deadBg;
	sf::SoundBuffer buffer;

	int enfazlax = 800, enAzx = 300;
	int enfazlay = 1000, enAzy = 80;
	int can=0;

	Button button;
	button.setParent(&window);
	//button.setPosition(sf::Vector2f(180, 230));
	button.setSize(sf::Vector2f(180, 230));
	sf::Texture texture;
	texture.loadFromFile("images/Jerry3.png");
	button.setTexture(texture);

	Button button2;
	button2.setParent(&window);
	button2.setPosition(sf::Vector2f(1025, -10));
	button2.setSize(sf::Vector2f(250, 230));
	sf::Texture texture3;
	texture3.loadFromFile("images/tabela.png");
	button2.setTexture(texture3);

	Button button3;
	button3.setParent(&window);
	button3.setPosition(sf::Vector2f(50, 50));
	sf::Texture texture4;
	texture4.loadFromFile("images/carpi.png");
	button3.setTexture(texture4);

	Button button4;
	button4.setParent(&window);
	button4.setPosition(sf::Vector2f(130, 50));
	sf::Texture texture5;
	texture5.loadFromFile("images/carpi.png");
	button4.setTexture(texture5);
	
	Button button5;
	button5.setParent(&window);
	button5.setPosition(sf::Vector2f(210, 50));
	sf::Texture texture6;
	texture6.loadFromFile("images/carpi.png");
	button5.setTexture(texture6);

	Button button6;
	button6.setParent(&window);
	button6.setPosition(sf::Vector2f(370, 540));
	sf::Texture texture7;
	texture7.loadFromFile("images/Back.png");
	button6.setTexture(texture7);
	

	sf::Texture texture2;
	texture2.loadFromFile("images/Jerry2.png");
	

	srand(time(0));

	if (!font1.loadFromFile("arial.ttf"))
	{
		std::cout << "font yüklenemedi" << std::endl;
	}

	zaman.setFont(font1);
	zaman.setFillColor(sf::Color::Black);
	zaman.setString("Zaman :" + std::to_string(0));
	zaman.setPosition(sf::Vector2f(1040, 100));
	zaman.setCharacterSize(60);
	zaman.setStyle(sf::Text::Bold);

	dead.setFont(font1);
	dead.setFillColor(sf::Color::Black);
	//dead.setString("");
	dead.setPosition(sf::Vector2f(340, 240));
	dead.setCharacterSize(70);
	dead.setStyle(sf::Text::Bold);
	

	if (arkaplan.loadFromFile("images/JerryYakala.jpg") == false)
	{
		std::cout << "resim yüklenemedi" << std::endl;
	}
	if (deadBg.loadFromFile("images/JerryDead.jpg") == false)
	{
		std::cout << "resim yüklenemedi" << std::endl;
	}

	sf::Sprite sprite;
	sf::Vector2u size = arkaplan.getSize();
	sprite.setTexture(arkaplan);
	sprite.setOrigin(size.x / 2, size.y / 2);
	sprite.setPosition(700, 480);
	sprite.setScale(1.4, 1.7);

	sf::Sprite sprite2;
	sf::Vector2u size2 = deadBg.getSize();
	//sprite2.setTexture(deadBg);
	sprite2.setOrigin(size2.x / 2, size2.y / 2);
	sprite2.setPosition(700, 480);
	sprite2.setScale(1.8, 1.9);
	
	if (!buffer.loadFromFile("sounds/JerrySong.wav"))
	{
		std::cout << "Müzik yüklenemedi" << std::endl;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);

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
				case::sf::Keyboard::Space:
					/////////////////////////
					window.close();
					sound.stop();
					oyunlar::oyunlar();
				}
				break;
			}
			if (event.type == sf::Event::Closed)
				window.close();
			
			
		}
		
		
		for (int i = 0; i < 20; i++)
		{
			
			window.clear(sf::Color::White);
			window.draw(sprite);
			button.setPosition(sf::Vector2f(rand() % (enfazlay - enAzy + 1) + enAzy, rand() % (enfazlax - enAzx + 1) + enAzx));
			zaman.setString("Skor :" + std::to_string(i));
			window.draw(button2);
			window.draw(zaman);
			window.draw(button3);
			window.draw(button4);
			window.draw(button5);
			window.draw(button);
			window.draw(sprite2);
			window.draw(dead);
			window.draw(button6);
			window.display();
			Sleep(2000);

			if (button.isMouseOver())
			{
				
				//Sleep(1000);
			}
			else
			{   
				can++;
				if (can == 1) {
					button3.setSize(sf::Vector2f(80, 80));
				}
				if (can == 2) {
					button4.setSize(sf::Vector2f(80, 80));
				}
				if (can==3)
				{
					int skor=i;
					button5.setSize(sf::Vector2f(80, 80));
					sprite2.setTexture(deadBg);
					dead.setString("Oyun Bitti! Skorunuz :"+ std::to_string(skor));
					button6.setSize(sf::Vector2f(200, 200));
					
					
					//window.close();
				}
				
			}
			if (button6.isMouseOver())
			{
				sound.stop();
				
				window.close();
				
				oyunlar::oyunlar();
			}
			
			
		}
		for (int i = 20; i < 50; i++)
		{
			
			window.clear(sf::Color::White);
			window.draw(sprite);
			button.setPosition(sf::Vector2f(rand() % (enfazlay - enAzy + 1) + enAzy, rand() % (enfazlax - enAzx + 1) + enAzx));
			zaman.setString("Skor :" + std::to_string(i));
			window.draw(button2);
			window.draw(zaman);
			window.draw(button3);
			window.draw(button4);
			window.draw(button5);
			window.draw(button);
			window.draw(sprite2);
			window.draw(dead);
			window.draw(button6);
			window.display();
			Sleep(1200);
			if (button.isMouseOver())
			{

				//Sleep(1000);
			}
			else
			{
				can++;
				if (can == 1) {
					button3.setSize(sf::Vector2f(80, 80));
				}
				if (can == 2) {
					button4.setSize(sf::Vector2f(80, 80));
				}
				if (can == 3)
				{
					int skor = i;
					button5.setSize(sf::Vector2f(80, 80));
					sprite2.setTexture(deadBg);
					dead.setString("Oyun Bitti! Skorunuz :" + std::to_string(skor));
					button6.setSize(sf::Vector2f(200, 200));
					
				}
			}
			if (button6.isMouseOver())
			{
				sound.stop();
				window.close();
				oyunlar::oyunlar();
			}

		}
		for (int i = 50; i < 80; i++)
		{
			
			window.clear(sf::Color::White);
			window.draw(sprite);
			button.setPosition(sf::Vector2f(rand() % (enfazlay - enAzy + 1) + enAzy, rand() % (enfazlax - enAzx + 1) + enAzx));
			zaman.setString("Skor :" + std::to_string(i));
			window.draw(button2);
			window.draw(zaman);
			window.draw(button3);
			window.draw(button4);
			window.draw(button5);
			window.draw(button);
			window.draw(sprite2);
			window.draw(dead);
			window.draw(button6);
			window.display();
			Sleep(1000);
			if (button.isMouseOver())
			{

				//Sleep(1000);
			}
			else
			{
				can++;
				if (can == 1) {
					button3.setSize(sf::Vector2f(80, 80));
				}
				if (can == 2) {
					button4.setSize(sf::Vector2f(80, 80));
				}
				if (can == 3)
				{
					int skor = i;
					button5.setSize(sf::Vector2f(80, 80));
					sprite2.setTexture(deadBg);
					dead.setString("Oyun Bitti! Skorunuz :" + std::to_string(skor));
					button6.setSize(sf::Vector2f(200, 200));
				}
			}
			if (button6.isMouseOver())
			{
				sound.stop();
				window.close();
				oyunlar::oyunlar();
			}

		}
		for (int i = 80; i < 150; i++)
		{
			window.clear(sf::Color::White);
			window.draw(sprite);
			button.setPosition(sf::Vector2f(rand() % (enfazlay - enAzy + 1) + enAzy, rand() % (enfazlax - enAzx + 1) + enAzx));
			zaman.setString("Skor :" + std::to_string(i));
			window.draw(button2);
			window.draw(zaman);
			window.draw(button3);
			window.draw(button4);
			window.draw(button5);
			window.draw(button);
			window.draw(sprite2);
			window.draw(dead);
			window.draw(button6);
			window.display();
			Sleep(800);
			if (button.isMouseOver())
			{

				//Sleep(1000);
			}
			else
			{
				can++;
				if (can == 1) {
					button3.setSize(sf::Vector2f(80, 80));
				}
				if (can == 2) {
					button4.setSize(sf::Vector2f(80, 80));
				}
				if (can == 3)
				{
					int skor = i;
					button5.setSize(sf::Vector2f(80, 80));
					sprite2.setTexture(deadBg);
					dead.setString("Oyun Bitti! Skorunuz :" + std::to_string(skor));
					button6.setSize(sf::Vector2f(200, 200));
				}
			}
			if (button6.isMouseOver())
			{
				sound.stop();
				window.close();
				oyunlar::oyunlar();
			}

		}
		
		window.close();
		
	}

	
}


film::~film()
{
	
}
