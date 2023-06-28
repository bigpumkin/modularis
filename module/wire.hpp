#ifndef WIRE_H
#define WIRE_H

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
		Basic *module;
		size_t socket_idx;
		SocketType socket_type;
	};

	SocketInfo from;
	SocketInfo to;
};


vector<Wire> wires;

void bind_socket(Basic *module_from, Basic *module_to, size_t idx_from, size_t idx_to)
{
	Wire wire;
	wire.from.socket_idx = idx_from;
	wire.to.socket_idx = idx_to;
	
	wires.push_back(wire);
}

void set_wires()
{
	for (size_t i = 0; i < wires.size(); i++)
	{
		size_t socket_idx_from = wires[i].from.socket_idx;
		size_t socket_idx_to = wires[i].to.socket_idx;

		wires[i].to.module->audio_in[socket_idx_to] = wires[i].from.module->audio_out[socket_idx_from];
		wires[i].to.module->mod_in[socket_idx_to] = wires[i].from.module->mod_out[socket_idx_from];
	}
}

#endif