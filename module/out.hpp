#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 
#include "basic.hpp"
#include "audio_stream.hpp"

class Out : public Basic
{
    
  public:
	Out();
	vector<float> buf;
	void process(float sample_rate);
	sf::SoundBuffer buffer;
	
};

//======CPP=======
//#include "out.hpp"

Out::Out()
{
	this->set_background(sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("out", 68, sf::Color(255, 184, 0));

	this->num_audio_in = 2;
        
    this->set_socket();
    this->set_mono_all();
    
}

void Out::process(float sample_rate = 44100) 
{

    this->buf[0].push_back(this->audio_in[0] + this->audio_in[1]);
    
    float_to_int16(buf);
    
    this->buffer.loadFromSamples(buf, 50000, 1, 44100);
    
}

