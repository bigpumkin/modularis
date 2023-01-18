#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include "basic.hpp"

class Out : public Basic
{
  public:
	Out();
};

//======CPP=======
//#include "out.hpp"

Out::Out()
{
	this->set_background(500, 800, sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("osc", 68, sf::Color(255, 184, 0));

	amount_in = 5;
	amount_out = 6;
	amount_mod = 3;
}
