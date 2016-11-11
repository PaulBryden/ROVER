#ifndef PacketQueue_h
#define PacketQueue_h

#include "Types.h"

class PacketQueue {


public:
	void addPacket(packet_t p);

	packet_t popPacket();

	Message buildMessage(packet_t p[]);
};

#endif
