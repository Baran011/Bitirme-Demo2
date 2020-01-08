#pragma once
#include "Item.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unordered_map>
using namespace std;

typedef pair<sf::Texture*, sf::Texture*> tPair;
class MatchGame {
	sf::RenderWindow* window;
	vector<Item> items;
	Item defaultItem;
	Item* before;
	Item* curr;
	bool consoleDebug;
public:
	MatchGame(bool consoleDebug = false);
	void loadConfig(	string filepath,
						sf::Vector2u& winsize,
						string& title,
						sf::Vector2i& grid,
						sf::Vector2f& itemsize,
						sf::Vector2f& range,
						string& defaultTexturePath,
						string& dataFilePath);
	bool getConsoleDebug()const;
	void setConsoleDebug(bool debug);
	void loadFromFile(string filepath);
	void setWindow(sf::RenderWindow* window);
	void setDefaultTexture(string filepath);
	void setDefaultTexture(sf::Texture* texture);
	void createItems(sf::Vector2i grid, sf::Vector2f itemsize);
	void setPositionItem(sf::Vector2i grid, sf::Vector2f range, sf::Vector2f space = sf::Vector2f(0, 0));
	void matchItems(vector<tPair>& textures);
	vector<tPair> readTexture(string filepath);
	bool isFinish()const;
	void loop();
};

