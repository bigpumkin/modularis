#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <cmath>
#include <string>
#include <vector>

#include "socket.hpp"

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
    
    vector <Socket> audio_in;
    vector <Socket> audio_out;
    vector <Socket> mod_in;
    vector <Socket> mod_out;
    
	// Название модуля
	sf::Font font;
	sf::Text display_name; // используется в функции set_display_name

	// Основное тело (фон)
	sf::RectangleShape background;

	
	sf::Text get_diplay_name();
	
	
    void set_background(float size_x, float size_y, sf::Color background_color, sf::Color outline_color);
	
	void set_display_name(string name, int character_size_name, sf::Color display_name_color);
	
	void draw(float pos_x, float pos_y, sf::RenderWindow& window);

	sf::RectangleShape get_background();
	
	void set_socket(size_t  num_audio_in, size_t  num_audio_out, size_t  num_mod_in, size_t  num_mod_out);	
	void set_mono_all(vector<Socket>& sock);
	void set_poly_all(vector<Socket>& sock);
	
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

void Basic::set_socket(size_t num_audio_in, size_t num_audio_out, size_t num_mod_in, size_t num_mod_out)
{
    this->audio_in.resize(num_audio_in);
    this->audio_out.resize(num_audio_out);
    this->mod_in.resize(num_mod_in);
    this->mod_out.resize(num_mod_out);
}

void Basic::set_mono_all(vector<Socket>& sock)
{
    for(size_t i=0; i<sock.size(); i++)
    {
        sock[i].values.set_mono;
    }
}

void Basic::set_poly_all(vector<Socket>& sock)
{
    for(size_t i=0; i<sock.size(); i++)
    {
        sock[i].values.set_poly;
    }
}

