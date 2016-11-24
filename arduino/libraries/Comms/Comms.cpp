#include "Comms.h"

void Comms::sendMessage(Message m) {
	// TODO - implement Comms::sendMessage
	vector<packet_t> packets;
	packets = m.toPackets();
	
}

void Comms::checkMessages() {
	// TODO - implement Comms::checkMessages
	message = messageQueue.popMessage();
	message.readMessage();
	
}

void Comms::initialiseNode(Port ports[]) {
	// TODO create static variables
	vector<Port> portList(ports, ports + sizeof ports / sizeof ports[0]);
	// TODO Do resource discovery stuff
}
