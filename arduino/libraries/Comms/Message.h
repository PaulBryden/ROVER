#ifndef Message_h
#define Message_h

#include "Types.h"
#include <iterator>
#include <vector>

class Message {


public:
	vector<packet_t> toPackets();

	void readMessage();
};

#endif
