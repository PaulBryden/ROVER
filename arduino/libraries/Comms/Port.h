#ifndef Port_h
#define Port_h
#include <iterator>
#include <vector>
#include "Types.h"

class Port {


public:
	int id;
	void read();

	void write(vector<char> serializedPacket);

	packet_t getPacketFromBuffer();

	void writePacket(packet_t p);
};

#endif
