#ifndef MessageQueue_h
#define MessageQueue_h

#include "Message.h"

class MessageQueue {

	deque<Message> _queue;

public:
	void addMessage(Message m);
	void addPriorityMessage(Message m);
	
	deque<Message> getMessageQueue();
	Message popMessage();
	int queueSize();
};

#endif
