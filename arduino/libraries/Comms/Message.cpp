#include "Message.h"
byte _messageID;
byte _targetService;
byte _sourceService;
byte _typeOfMessage;
byte _messageBitfields;
vector<byte> _bodyContent;

Message::Message(byte messageID, byte targetService, byte sourceService, byte typeOfMessage, byte messageBitfields, vector<byte> bodyContent) {
	_messageID = messageID;
	_targetService = targetService;
	_sourceService = sourceService;

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
