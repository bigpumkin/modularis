#include "osc.hpp"

	Oscillator::Oscillator()
	{
		size_x = 300;
		size_y = 200;

		amount_in = 5;
		amount_out = 6;
		amount_mod = 3;
		
		//Основное тело(фон)
		background_color = sf::Color(8,111,161);
		outline_color = sf::Color(0, 0, 0);
		
		//Название 
		character_size_name = 12;
		display_name_color = sf::Color(255,184,0);
		pos_x_name = pos_x - size_x / 2;
		pos_y_name = pos_y - size_y * 3.4;
		name = "osc";
	}
