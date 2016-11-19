#include "Port.h"

void Port::read() {
	// TODO - implement Port::read
}

void Port::write(vector<char> serializedPacket) {
	// TODO - implement Port::write
}

packet_t Port::getPacketFromBuffer() {
	// TODO - implement Port::getPacketFromBuffer
	packet_t testPacket;
	testPacket.packetHeader.flags = 0x0;
	return testPacket;
}

void Port::writePacket(packet_t p) {
	// TODO - implement Port::writePacket
}
