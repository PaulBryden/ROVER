#include "PacketQueue.h"
#include "Types.h"

void PacketQueue::addPacket(packet_t p) {
	// TODO - implement PacketQueue::addPacket
}

packet_t PacketQueue::popPacket() {
	// TODO - implement PacketQueue::popPacket
	packet_t testPacket;
	testPacket.packetHeader.flags = 0x0;
	return testPacket;
}

Message PacketQueue::buildMessage(packet_t p[]) {
	// TODO - implement PacketQueue::buildMessage
	Message testMessage;
	return testMessage;
}
