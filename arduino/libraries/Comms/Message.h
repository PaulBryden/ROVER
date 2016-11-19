#ifndef Message_h
#define Message_h

#include "Types.h"
#include <iterator>
#include <vector>

class Message {


public:
	Message(byte messageID, byte targetService, byte sourceService, byte typeOfMessage, byte messageBitfields, vector<byte> bodyContent);
	vector<packet_t> toPackets();

	void readMessage();
};

#endif
