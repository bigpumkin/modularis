#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <cmath>

#include "basic.hpp"
#include "misc.hpp"

class Oscillator : public Basic
{
 
  public:
	Oscillator();
	
	float note_freq, mod_phase, mod_freq;
	
	vector<float> phase;
	
	void process(float sample_rate);
	
};


//======CPP=======
//#include "osc.hpp"

Oscillator::Oscillator()
{
	this->set_background(sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("osc", 68, sf::Color(255, 184, 0));
	
	this->num_audio_out = 4;
    this->num_mod_in = 5;
    
    this->set_socket();
    this->set_mono_all();
        
}

void Oscillator::process(float sample_rate) 
{
    phase = get_phasor(this->note_freq,this->mod_phase);
    
    this->audio_out[0].values[0] = phase[0]; 
}
