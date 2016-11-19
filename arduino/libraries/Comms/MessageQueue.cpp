#include "MessageQueue.h"

void MessageQueue::addMessage(Message m) {
	// TODO - implement MessageQueue::addMessage
}

Message MessageQueue::popMessage() {
	// TODO - implement MessageQueue::popMessage
	vector<byte> data;
	Message testMessage(0xff,0xff,0xff,0xff,0xff,data);
	return testMessage;
}
