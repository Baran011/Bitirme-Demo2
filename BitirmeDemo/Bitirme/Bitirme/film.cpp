#include "film.h"
#include<SFML\Window.hpp>
#include<SFML\Graphics.hpp>
#include<vector>
#include<iostream>
#include <SFML/Audio.hpp>
#ifndef SFEMOVIE_SAMPLE_MEDIA_INFO_HPP
#define SFEMOVIE_SAMPLE_MEDIA_INFO_HPP

#include <SFML/Movie.hpp>

#endif
film::film()
{
	sf::RenderWindow  window(sf::VideoMode(1400, 1080), "Film Havuzu");
	//sfe::Movie movie;
	//Opencv
	/*
	if (!movie.openFromFile("videos/cizgiFilm1.avi")) {
		std::cout << "film yüklenemedi";
	}
	
	*/
	
	

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();

				break;
			}
			
		}
	}
}


film::~film()
{
}
