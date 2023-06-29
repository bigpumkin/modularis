#ifndef BASIC_H
#define BASIC_H

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
  
    size_t max_num_socket;
   
    void draw_display_name(sf::RenderWindow &window);
    void draw_background(sf::RenderWindow &window);
    
    void set_mono_for_type(vector<Socket>& sock);
    void set_poly_for_type(vector<Socket>& sock);
    
    void set_size_module();
    
	
  public:
    
	float size_x;
	float size_y;
	float pos_x;
	float pos_y;
	float background_size_x;
    float background_size_y;
    
    vector <Socket> audio_in;
    vector <Socket> audio_out;
    vector <Socket> mod_in;
    vector <Socket> mod_out;
    
    size_t num_audio_in = 0;
    size_t num_audio_out = 0;
    size_t num_mod_in = 0;
    size_t num_mod_out = 0;
    
	// Название модуля
	sf::Font font;
	sf::Text display_name; // используется в функции set_display_name

	// Основное тело (фон)
	sf::RectangleShape background;

	
	sf::Text get_diplay_name();
	
	
    void set_background(sf::Color background_color, sf::Color outline_color);
	
	void set_display_name(string name, int character_size_name, sf::Color display_name_color);
	
	void draw_socket(sf::RenderWindow &window);
	
	void draw(sf::RenderWindow& window);

	sf::RectangleShape get_background();
	
	void set_socket();	
	void set_mono_all();
	void set_poly_all();
	
	virtual void process(float sample_rate) = 0;
		
};

//======CPP======
//#include "basic.hpp"
#include "assets/fonts/Roboto-Regular.hpp"

void Basic::set_background(sf::Color background_color, sf::Color outline_color)
{
	set_size_module();
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(this->background_size_x, this->background_size_y));
	rectangle.setFillColor(background_color);
	rectangle.setOutlineColor(outline_color);
	rectangle.setOutlineThickness(5);

	background = rectangle;
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

void Basic::set_size_module()
{
	float a = this->num_audio_in + this->num_mod_in;
	float b = this->num_audio_out + this->num_mod_out; //для выбора макс.колва гнезд
	
	
	if (a > b)
	{	
		this->max_num_socket = a;
		this->background_size_y = a * 30 + a * 150;  // Расстояние для надписи + Колво гнезд * размер + Колво гнезд * расстояние между ними
	}
	
	else
	{		
		this->max_num_socket = b;
		this->background_size_y = b * 30 + a * 90;  
	}
	
	this->background_size_x = 500;
	
}

void Basic::draw_background(sf::RenderWindow &window)
{
	this->background.setPosition(this->pos_x, this->pos_y);

	window.draw(this->background);
}

void Basic::draw_display_name(sf::RenderWindow &window)
{
	this->display_name.setPosition(this->pos_x, this->pos_y - 30.f);

	window.draw(this->display_name);
}

void Basic::draw_socket(sf::RenderWindow &window)
{
	vector<sf::CircleShape> socket_circle(this->max_num_socket);
	
    this->pos_x -= 25;
	this->pos_y -= -80;
	for (size_t i = 0; i < this->max_num_socket; i++)
	{
	    socket_circle[i].setRadius(30);
	    socket_circle[i].setFillColor(sf::Color(5,67,3));
		socket_circle[i].setOutlineThickness(5);
	    socket_circle[i].setOutlineColor(sf::Color(0,0,0));
	    
		socket_circle[i].setPosition(this->pos_x, this->pos_y);
		
		this->pos_y += 150;
	
		window.draw(socket_circle[i]);
	}
}
void Basic::draw(sf::RenderWindow &window)
{
	draw_background(this->pos_x, this->pos_y, window);
    draw_display_name(this->pos_x, this->pos_y, window);
    draw_socket(this->pos_x, this->pos_y, window);
}

sf::Text Basic::get_diplay_name() { return display_name; }

sf::RectangleShape Basic::get_background() { return background; }

void Basic::set_socket()
{
    this->audio_in.resize(this -> num_audio_in);
    this->audio_out.resize(this ->num_audio_out);
    this->mod_in.resize(this ->num_mod_in);
    this->mod_out.resize(this ->num_mod_out);
    
}

void Basic::set_mono_for_type(vector<Socket>& sock)
{
    for(size_t i=0; i<sock.size(); i++)
    {
        sock[i].set_mono();
    } 
}

void Basic::set_poly_for_type(vector<Socket>& sock)
{
    for(size_t i=0; i<sock.size(); i++)
    {
        sock[i].set_poly();
    }
}

void Basic::set_mono_all()
{
    for(size_t i=0; i < this->num_audio_in; i++)
    {        
    	set_mono_for_type(this -> audio_in);
    }
    
    for(size_t i=0; i < this->num_audio_out; i++)
    {        
    	set_mono_for_type(audio_out);
    }
    
    for(size_t i=0; i < this->num_mod_in; i++)
    {        
    	set_mono_for_type(mod_in);
    }

    for(size_t i=0; i < this-> num_mod_out; i++)
    {
        set_mono_for_type(mod_out);
    }
}

void Basic::set_poly_all()
{
    for(size_t i=0; i< this->num_audio_in; i++)
    {        
    	set_poly_for_type(this->audio_in);
    }
    
    for(size_t i=0; i < this->num_audio_out; i++)
    {        
    	set_poly_for_type(audio_out);
    }
    
    for(size_t i=0; i < this->num_mod_in; i++)
    {        
    	set_poly_for_type(mod_in);
    }

    
  for(size_t i=0; i < this-> num_mod_out; i++)
    {
        set_poly_for_type(mod_out);
    }
}

#endif