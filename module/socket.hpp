#include <vector>

using namespace std;


class Socket
{
    public:
       vector<float> values;
       
       void set_mono();
       void set_poly(); //16 голосов
       
};


//=======CPP========
//#include "socket.hpp"

void Socket::set_mono()
{
    this->values.resize(1);
}

void Socket::set_poly()
{
    this->values.resize(16);
}

