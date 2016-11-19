#ifndef PacketQueue_h
#define PacketQueue_h

#include "Types.h"
#include "Message.h"
#include <deque>
class PacketQueue {


public:
	void addPacket(packet_t p);

	packet_t popPacket();

	Message checkPacketQueue();

	Message buildMessage(vector<packet_t> p);
	
	void setPacketQueue(deque<packet_t> p);
};

#endif
