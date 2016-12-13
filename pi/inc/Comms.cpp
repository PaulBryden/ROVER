#include <Comms.h>

Comms::Comms() {
}

void Comms::sendMessage(Message m) {
	vector<packet_t> packets;
	packets = m.toPackets();
	
	byte target = m._targetService;
	
	Service * s = serviceTable.getService(target);
	
	if (s -> getShortestDistance() > 0 ) {
		int p = s -> getOutgoingPort();
		
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


void Comms::initialiseNode(std::vector<Port*> serials) {
	portList=serials;
	//portList[3] = *(serials[3]);
	// TODO initialise static variables?
	//int i = 0;

	//while (i < 3){
	//	portList.push_back(*serials[i]);
	//	i++;
	//}
	//for (i = 0; 3 > i ; ++i){// (sizeof(*serials) / sizeof(serials[0])); i++) {
	//	portList[i] = *(serials[i]);
	//}
	
	// TODO Do resource discovery stuff
}
