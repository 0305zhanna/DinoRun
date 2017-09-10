#include <SFML/Graphics.hpp>
#include <string>

class Dino :
	public sf::Sprite//наследование
{	
public:
	Dino(std::string image);//конструктор динозавра
	void Update(float time);//обновление полей динозавра
	bool onGround;//на земле
	float dy;//скорость динозавра по y
	const float x = 20;// координата динозавра  
private:
	float y;//координата динозавра
	const int ground = 370;//земля
	sf::Texture dinoTexture;
	
};