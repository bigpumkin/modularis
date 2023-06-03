#include <string>
#include <vector>
#include "basic.hpp"
using namespace std;

struct Wire 
{
    enum SocketType 
    {
       audio_in,
       audio_out,
       mod_in,
       mod_out,
    };

    struct SocketInfo 
    {
       Basic* module;
       size_t socket_idx;
       SocketType socket_type;
    };

    SocketInfo from;
    SocketInfo to;
    
};



