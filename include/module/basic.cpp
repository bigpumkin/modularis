#include "basic.hpp"

void Basic::set_background(float pos_x, float pos_y, float size_x, float size_y, sf::Color background_color, sf::Color outline_color)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(size_x, size_y));
	rectangle.setFillColor(background_color);
	rectangle.setOutlineColor(outline_color);
	rectangle.setOutlineThickness(5);
	rectangle.setPosition(pos_x, pos_y);

	background = rectangle;
}

void Basic::set_display_name(float pos_x, float pos_y, string name, int character_size_name, sf::Color display_name_color)
{
	font.loadFromFile("/system/fonts/Roboto-Regular.ttf");
	sf::Text text;
	text.setString(name);
	text.setFont(font);
	text.setPosition(pos_x, pos_y);
	text.setCharacterSize(character_size_name);
	text.setColor(display_name_color);

	display_name = text;
}

sf::Text Basic::get_diplay_name() { return display_name; }

void Basic::draw(float pos_x, float pos_y, sf::Window& window)
{
	set_background(pos_x, pos_y, size_x, size_y, background_color,outline_color);
	
	set_display_name(pos_x, pos_y, name,character_size_name,display_name_color);
	
	sf::RectangleShape background = this->background;
	sf::Text display_name = this->display_name;

   window.draw(background);
   window.draw(display_name);
}

sf::RectangleShape Basic::get_background() { return background; }
