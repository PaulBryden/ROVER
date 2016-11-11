#include "Message.h"

class MessageQueue {


public:
	void addMessage(Message m);

	Message popMessage();
};
