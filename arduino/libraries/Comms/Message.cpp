#include "Message.h"
byte _messageID;
byte _targetService;
byte _sourceService;
vector<byte> _bodyContent;
message_header_t _messageHeader;

Message::Message(byte messageID, byte targetService, byte sourceService, byte typeOfMessage, byte messageBitfields, vector<byte> bodyContent) {

	_messageID = messageID;
	_targetService = targetService;
	_sourceService = sourceService;
	_bodyContent = bodyContent;
	
	//Integer division always rounds down so adding one to give desired result
	_messageHeader.numOfPacketsInMessage = ((MESSAGE_HEADER_SIZE + _bodyContent.size())/PACKET_CONTENT_SIZE) + 1;
	_messageHeader.typeOfMessage = _typeOfMessage;
	_messageHeader.flags = _messageBitfields;
}

vector<packet_t> Message::toPackets() {
	// Generates bytestream 
	vector<byte> bytes = ((vector<byte>) message_header_t);
	bytes.insert(bytes.end(), _bodyContent.begin(), _bodyContent.end());
	vector<packet_t> packets;
	PacketHandler handler = new PacketHandler();
	
	for(int pNo; bytes.size() > 0; pNo++){
		vector<byte> tempByteVector = new vector<byte>();
		packet_t tempPacket = new packet_t;
		for(int i = 0; i < PACKET_CONTENT_SIZE; i++){
			tempByteVector.push_back(bytes[i]);
			bytes.erase(0);
		}
		//Flags currently defaulted to 0  as not implemented yet
		tempPacket = handler.createPacket(000, _messageID, pNo, _targetService, _sourceService, tempByteVector);
		packets.push_back(tempPacket);
	}
	return packets;
}

void Message::readMessage() {
	// TODO - implement Message::readMessage
}
