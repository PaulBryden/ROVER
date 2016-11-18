#ifndef PacketHandler_h
#define PacketHandler_h
#include "Types.h"
#include "Port.h"
class PacketHandler {


public:
	packet_t createPacket(byte flags,byte messageID, byte packetID, byte targetService, byte sourceService, byte dataContent[]);

	void sendPacket(packet_t p, Port port);

	bool crcCheck(packet_t p);

	byte calculateCrc(packet_t p);
};

#endif
