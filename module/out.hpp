#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 
#include "basic.hpp"
#include "audio_stream.hpp"

class Out : public Basic
{
  private:
    vector<float> buf_float;
	vector<sf::Int16> buf_int16;
	
	float sum_LR;
	
  public:
	Out();
	
	void process(float sample_rate);
	sf::SoundBuffer buffer;
	
};

//======CPP=======
//#include "out.hpp"

Out::Out()
{
	buf_float.push_back(0);
	buf_int16.push_back(0);
	
	this->set_background(sf::Color(8, 111, 161), sf::Color(0, 0, 0));
	this->set_display_name("out", 68, sf::Color(255, 184, 0));

	this->num_audio_in = 2;
        
    this->set_socket();
    this->set_mono_all();
    
}

void Out::process(float sample_rate = 44100) 
{
    this->sum_LR = this->audio_in[0].values[0] + this->audio_in[1].values[0];
    this->buf_float[0] = this->sum_LR;
    
    buf_int16 = float_to_int16(buf_float);
    
    data.samples = buf_int16.data();
        
}

