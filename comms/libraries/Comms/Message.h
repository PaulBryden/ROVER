#ifndef Message_h
#define Message_h

#include "Types.h"

class Message {


public:
	packet_t[] toPackets();

	void readMessage();
};

#endif
