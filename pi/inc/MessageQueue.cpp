#include <MessageQueue.h>

void MessageQueue::addMessage(Message m) {
	// TODO - implement MessageQueue::addMessage
	_queue.push_back(m);
}

void MessageQueue::addPriorityMessage(Message m){
	_queue.push_front(m);
}


Message MessageQueue::popMessage() {
	// TODO - implement MessageQueue::popMessage
	Message m = _queue.front();
	_queue.pop_front();
	return m;
}

//Added for testing
deque<Message> MessageQueue::getMessageQueue(){
	return _queue;
}

int MessageQueue::queueSize(){
	return _queue.size();
}