#ifndef Message_h
#define Message_h

#include "Types.h"
#include <iterator>
#include <vector>

class Message {


public:
	Message(void);
	vector<packet_t> toPackets();

	void readMessage();
};

#endif
