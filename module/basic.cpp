#include "basic.hpp"

void Basic::set_background(float size_x, float size_y, sf::Color background_color, sf::Color outline_color)
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(size_x, size_y));
	rectangle.setFillColor(background_color);
	rectangle.setOutlineColor(outline_color);
	rectangle.setOutlineThickness(5);

	background = rectangle;
}

void Basic::draw_background(float pos_x, float pos_y)
{
	sf::RectangleShape rectangle;
	rectangle.setPosition(pos_x, pos_y);
	
	background = rectangle;
}

void Basic::set_display_name( string name, int character_size_name, sf::Color display_name_color)
{
	font.loadFromFile("/system/fonts/Roboto-Regular.ttf");
	sf::Text text;
	text.setString(name);
	text.setFont(font);
	text.setCharacterSize(character_size_name);
	text.setColor(display_name_color);

	display_name = text;
}

void Basic::draw_display_name(float pos_x, float pos_y)
{
	sf::Text text;
	text.setPosition(pos_x, pos_y);
	
	display_name = text;
}

sf::Text Basic::get_diplay_name() { return display_name; }

void Basic::draw(float pos_x, float pos_y, sf::RenderWindow &window)
{
	draw_background(pos_x, pos_y);
     draw_display_name(pos_x, pos_y);
}

sf::RectangleShape Basic::get_background() { return background; }
