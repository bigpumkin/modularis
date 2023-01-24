#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <cmath>

#include "basic.hpp"
#include "misc"

class Oscillator : public Basic
{
 
  public:
	Oscillator();
	
	void process(float note_freq, float mod_phase, float mod_freq, unsigned sample_rate);
	
};




//======CPP=======
//#include "osc.hpp"

Oscillator::Oscillator()
{
	this->set_background(500, 800, sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("osc", 68, sf::Color(255, 184, 0));
    
    this->set_socket(0,4,5,0)
    this->audio_out.set_mono();
    this->mod_in.set_mono();
}

void Oscillator::process(float note_freq, float mod_phase, float mod_freq, float sample_rate)
{
    this->audio_out[0] = get_phasor(note_freq,  sample_rate);
          
}
