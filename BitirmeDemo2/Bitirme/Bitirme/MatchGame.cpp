#include "MatchGame.h"
#pragma once
template<typename LValue, typename RValue>
LValue dotproduct(LValue lvalue, RValue rvalue) {
return LValue(lvalue.x * rvalue.x, lvalue.y * rvalue.y);
}

template<typename Vec>
string to_string(Vec vec, string begin = "(", string sep = ",", string end = ")") {
stringstream ss;
ss << begin << vec.x << sep << vec.y << end;
return ss.str();
}


MatchGame::MatchGame(bool consoleDebug) : window(0), consoleDebug(consoleDebug){}
bool MatchGame::getConsoleDebug()const { return consoleDebug; }
void MatchGame::setConsoleDebug(bool debug) { this->consoleDebug = debug; }
void MatchGame::loadConfig(
	string filepath,
	sf::Vector2u& winsize,
	string& title,
	sf::Vector2i& grid,
	sf::Vector2f& itemsize,
	sf::Vector2f& range,
	string& defaultTexturePath,
	string& dataFilePath)
{
	if(consoleDebug)
		cout << "*** loadConfig(" << filepath << ") Begin ***" << endl;
	fstream file(filepath, ios::in);
	if (!file.is_open())
		throw "Error : MatchGame::loadConfig()";
	string reader;
	typedef unordered_map<string, string> umap;
	umap data;
	string seperator = ":";
	while (getline(file, reader)) {
		size_t index = reader.find(seperator);
		data[reader.substr(0, index)] = reader.substr(index + seperator.length());
	}

	int space = 8;
	for (umap::iterator iter = data.begin(); iter != data.end(); iter++) {
		string str = iter->first;
		stringstream ss(iter->second);
		if (consoleDebug)
			cout << setw(8) << "- " << str << " -> " << iter->second << endl;
		if (str == "windowsize")
			ss >> winsize.x >> winsize.y;
		else if (str == "title")
			getline(ss, title);
		else if (str == "grid")
			ss >> grid.x >> grid.y;
		else if (str == "itemsize")
			ss >> itemsize.x >> itemsize.y;
		else if (str == "range")
			ss >> range.x >> range.y;
		else if (str == "default")
			getline(ss, defaultTexturePath);
		else if (str == "data")
			getline(ss, dataFilePath);
	}
	if (consoleDebug)
		cout << "*** loadConfig(" << filepath << ") End ***" << endl;
}


void MatchGame::loadFromFile(string filepath) {
	if (consoleDebug)
		cout << "*** loadFromFile(" << filepath << ") Begin ***" << endl;
	sf::Vector2i grid;
	sf::Vector2u winsize;
	string title;
	sf::Vector2f itemsize, range, space;
	string defaultTexturePath;
	string dataFilePath;
	loadConfig(filepath, winsize, title, grid, itemsize, range, defaultTexturePath, dataFilePath);
	space = dotproduct(itemsize, grid) + dotproduct(range, grid - sf::Vector2i(1, 1));
	space = dotproduct(static_cast<sf::Vector2f>(winsize) - space, sf::Vector2f(.5, .5));
	if (consoleDebug)
		cout << "Space : " << to_string(space) << endl;
	createItems(grid, itemsize);
	setDefaultTexture(defaultTexturePath);
	vector<tPair> textures = readTexture(dataFilePath);
	matchItems(textures);
	setPositionItem(grid, range, space);
	setWindow(new sf::RenderWindow(sf::VideoMode(winsize.x, winsize.y), title));
	if (consoleDebug)
		cout << "*** loadFromFile(" << filepath << ") End ***" << endl << endl;
}

void MatchGame::setWindow(sf::RenderWindow* window) {
	if (consoleDebug)
		cout << "*** setWindow() Begin ***" << endl;
	this->window = window;
	if (consoleDebug)
		cout << "*** setWindow() End ***" << endl << endl;
}

void MatchGame::setDefaultTexture(string filepath) {
	if (consoleDebug)
		cout << "*** setDefaultTexture(filepath) Begin ***" << endl;
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile(filepath);
	defaultItem.setTexture(texture);
	if (consoleDebug)
		cout << "*** setDefaultTexture(filepath) End ***" << endl << endl;
}

void MatchGame::setDefaultTexture(sf::Texture* texture) {
	if (consoleDebug)
		cout << "*** setDefaultTexture(texture) Begin ***" << endl;
	defaultItem.setTexture(texture);
	if (consoleDebug)
		cout << "*** setDefaultTexture(texture) End ***" << endl << endl;
}

