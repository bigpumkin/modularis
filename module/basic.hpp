#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Basic
{
  private:
    void draw_display_name(float pos_x, float pos_y, sf::RenderWindow &window);
    void draw_background(float pos_x, float pos_y, sf::RenderWindow &window);
       
  public:
	float size_x;
	float size_y;
	float pos_x;
	float pos_y;

	// Название модуля
	sf::Font font;
	sf::Text display_name; // используется в функции set_display_name

	// Основное тело (фон)
	sf::RectangleShape background;

	// Джеки и прочие надписи
	sf::Color text_color;
	sf::Color jack_color;
	
	sf::Text get_diplay_name();
	
	//Формат вывода с модулей
	vector<vector<float>> audio_in;
	vector<vector<float>> audio_out;
	vector<vector<float>> mod_in;
	vector<vector<float>> mod_out;
	
    void set_background(float size_x, float size_y, sf::Color background_color, sf::Color outline_color);
	
	void set_display_name(string name, int character_size_name, sf::Color display_name_color);
	
	void draw(float pos_x, float pos_y, sf::RenderWindow& window);

	sf::RectangleShape get_background();
	
	void set_out(int c_audio_in,  int c_audio_out, int c_mod_in, int c_mod_out);
	
};


//======CPP======
//#include "basic.hpp"
#include "assets/fonts/Roboto-Regular.hpp"

void Basic::set_background(float size_x, float size_y, sf::Color background_color, sf::Color outline_color)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(size_x, size_y));
	rectangle.setFillColor(background_color);
	rectangle.setOutlineColor(outline_color);
	rectangle.setOutlineThickness(5);

	background = rectangle;
}

void Basic::draw_background(float pos_x, float pos_y, sf::RenderWindow &window)
{
	this->background.setPosition(pos_x, pos_y);

	window.draw(this->background);
}

void Basic::set_display_name(string name, int character_size_name, sf::Color display_name_color)
{
	font.loadFromMemory(&assets_fonts_Roboto_Regular_ttf, assets_fonts_Roboto_Regular_ttf_len);
	sf::Text text;
	text.setString(name);
	text.setFont(font);
	text.setCharacterSize(character_size_name);
	text.setFillColor(display_name_color);

	display_name = text;
}

void Basic::draw_display_name(float pos_x, float pos_y, sf::RenderWindow &window)
{
	this->display_name.setPosition(pos_x, pos_y - 30.f);

	window.draw(this->display_name);
}

sf::Text Basic::get_diplay_name() { return display_name; }

void Basic::draw(float pos_x, float pos_y, sf::RenderWindow &window)
{
	draw_background(pos_x, pos_y, window);
    draw_display_name(pos_x, pos_y, window);
}

sf::RectangleShape Basic::get_background() { return background; }

void Basic::set_out(int c_audio_in,  int c_audio_out, int c_mod_in, int c_mod_out)
{
    audio_in.resize(c_audio_in);
    audio_out.resize(c_audio_out);
    mod_in.resize(c_mod_in);
    mod_out.resize(c_mod_out);
}