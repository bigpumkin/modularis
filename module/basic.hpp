#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <cmath>
#include <string>

using namespace std;

class Basic
{
  private:
     void draw_display_name(float pos_x, float pos_y);
     void draw_background(float pos_x, float pos_y);
       
  public:
	float size_x;
	float size_y;
	float pos_x;
	float pos_y;
	size_t amount_in;
	size_t amount_out;	
	size_t amount_mod;

	//Название модуля
	float pos_x_name;
	float pos_y_name;
	string name;
	sf::Font font;
	sf::Color display_name_color;
	int character_size_name;
	 sf::Text display_name; //используется функции set display_name

	//Основное тело(фон)
	sf::Color background_color;
	sf::Color outline_color;
	sf::RectangleShape background;

	//Джеки и прочие надписи
	sf::Color text_color;
	sf::Color jack_color;
	
	sf::Text get_diplay_name();
	
    void set_background(float size_x, float size_y, sf::Color background_color, sf::Color outline_color);
	
	void set_display_name(string name, int character_size_name, sf::Color display_name_color);
	
	void draw(float pos_x, float pos_y, sf::RenderWindow& window);

	sf::RectangleShape get_background();
};