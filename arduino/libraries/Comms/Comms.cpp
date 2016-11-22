#include "Comms.h"

MessageQueue messageQueue;
vector<Port> portList;
ServiceTable serviceTable;

void Comms::sendMessage(Message m) {
	// TODO - implement Comms::sendMessage
}

void Comms::checkMessages() {
	// TODO - implement Comms::checkMessages
}

void Comms::initialiseNode(Port ports[]) {
	// create static variables
	portList.push_back(Port(Serial));
	portList.push_back(Port(Serial1));
	portList.push_back(Port(Serial2));
	portList.push_back(Port(Serial3));

	// Do resource discovery stuff
}
