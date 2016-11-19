#include "Message.h"

Message::Message(void) {
	
}

vector<packet_t> Message::toPackets() {
	// TODO - implement Message::toPackets
	vector<packet_t> serializedPacket; //TO BE IMPLEMENTED
	packet_t testPacket;
	testPacket.packetHeader.crc = 0x0;
	serializedPacket.push_back(testPacket);
	return serializedPacket;
}

void Message::readMessage() {
	// TODO - implement Message::readMessage

}
