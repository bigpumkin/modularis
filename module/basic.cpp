#include "basic.hpp"
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
