#include <SFML/Graphics.hpp>
#include "Dino.h"
#include <ctime>
#include <iostream>
Dino::Dino(std::string image)
{
	dinoTexture.loadFromFile(image);
	setTexture(dinoTexture);
	setPosition(x, ground);
	y = ground;
	dy = 0;
	onGround = true;
}
void Dino::Update(float time)
{
	if (!onGround) { 
		dy = dy + 0.99*time;
	}
	y += dy;
	if (y >= ground) {
		dy = 0; 
		y = ground; 
		onGround = true;
	}
	setPosition(x, y);
}
