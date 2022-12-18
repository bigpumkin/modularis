#include "osc.hpp"

Oscillator::Oscillator()
{
	this->set_background(300, 200, sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("osc", 16, sf::Color(255, 184, 0));

	amount_in = 5;
	amount_out = 6;
	amount_mod = 3;
}
