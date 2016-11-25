#include "Comms.h"

void Comms::sendMessage(Message m) {
	vector<packet_t> packets;
	packets = m.toPackets();
	
	byte target = m._targetService;
	
	Service * s = serviceTable.getService(target);
	
	if (s -> getShortestDistance() > 0 ) {
		Port p = s -> getOutgoingPort();
		
		for (int i; packets.size() > i; i++) {
			handle.sendPacket(packets[i], p);
		}
	} else {
		m.readMessage();
	}
	
}

void Comms::checkMessages() {
	while (messageQueue.queueSize() > 0) {
		Message message = messageQueue.popMessage();
		message.readMessage();
	}
}

void Comms::initialiseNode(Port* serials[]) {
	// TODO initialise static variables?
	//vector<Port> portList(ports, ports + sizeof ports / sizeof ports[0]);
	//vector<Port> portList;
	for (int i = 0; i < (sizeof(*serials) / sizeof(serials[0])); i++) {
		portList[i] = *serials[i];
	}
	
	// TODO Do resource discovery stuff
}
