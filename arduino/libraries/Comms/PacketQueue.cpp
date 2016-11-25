#include "PacketQueue.h"
#include "Types.h"
#include <iostream>

void PacketQueue::addPacket(packet_t p) {
	_queue.push_back(p);
}

void PacketQueue::popPacket() {
	_queue.pop_front();
}

Message PacketQueue::checkPacketQueue() {

	vector<packet_t> messageTrack; //keep track of packets which could potentially create entire message
	vector<int> packetIndexRemove;
	if (_queue.front().packetHeader.packetID == 1) { //if the first packet in buffer is the first packet of message
		//cout << "packetID=1" << endl;
		//cout << "_queue.size() = ";
		//cout << hex << _queue.size() << endl;
		//cout << "_queueDataContent";
		//cout << hex << _queue.front().dataContent.at(0) << endl;
		messageTrack.push_back(_queue.front()); //add it to the potential packets list
		packetIndexRemove.push_back(0);

		if (_queue.size() >= _queue.front().dataContent[0]) { //if there are enough packets to build an entire message in the queue
			//cout << "Enough packets to build message" << endl;
			byte counter = 1; //keep track of number of packets in message
			for (int i = 1; i < _queue.size(); i++) { 
				if ((_queue[i].packetHeader.messageID == _queue.front().packetHeader.messageID)&&(_queue[i].packetHeader.sourceService==_queue[0].packetHeader.sourceService)&&(_queue[i].packetHeader.packetID>counter) ){ //if packets are part of same message
					//cout << "Processing packet:";
					//cout << hex << int(_queue[i].packetHeader.messageID) << endl;
					counter++;
					messageTrack.push_back(_queue[i]); //add potential packet
					packetIndexRemove.push_back(i); //keep track of elements to remove
				}
			}
			if (counter == _queue.front().dataContent[0]) { //if all packets that could make up the message are present
				//cout << "Checking Message ID of packets:" << endl;
				for (int y = 0; y < messageTrack.size(); y++) {

					//cout << int(packetIndexRemove[y]) << endl;
					//cout << hex << int(_queue[packetIndexRemove[y]].packetHeader.messageID) << endl;
				}
				
				for (int i = packetIndexRemove.size()-1; i >= 0; i--) {

					//cout << int(packetIndexRemove[i]) << endl;
					//cout << int(_queue[packetIndexRemove[i]].packetHeader.messageID) << endl;
					_queue.erase(_queue.begin() + packetIndexRemove[i]);

				}

				//cout << hex << "Testing First Packet" << endl;
				//cout << hex << _queue.size() << endl;
				//cout << hex <<int( _queue[0].packetHeader.messageID) <<endl;
				//cout << hex << int(_queue[0].packetHeader.packetID) << endl;
				//cout << "Building Message" << endl;


				return buildMessage(messageTrack); //build the message and return it.
			}
		}
	}
	else {
		//cout << "Popping Packet" << endl;
		popPacket(); //if first packet in queue is not the first packet in message. Something has gone wrong, so pop it.
	}

	//throw "no_message";

}


Message PacketQueue::buildMessage(vector<packet_t> p) {
	byte messageID = p[0].packetHeader.messageID; //Grab data about Message from first packet
	byte targetService = p[0].packetHeader.targetService;
	byte sourceService = p[0].packetHeader.sourceService;
	byte typeOfMessage = p[0].dataContent[1] & 0xF8;
	byte messageBitfields = p[0].dataContent[1] & 0x7;
	vector<byte> bodyContent;

	for (int i = 0; i < p.size(); i++) { //grab body content from each of the packets and push it to bodycontent var
		if (i == 0) {
			int y = 2; //if this is first packet, skip message header
		}
		else {
			int y = 0;
		}
		for (int y = 0; y < p[i].dataContent.size(); y++) {
			bodyContent.push_back(p[i].dataContent[y]);  //add body content to vector var;
		}
	}
	Message builtMessage = Message(messageID, targetService, sourceService, typeOfMessage, messageBitfields, bodyContent);

	return builtMessage;
}
