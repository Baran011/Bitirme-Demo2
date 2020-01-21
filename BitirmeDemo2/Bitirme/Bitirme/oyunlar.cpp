#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "oyunlar.h"
#include "Button.h"
#include "ýlkOyun.h"
#include "Solitaire.h"
#include "kelimeOyun.h"
#include "MatchGame.h"
#include "Button.h"
#include "film.h"
using namespace std;
oyunlar::oyunlar()
{   
	sf::Texture arkaplan;
	sf::Font font1;
	
	
	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer2;

	sf::Texture exitGame;
	exitGame.loadFromFile("images/Close.png");
	sf::Sprite s_exitGame(exitGame);
	s_exitGame.setPosition(1200, 800);
	//s_exitGame.setScale(0.3, 0.3);

	sf::Texture backGame;
	backGame.loadFromFile("images/Back.png");
	sf::Sprite s_backGame(backGame);
	s_backGame.setPosition(1000, 760);
	//s_backGame.setScale(0.45, 0.45);

	

	/*
	sf::Texture tetrisB;
	tetrisB.loadFromFile("images/tetrisButton.PNG");
	sf::Sprite tetrisT(tetrisB);
	tetrisT.setPosition(100, 100);
	//tetrisT.setScale(1, 1);

	sf::Texture solitaire;
	solitaire.loadFromFile("images/eslestir.PNG");
	sf::Sprite solitaireT(solitaire);
	solitaireT.setPosition(300, 100);
	solitaireT.setScale(0.32, 0.50);

	sf::Texture kelime;
	kelime.loadFromFile("images/kelimeButton.PNG");
	sf::Sprite kelimeT(kelime);
	kelimeT.setPosition(530, 100);

	sf::Texture eslestir;
	eslestir.loadFromFile("images/eslestirButton.PNG");
	sf::Sprite eslestirT(eslestir);
	eslestirT.setPosition(760, 100);

	sf::Texture eslestir2;
	eslestir2.loadFromFile("images/iliskisel.PNG");
	sf::Sprite eslestirT2(eslestir2);
	eslestirT2.setPosition(990, 100);

	*/
	

	if (!buffer.loadFromFile("sounds/oyunlarSound.wav"))
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

	sound.play();
	sound.setLoop(true);

if (!font1.loadFromFile("arial.ttf"))
{
	std::cout << "font yüklenemedi" << std::endl;
}

sf::RenderWindow  window2(sf::VideoMode(1500, 1080), "Oyunlar");

if (arkaplan.loadFromFile("images/oyunlarbg-13.jpg") == false)
{
	std::cout << "resim yüklenemedi" << std::endl;
}

Button button;
button.setParent(&window2);
button.setPosition(sf::Vector2f(180, 230));

sf::Texture texture;
texture.loadFromFile("images/tetrisButton.PNG");
button.setTexture(texture);

Button button2;
button2.setParent(&window2);
button2.setPosition(sf::Vector2f(180, 520));

sf::Texture texture2;
texture2.loadFromFile("images/eslestir.PNG");
button2.setTexture(texture2);

Button button3;
button3.setParent(&window2);
button3.setPosition(sf::Vector2f(450, 520));

sf::Texture texture3;
texture3.loadFromFile("images/eslestirButton.PNG");
button3.setTexture(texture3);

Button button4;
button4.setParent(&window2);
button4.setPosition(sf::Vector2f(720, 520));

sf::Texture texture4;
texture4.loadFromFile("images/iliskisel.PNG");
button4.setTexture(texture4);

Button button5;
button5.setParent(&window2);
button5.setPosition(sf::Vector2f(180, 810));

sf::Texture texture5;
texture5.loadFromFile("images/kelimeButton.PNG");
button5.setTexture(texture5);

Button button6;
button6.setParent(&window2);
button6.setPosition(sf::Vector2f(1320, 20));

sf::Texture texture6;
texture6.loadFromFile("images/Close.png");
button6.setTexture(texture6);

Button button7;
button7.setParent(&window2);
button7.setPosition(sf::Vector2f(450, 230));

sf::Texture texture7;
texture7.loadFromFile("images/JerryButton.PNG");
button7.setTexture(texture7);

/*
if (tetrisB.loadFromFile("images/tetrisButton.PNG") == false)
{
std::cout << "resim yüklenemedi" << std::endl;
}
*/


sf::Sprite sprite;
sf::Vector2u size = arkaplan.getSize();
sprite.setTexture(arkaplan);
sprite.setOrigin(size.x / 2, size.y / 2);
sprite.setPosition(765, 540);
sprite.setScale(0.8, 0.9);



/*
Button btn1("Ilk Oyun", { 200,300 }, 20, sf::Color::Green, sf::Color::Black, tetrisB);
btn1.setPosition({ 100,100 });
btn1.setFont(font1);
btn1.setTexture1(tetrisB);

Button btn2("Ikinci oyun", { 200,300 }, 20, sf::Color::Green, sf::Color::Black, tetrisB);
btn2.setPosition({ 350,100 });
btn2.setFont(font1);
btn2.setTexture1(tetrisB);

Button btn3("Geri", { 150,50 }, 20, sf::Color::Red, sf::Color::Black, tetrisB);
btn3.setPosition({ 900,900 });
btn3.setFont(font1);
btn3.setTexture1(tetrisB);
*/


while (window2.isOpen())
{

	sf::Event event;
	while (window2.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window2.close();

			break;
		
		case sf::Event::MouseMoved:
		
			if (sf::Mouse::getPosition(window2).y > s_exitGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < s_exitGame.getGlobalBounds().height + s_exitGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < s_exitGame.getGlobalBounds().width + s_exitGame.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > s_exitGame.getGlobalBounds().left)
			{
				s_exitGame.setScale(0.35, 0.35);

			}
			else
			{
				s_exitGame.setScale(0.3, 0.3);
			}
			if (sf::Mouse::getPosition(window2).y > s_backGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < s_backGame.getGlobalBounds().height + s_backGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < s_backGame.getGlobalBounds().width + s_backGame.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > s_backGame.getGlobalBounds().left)
			{
				
				s_backGame.setScale(0.5, 0.5);
			}
			else
			{
				
				s_backGame.setScale(0.45, 0.45);
			}
			break;
		case sf::Event::MouseButtonPressed:
			/*
			if (sf::Mouse::getPosition(window2).y > tetrisT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < tetrisT.getGlobalBounds().height + tetrisT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < tetrisT.getGlobalBounds().width + tetrisT.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > tetrisT.getGlobalBounds().left) {
				window2.close();
				sound.stop();
				sound2.play();
				ýlkOyun::ýlkOyun();
			}
			else if (sf::Mouse::getPosition(window2).y > solitaireT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < solitaireT.getGlobalBounds().height + solitaireT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < solitaireT.getGlobalBounds().width + solitaireT.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > solitaireT.getGlobalBounds().left)
			{
				window2.close();
				sound.stop();
				sound2.play();
				Solitaire::Solitaire();                                 

			}
			else if (sf::Mouse::getPosition(window2).y > kelimeT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < kelimeT.getGlobalBounds().height + kelimeT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < kelimeT.getGlobalBounds().width + kelimeT.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > kelimeT.getGlobalBounds().left) {
				window2.close();
				sound.stop();
				kelimeOyun::kelimeOyun();
			}
			else if (sf::Mouse::getPosition(window2).y > eslestirT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < eslestirT.getGlobalBounds().height + eslestirT.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < eslestirT.getGlobalBounds().width + eslestirT.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > eslestirT.getGlobalBounds().left)
			{
				std::cout << "oyunun tetiklemesi";

				srand(time(0));
				MatchGame game(true);
				//game.setConsoleDebug(true);
				game.loadFromFile("config2.txt");
				window2.close();
				sound.stop();
				game.loop();

				if (game.isFinish())
				{
					MatchGame game2(true);
					game2.loadFromFile("config3.txt");
					game2.loop();
				}
				
			}
			else if (sf::Mouse::getPosition(window2).y > eslestirT2.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < eslestirT2.getGlobalBounds().height + eslestirT2.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < eslestirT2.getGlobalBounds().width + eslestirT2.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > eslestirT2.getGlobalBounds().left)
			{
				srand(time(0));
				MatchGame game(true);
				//game.setConsoleDebug(true);
				game.loadFromFile("config1.txt");
				window2.close();
				sound.stop();
				game.loop();
			}

				break;

			*/
			 if (sf::Mouse::getPosition(window2).y > s_exitGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < s_exitGame.getGlobalBounds().height + s_exitGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < s_exitGame.getGlobalBounds().width + s_exitGame.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > s_exitGame.getGlobalBounds().left){

				window2.close();
}
			else if(sf::Mouse::getPosition(window2).y > s_backGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).y < s_backGame.getGlobalBounds().height + s_backGame.getGlobalBounds().top &&
				sf::Mouse::getPosition(window2).x < s_backGame.getGlobalBounds().width + s_backGame.getGlobalBounds().left &&
				sf::Mouse::getPosition(window2).x > s_backGame.getGlobalBounds().left)
			{
				std::cout << "Ana Menüye dönüldü";
			}
			

			}
			if (button.isMouseClick(sf::Mouse::Left))
			{
				window2.close();
				sound.stop();
				sound2.play();
				ýlkOyun::ýlkOyun();
			}
			if (button.isMouseOver())
			{
				button.setSize(sf::Vector2f(180, 230));
			}
			else
			{
				button.setSize(sf::Vector2f(150, 200));
			}
			if (button2.isMouseClick(sf::Mouse::Left))
			{
				window2.close();
				sound.stop();
				sound2.play();
				Solitaire::Solitaire();
			}
			if (button2.isMouseOver())
			{
				button2.setSize(sf::Vector2f(180, 230));
			}
			else
			{
				button2.setSize(sf::Vector2f(150, 200));
			}
			if (button3.isMouseClick(sf::Mouse::Left))
			{
				window2.close();
				sound.stop();
				sound2.play();
				srand(time(0));
				MatchGame game(true);
				//game.setConsoleDebug(true);
				game.loadFromFile("config2.txt");
				window2.close();
				sound.stop();
				game.loop();

				if (game.isFinish())
				{
					MatchGame game2(true);
					game2.loadFromFile("config3.txt");
					game2.loop();
				}
			}
			if (button3.isMouseOver())
			{
				button3.setSize(sf::Vector2f(180, 230));
			}
			else
			{
				button3.setSize(sf::Vector2f(150, 200));
			}
			if (button4.isMouseClick(sf::Mouse::Left))
			{
				window2.close();
				sound.stop();
				sound2.play();
				srand(time(0));
				MatchGame game(true);
				//game.setConsoleDebug(true);
				game.loadFromFile("config1.txt");
				window2.close();
				sound.stop();
				sound2.play();
				game.loop();
			}
			if (button4.isMouseOver())
			{
				button4.setSize(sf::Vector2f(180, 230));
			}
			else
			{
				button4.setSize(sf::Vector2f(150, 200));
			}
			if (button5.isMouseClick(sf::Mouse::Left))
			{
				window2.close();
				sound.stop();
				sound2.play();
				kelimeOyun::kelimeOyun();
			}
			if (button5.isMouseOver())
			{
				button5.setSize(sf::Vector2f(180, 230));
			}
			else
			{
				button5.setSize(sf::Vector2f(150, 200));
			}
			if (button6.isMouseClick(sf::Mouse::Left))
			{
				window2.close();
				sound.stop();
			}
			if (button6.isMouseOver())
			{
				button6.setSize(sf::Vector2f(180, 180));
			}
			else
			{
				button6.setSize(sf::Vector2f(150, 150));
			}
			if (button7.isMouseClick(sf::Mouse::Left))
			{
				window2.close();
				sound.stop();
				sound2.play();
				film::film();
				
			}
			if (button7.isMouseOver())
			{
				button7.setSize(sf::Vector2f(180, 230));
			}
			else
			{
				button7.setSize(sf::Vector2f(150, 200));
			}
		}

		window2.clear();

		window2.draw(sprite);
	
		window2.draw(button);
		window2.draw(button2);
		window2.draw(button3);
		window2.draw(button4);
		window2.draw(button5);
		window2.draw(button6);
		window2.draw(button7);
		window2.display();

	}
}
void oyunlar::draw(sf::RenderTarget& target, sf::RenderStates)const {
	target.draw(oyunlar::oyunlar());
	//target.draw(text);
}


oyunlar::~oyunlar()
{
}
