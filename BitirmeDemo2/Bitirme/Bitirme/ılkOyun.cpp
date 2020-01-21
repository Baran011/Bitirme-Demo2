#include "ýlkOyun.h"
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
#include <SFML/Audio.hpp>
#include <string> 
#include "Menu.h"
#include "oyunlar.h"
#include "Button.h"
using namespace sf;

const int M = 20;              //satýr
const int N = 10;              //sütun

int field[M][N] = { 0 };
int parcaOffsetX = 50;
int parcaOffsetY = 10;

struct Point
{
	int x, y;
} a[4], b[4];

int figures[7][4] =
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O

};

bool check()
{
	for (int i = 0; i<4; i++)
		if (a[i].x<0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;

		return 1;
};

ýlkOyun::ýlkOyun()
{
	srand(time(0));
	//sf::ContextSettings setting = sf::Event::Resized;
	sf::RenderWindow  window3(sf::VideoMode(640, 960), "ilkOyun");

	

	sf::Font font1;
	sf::Text puan;

	
	if (!font1.loadFromFile("arial.ttf"))
	{
		std::cout << "font yüklenemedi" << std::endl;
	}

	puan.setFont(font1);
	puan.setFillColor(sf::Color::Black);
	puan.setString("0");
	puan.setPosition(sf::Vector2f(260,50));
	puan.setCharacterSize(20);
	puan.setStyle(sf::Text::Bold);

	sf::SoundBuffer buffer;

	if (!buffer.loadFromFile("sounds/tetrisSound.wav"))
	{
		std::cout << "Müzik yüklenemedi" << std::endl;
	}

	sf::Sound sound;
	sound.setBuffer(buffer);

	sound.play();
	sound.setLoop(true);

	Texture t1,t2,t3;
	if (t1.loadFromFile("images/tetris/tiles.png") == false)
	{
		std::cout << "Parcalar yüklenemedi" << std::endl;
	}
	if (t2.loadFromFile("images/tetris/background.png") == false)
	{
		std::cout << "Arkaplan yüklenemedi" << std::endl;
	}
	if (t3.loadFromFile("images/tetris/frame.png") == false)
	{
		std::cout << "Cerceve yüklenemedi" << std::endl;
	}
	Sprite s(t1), background(t2), frame(t3);
	

	int dx = 0; bool rotate = 0; int colorNum = 1;
	float timer = 0, delay = 0.3;

	Clock clock;

	while (window3.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window3.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window3.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == Keyboard::Up) rotate = true;
				else if (event.key.code == Keyboard::Left) dx = -1;
				else if (event.key.code == Keyboard::Right) dx = 1;
				else if (event.key.code == Keyboard::Escape)
				{
					window3.close();
					sound.stop();
					oyunlar::oyunlar();
				}
				break;
			}
				
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

		//// <- Move -> ///
		for (int i = 0; i<4; i++) { b[i] = a[i]; a[i].x += dx; }
		if (!check()) for (int i = 0; i<4; i++) a[i] = b[i];

		//////Rotate//////
		if (rotate)
		{
			Point p = a[1]; //center of rotation
			for (int i = 0; i<4; i++)
			{
				int x = a[i].y - p.y;
				int y = a[i].x - p.x;
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}
			if (!check()) for (int i = 0; i<4; i++) a[i] = b[i];
		}

		///////Tick//////
		if (timer>delay)
		{
			for (int i = 0; i<4; i++) { b[i] = a[i]; a[i].y += 1; }

			if (!check())
			{
				for (int i = 0; i<4; i++) field[b[i].y][b[i].x] = colorNum;

				colorNum = 1 + rand() % 7;
				int n = rand() % 7;
				for (int i = 0; i<4; i++)
				{
					a[i].x = figures[n][i] % 2;
					a[i].y = figures[n][i] / 2;
				}
			}

			timer = 0;
		}

		///////check lines//////////
		int k = M - 1;
		int t = N - 1;
		
		for (int i = M - 1; i>0; i--)
		{
			int count = 0;
			int sayac = 0;
			for (int j = 0; j<N; j++)
			{
				
				if (field[i][j]) {
					count++;
					
				}

				field[k][j] = field[i][j];                                           //silinen satýr bir üst satýr olur
				
			}
			if (count < N) {
				k--; 
				sayac++;
				puan.setString(std::to_string(sayac));
			}
			
		}

		// dead control
		for (int i = N-1; i >0 ; i--)
		{
			int count = 0;
			for (int j = 0; j < M; j++)
			{
				if (field[j][i]) count++;

			}
			if (count >= 19)
			{
				std::cout << "Oyun sonlandý";
			}
		}

		dx = 0; rotate = 0; delay = 0.3;


		window3.clear(Color::White);
		window3.draw(background);

		for (int i = 0; i<M; i++)
			for (int j = 0; j<N; j++)
			{
				if (field[i][j] == 0) continue;
				s.setTextureRect(IntRect(field[i][j] * 36, 0, 36, 36));
				s.setPosition(j * 36, i * 36);
				s.move(57, 60); //offset																		////////////////////////////////
				window3.draw(s);
			}

		for (int i = 0; i<4; i++)
		{
			s.setTextureRect(IntRect(colorNum * 36, 0, 36, 36));
			s.setPosition(a[i].x * 36, a[i].y * 36);
			s.move(57, 60); //offset
			window3.draw(s);
		}
		
		//window3.draw(frame);
		window3.draw(puan);
		window3.display();

	}
}
void ýlkOyun::draw(sf::RenderTarget& target, sf::RenderStates)const {
	target.draw(ýlkOyun::ýlkOyun());
	//target.draw(text);
}

ýlkOyun::~ýlkOyun()
{
}