void MatchGame::createItems(sf::Vector2i grid, sf::Vector2f itemsize) {
	if (consoleDebug)
		cout << "*** createItems() Begin ***" << endl;
	defaultItem.setSize(itemsize);
	for (int i = 0; i < grid.x * grid.y; i++)
		items.push_back(Item(itemsize));
	if (consoleDebug)
		cout << "*** createItems() End ***" << endl << endl;
}

void MatchGame::setPositionItem(sf::Vector2i grid, sf::Vector2f range, sf::Vector2f space) {
	if (consoleDebug)
		cout << "*** setPositionItem() Begin ***" << endl;
	int counter = grid.x * grid.y;
	if (counter != items.size())
		throw "Error : MatchGame::setPositionItem()";
	for (int i = 0; i < counter; i++)
		items[i].setPosition(dotproduct(items[i].getSize() + range, sf::Vector2i(i % grid.x, i / grid.x)) + space);
	if (consoleDebug)
		cout << "*** setPositionItem() End ***" << endl << endl;
}

void MatchGame::matchItems(vector<tPair>& textures) {
	if (consoleDebug)
		cout << "*** matchItems() Begin ***" << endl;
	if (items.size() != 2 * textures.size())
		throw "Error : MatchGame::matchItems()";
	vector<Item*> pitem;
	for (auto& item : items)
		pitem.push_back(&item);

	int i;
	for (auto& pair : textures) {
		i = rand() % pitem.size();
		Item* item1 = pitem[i];
		pitem.erase(pitem.begin() + i);
		i = rand() % pitem.size();
		Item* item2 = pitem[i];
		pitem.erase(pitem.begin() + i);
		if (consoleDebug) {
			cout << pair.first << " ";
			cout << pair.second << " " << endl;
		}
		item1->setTexture(pair.first);
		item2->setTexture(pair.second);
		item1->setMatch(item2);
		item2->setMatch(item1);
	}
	if (consoleDebug)
		cout << "*** matchItems() End ***" << endl << endl;
}

vector<tPair> MatchGame::readTexture(string filepath) {
	if (consoleDebug)
		cout << "*** readTexture(" << filepath << ") Begin ***" << endl;
	size_t index = filepath.rfind("/");
	if (index == string::npos)
		throw "Error : MatchGame::readTexture()";
	string path = filepath.substr(0, index + 1);
	fstream file(filepath, ios::in);
	vector<tPair> pairs;
	int space = 8;
	string t1, t2;
	while (file >> t1 >> t2) {
		if (consoleDebug)
			cout << setw(8) << "- " << path + t1 << " " << path + t2 << " ";
		tPair tpair(new sf::Texture, new sf::Texture);
		if (consoleDebug) {
			cout << boolalpha << tpair.first->loadFromFile(path + t1) << " ";
			cout << tpair.second->loadFromFile(path + t2) << endl << noboolalpha;
		}
		else
		{
			tpair.first->loadFromFile(path + t1);
			tpair.second->loadFromFile(path + t2);
		}
		pairs.push_back(tpair);
	}
	if (consoleDebug)
		cout << "*** readTexture(" << filepath << ") End ***" << endl << endl;
	return pairs;
}

bool MatchGame::isFinish()const {
	for (auto& item : items)
		if (item.getIsDraw())
			return false;
	return true;
}

void MatchGame::loop() {
	before = curr = NULL;
	while (window->isOpen() && !isFinish()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				for (int i = 0; i < items.size(); i++) {
					if (items[i].isOnPos(sf::Mouse::getPosition(*window))) {
						if (consoleDebug) {
							cout << "Tiklanan " << i << " ";
						}
						if (before) {
							if (before != &items[i]) {
								curr = &items[i];
								if (consoleDebug)
									cout << "(farkli ikinci tiklama)";
							}
							else {
								if (consoleDebug)
									cout << "(ayni ikinci tiklama)";
							}
						}
						else {
							before = &items[i];
							if (consoleDebug)
								cout << "(ilk tiklama)";
						}
						if (consoleDebug)
							cout << endl;
					}
				}
				break;
			}
		}

		window->clear(sf::Color::White);
		for (auto& item : items) {
			if (item.getIsDraw()) {
				bool check = &item != before && &item != curr;
				if (check) {
					defaultItem.setPosition(item.getPosition());
					window->draw(defaultItem);
				}
				else
					window->draw(item);
			}
		}
		window->display();
		if (before && curr) {
			sf::sleep(sf::seconds(1));
			if (consoleDebug) {
				cout << "Check Before : " << before << " getMatch() : " << before->getMatch() << endl;
				cout << "Check Curr : " << curr << " getMatch() : " << curr->getMatch() << endl;
			}
			if (before->checkMatch(curr)) {
				curr->setIsDraw(false);
				before->setIsDraw(false);
			}
			before = curr = NULL;
		}
	}
}
