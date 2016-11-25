#include "MessageQueue.h"

void MessageQueue::addMessage(Message m) {
	// TODO - implement MessageQueue::addMessage
}

Message MessageQueue::popMessage() {
	// TODO - implement MessageQueue::popMessage
	Message m = messageQueue.front();
	messageQueue.pop_front();
	return m;
}
