#include <SFML/Graphics.hpp>
#include <string>
#include "Dino.h"

class Cactus:
	public sf:: Sprite//наследование спрйта
{
public:
	Cactus(std::string image);//конструктор

	void Update(float t);//обновление координат

	void Restart();//возобновление движения
	float a;//ускорение кактуса
private:
	float dx;//скорость кактуса
	sf::Texture cactustexture;
	int t;
	const float w = 70;//ширина картинки кактуса
};
class DinoGame
{
public:
	DinoGame();//конструктор
	void Update(sf::Time time);//обновление полей игры
	void Draw(sf::RenderWindow &w);//отрисовка
	std::vector<Cactus*> cactuses;//массив указателей на объект кактус
	Dino dino;//объект динозавр
	bool Intersects();//проверка столкновений
	void Rest();//заново
private:
	bool endGame;//конец игры
	int count; //очки
	sf::Text text;//вывод очков
	sf::Text endofgame;//конец игры
	int new_cactus_coordinate();//нахождение новых координат кактуса
	int w;//ширина окна
	const int MAX_DIST = 320;//дистанция между кактусами
	sf::Font font;//шрифт
};

