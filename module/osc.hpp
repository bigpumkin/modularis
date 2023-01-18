#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp> 
#include <cmath>
#include "basic.hpp"

class Oscillator : public Basic
{
  public:
	Oscillator();
	
	void Oscillator::process(float note_freq, float mod_phase, float mod_freq, unsigned sample_rate);
	
};




//======CPP=======
//#include "osc.hpp"

Oscillator::Oscillator()
{
	this->set_background(500, 800, sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("osc", 68, sf::Color(255, 184, 0));
    this->set_out(0, 1, 1, 0);
	
}

void Oscillator::process(float note_freq, float mod_phase, float mod_freq, unsigned sample_rate)
{
    float phase = 0;
    const unsigned SAMPLES = 44100;
	const unsigned amplitude = 30000;


	const double TWO_PI = 6.28318;
	const unsigned two_div_pi = 0.636619;//для пилы	
	
	const double increment = note_freq/sample_rate;
	double x = 0;
	
	for (unsigned i = 0; i < SAMPLES; i++) 
	{
     //sin
		         audio_out[0][0] = amplitude * sin(x*TWO_PI);
	 //tri	   
		         audio_out[0][1] = two_div_pi * ((((-1)^(SAMPLES+1)) / SAMPLES) * sin(SAMPLES * x));
		   
		}
		x += increment;
	 }

}