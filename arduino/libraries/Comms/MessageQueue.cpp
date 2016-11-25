#include "MessageQueue.h"

deque<Message> messageQueue;
void MessageQueue::addMessage(Message m) {
	// TODO - implement MessageQueue::addMessage
	messageQueue.push_back(m);
}

void MessageQueue::addPriorityMessage(Message m){
	messageQueue.push_front(m);
}


Message MessageQueue::popMessage() {
	// TODO - implement MessageQueue::popMessage
	Message m = messageQueue.front();
	messageQueue.pop_front();
	return m;
}

//Added for testing
deque<Message> MessageQueue::getMessageQueue(){
	return messageQueue;
}

int MessageQueue:queueSize(){
	return messageQueue.size();
}