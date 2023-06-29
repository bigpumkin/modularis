#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 
#include "basic.hpp"
#include "audio stream.hpp"

class Out : public Basic
{
  public:
	Out();
	
	void process(float sample_rate);
	
	vector<float> buf;
};

//======CPP=======
//#include "out.hpp"

Out::Out()
{
	this->set_background(500, 800, sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("out", 68, sf::Color(255, 184, 0));

	this->num_audio_in = 2;
        
    this->set_socket();
    this->set_mono_all();
    
    sf::SoundBuffer buffer;
}

void Out::process(float sample_rate = 44100) 
{
    buf[0] = this->audio_in[0] + this->audio_in[1];
    float_to_int16(buf);
    buffer.loadFromSamples(buf, 50000, 1, 44100);
}

