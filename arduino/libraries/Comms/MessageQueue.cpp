#include "MessageQueue.h"

deque<Message> messageQueue;
void MessageQueue::addMessage(Message m) {
	// TODO - implement MessageQueue::addMessage
	messageQueue.push_back(m);
}

Message MessageQueue::popMessage() {
	// TODO - implement MessageQueue::popMessage
	vector<byte> data;
	Message testMessage(0xff,0xff,0xff,0xff,0xff,data);
	return testMessage;
}
