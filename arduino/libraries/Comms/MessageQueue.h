#ifndef MessageQueue_h
#define MessageQueue_h

#include "Message.h"

class MessageQueue {


public:
	void addMessage(Message m);

	Message popMessage();
};

#endif
