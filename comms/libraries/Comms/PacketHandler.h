#ifndef PacketHandler_h
#define PacketHandler_h

class PacketHandler {


public:
	packet_t createPacket();

	void sendPacket(packet_t p);

	void crcCheck(packet_t p);

	byte calculateCrc(packet_t p);
};

#endif
