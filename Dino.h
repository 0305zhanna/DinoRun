#include <SFML/Graphics.hpp>
#include <string>

class Dino :
	public sf::Sprite//������������
{	
public:
	Dino(std::string image);//����������� ���������
	void Update(float time);//���������� ����� ���������
	bool onGround;//�� �����
	float dy;//�������� ��������� �� y
	const float x = 20;// ���������� ���������  
private:
	float y;//���������� ���������
	const int ground = 370;//�����
	sf::Texture dinoTexture;
	
};