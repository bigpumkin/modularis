#include <SFML/Audio.hpp>
#include <vector>

using namespace std;

sf::Int16 float_to_int16(float num)
{
    sf::Int16 res = num * 32767;
    return (int)res;
}

vector<float> get_phasor(float freq,  float phase, float sample_rate)
{
    vector<float> out;
    float sample_time = 1.f/sample_rate;
    size_t samples = sample_rate * 5;
    float phase_increment = freq * sample_time;
    
    for (size_t i = 0; i < samples; i++)
    {
        out.push_back(phase);
        phase = fmod((phase + phase_increment), 1.0);
    }
    
    return out;
    
}