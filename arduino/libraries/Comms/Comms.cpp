#include "Comms.h"

void Comms::sendMessage(Message m) {
	// TODO - implement Comms::sendMessage
	vector<packet_t> packets;
	packets = m.toPackets();
	
	byte target = message._targetService;
	
	Service s = serviceTable.getService(target);
	
	if (Service.getShorttestDistance() > 0 ) {
		Port p = Service.getOutgoingPort();
		
		for (int i; packets.size() > i; i++) {
			handle.sendPacket(packets[i], p);
		}
	} else {
		message.readMessage();
	}
	
}

void Comms::checkMessages() {
	// TODO - implement Comms::checkMessages
	message = messageQueue.popMessage();
	message.readMessage();
}

void Comms::initialiseNode(HardwareSerial* serials[]) {
	// TODO create static variables
	//vector<Port> portList(ports, ports + sizeof ports / sizeof ports[0]);
	vector<Port> portList;
	for (int i = 0; i < (sizeof(serials) / sizeof(serials[0])); i++) {
		portList[i] = Port(serials[i]);
	}
	
	// TODO Do resource discovery stuff
}
