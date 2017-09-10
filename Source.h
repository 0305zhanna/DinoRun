#include <SFML/Graphics.hpp>
#include <string>
#include "Dino.h"

class Cactus:
	public sf:: Sprite//������������ ������
{
public:
	Cactus(std::string image);//�����������

	void Update(float t);//���������� ���������

	void Restart();//������������� ��������
	float a;//��������� �������
private:
	float dx;//�������� �������
	sf::Texture cactustexture;
	int t;
	const float w = 70;//������ �������� �������
};
class DinoGame
{
public:
	DinoGame();//�����������
	void Update(sf::Time time);//���������� ����� ����
	void Draw(sf::RenderWindow &w);//���������
	std::vector<Cactus*> cactuses;//������ ���������� �� ������ ������
	Dino dino;//������ ��������
	bool Intersects();//�������� ������������
	void Rest();//������
private:
	bool endGame;//����� ����
	int count; //����
	sf::Text text;//����� �����
	sf::Text endofgame;//����� ����
	int new_cactus_coordinate();//���������� ����� ��������� �������
	int w;//������ ����
	const int MAX_DIST = 320;//��������� ����� ���������
	sf::Font font;//�����
};

