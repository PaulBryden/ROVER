#include "../Comms/Comms.h"
#include "../Comms/PacketHandler.h"
#include "../Comms/PacketHandler.cpp"
#include "../Comms/PacketQueue.h"
#include "../Comms/PacketQueue.cpp"
#include "../Comms/Message.h"
#include "../Comms/Message.cpp"
#include <iostream>
int main() {
	Port p;
	PacketHandler newPacketHandler;
	PacketQueue newPacketQueue;
	std::vector<byte> foo1;
	foo1.push_back(0x3);
	foo1.push_back(0x4);
	foo1.push_back(0x03);
	cout << "Data Content for packet1:";
	for (std::vector<byte>::const_iterator i = foo1.begin(); i != foo1.end(); ++i)
		cout << hex << int(*i) << ' ';
	cout << endl;
	std::vector<byte> foo2 (4,200);
	std::vector<byte> foo3 (4,50); 
	packet_t packet1;
	packet_t packet2;
	packet_t packet3;
	packet_t packet4;
	packet1	= newPacketHandler.createPacket(0x00,0x12,0x01,0x11, 0x03,foo1);
	packet2	= newPacketHandler.createPacket(0x00,0x12,0x02,0x11, 0x03,foo2);
	packet3	= newPacketHandler.createPacket(0x00,0x12,0x03, 0x11,0x03,foo3);
	packet4 = newPacketHandler.createPacket(0x00, 0x14, 0x03, 0x11, 0x03, foo3);
	std::cout <<"Created Packet1. Packet1 crc:" <<endl;
	std::cout << hex << int( packet1.packetHeader.crc) <<endl;
	std::cout <<"Created Packet2. Packet2 crc:" <<endl;
	std::cout << hex << int( packet2.packetHeader.crc) <<endl;
	std::cout <<"Created Packet3. Packet3 crc:" <<endl;
	std::cout << hex << int( packet3.packetHeader.crc) <<endl;
	cout << "adding packet 1" << endl;
	newPacketQueue.addPacket(packet1);
	cout << "success" << endl;
	cout << "adding packet 2" << endl;
	newPacketQueue.addPacket(packet2);
	cout << "success" << endl;
	cout << "adding packet 4 (NOT PART OF SAME MESSAGE)" << endl;
	newPacketQueue.addPacket(packet4);
	cout << "success" << endl;
	cout << "adding packet 3" << endl;
	newPacketQueue.addPacket(packet3);

	cout << "success" << endl;
	cout << "Generating message from packetqueue : Message id is:\n\n" << endl;
	cout << hex << int(newPacketQueue.checkPacketQueue()._messageID) << endl;
	cout << "packet1 id was: " << endl;
	cout << hex << int(packet1.packetHeader.messageID) << endl;
	cout << "packet2 id was: " << endl;
	cout << hex << int(packet1.packetHeader.messageID) << endl;
	newPacketQueue.checkPacketQueue();

}
