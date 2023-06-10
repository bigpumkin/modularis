#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <cmath>

#include "basic.hpp"
#include "misc.hpp"

class Oscillator : public Basic
{
 
  public:
	Oscillator();
	
	void process(float note_freq, float mod_phase, float mod_freq, float sample_rate);
	
};




//======CPP=======
//#include "osc.hpp"

Oscillator::Oscillator()
{
	this->set_background(500, 800, sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("osc", 68, sf::Color(255, 184, 0));
    
    this->set_socket(0,4,5,0);
    this->set_mono_all();
}

void Oscillator::process(float note_freq, float mod_phase, float mod_freq, float sample_rate) 
{  
    this->audio_out[0].values = get_phasor(note_freq,  mod_phase,sample_rate);
}
