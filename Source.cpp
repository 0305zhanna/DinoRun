#include <SFML/Graphics.hpp>
#include "Source.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdlib.h>
Cactus::Cactus(std::string image)
{
	srand(time(0));
	cactustexture.loadFromFile(image);
	setTexture(cactustexture);
	a = 1;
	setPosition(430, 400);
}
void Cactus::Restart()
{
	a = 1;
	setPosition(640, 400);
}
void Cactus::Update(float t)
{
	if (a < 3) { a = a + 0.00003; };
	move(-200 * a*t, 0);
}

DinoGame::DinoGame() : dino("images/dino13.png"), w(640)
{
	Cactus* cactus1 = new Cactus("images/cactuses.png");
	Cactus* cactus2 = new Cactus("images/cactuses1.png");
	Cactus* cactus3 = new Cactus("images/cactuses2.png");
	Cactus* cactus4 = new Cactus("images/cactuses3.png");

	cactus1->setPosition(new_cactus_coordinate(), cactus1->getPosition().y);
	cactus2->setPosition(new_cactus_coordinate(), cactus2->getPosition().y);
	cactus3->setPosition(new_cactus_coordinate(), cactus3->getPosition().y);
	cactus4->setPosition(new_cactus_coordinate(), cactus4->getPosition().y);

	cactuses.push_back(cactus1);
	cactuses.push_back(cactus2);
	cactuses.push_back(cactus3);
	cactuses.push_back(cactus4);

	count = 0;
	endGame = false;

	font.loadFromFile("sansation.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Black);
	text.setPosition(20, 20);

	endofgame.setFont(font);
	endofgame.setCharacterSize(45);
	endofgame.setColor(sf::Color::Black);
	endofgame.setPosition(120, 180);
}

int DinoGame::new_cactus_coordinate()
{
	int last_coordinate = 0;
	for (int i = 0; i < cactuses.size(); ++i) {
		if (last_coordinate < cactuses[i]->getPosition().x)
		{
			last_coordinate = cactuses[i]->getPosition().x;
		}
	}
	int distance = rand() % MAX_DIST + 45;
	int new_coordinate = w + last_coordinate + distance;
	count += 1;
	return new_coordinate;
}
void DinoGame::Update(sf::Time time)
{
	dino.Update(time.asSeconds());
	for (int i = 0; i < cactuses.size(); ++i) {
		cactuses[i]->Update(time.asSeconds());
		while (cactuses[i]->getPosition().x < (-109))
			cactuses[i]->setPosition(new_cactus_coordinate(), cactuses[i]->getPosition().y);
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
	{
		if (dino.onGround) {
			dino.dy = -0.6;
			dino.onGround = false;
		}
	}
}
int getCount(int count)
{
	int temp = 0;
	while (count > 0){
		count /= 10;
		++temp;
	}
	return temp;
}
void DinoGame::Draw(sf::RenderWindow &w)
{
	for (int i = 0; i < cactuses.size(); ++i) {
		w.draw(*cactuses[i]);
	}
	w.draw(dino);
	std::stringstream ss;
	ss << count;
	sf::String str(ss.str());
	text.setString(str);
	w.draw(text);
	if (endGame){
		dino.dy = 0;
		endofgame.setString("Game over. \n Press R to restart");
		w.draw(endofgame);
	}
}
void DinoGame::Rest()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
		for (int i = 0; i < cactuses.size(); ++i) {
			cactuses[i]->Restart();
		}
		count = 0;
		endGame = false;
	}
}

bool DinoGame::Intersects()
{
	for (int i = 0; i < cactuses.size(); ++i) {
		if (dino.getGlobalBounds().intersects(cactuses[i]->getGlobalBounds())) {
			endGame = true;
			for (int j = 0; j < cactuses.size(); ++j) {
				cactuses[j]->a = 0;
			}
			Rest();
			return true;
		}
	}
}
