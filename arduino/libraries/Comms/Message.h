#ifndef Message_h
#define Message_h
#include "Types.h"
#include <iterator>
#include <vector>

class Message {


public:
	Message(byte messageID, byte targetService, byte sourceService, byte typeOfMessage, byte messageBitfields, vector<byte> bodyContent);
	vector<packet_t> toPackets();
	byte _messageID;
	byte _targetService;
	byte _sourceService;
	byte _typeOfMessage;
	byte _messageBitfields;
	vector<byte> _bodyContent;
	void readMessage();
};

#endif
