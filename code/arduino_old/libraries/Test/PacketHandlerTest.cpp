//#include "../Comms/Comms.h"
#include "../Comms/PacketHandler.cpp"
//#include "../Comms/Comms.cpp"
#include "../Comms/DummyPort.cpp"
#include <iostream>
int main() {
	Port p;
	PacketHandler newPacketHandler;
	std::vector<byte> foo1 (3,100);
	cout << "Data Content for packet1:";
	for (std::vector<byte>::const_iterator i = foo1.begin(); i != foo1.end(); ++i)
		cout << hex << int(*i) << ' ';
	cout << endl;
	std::vector<byte> foo2 (4,200);
	std::vector<byte> foo3 (4,50);
	packet_t packet1;
	packet_t packet2;
	packet_t packet3;
	packet_t packet1Copy;
	packet1	= newPacketHandler.createPacket(0xff,0xff,0xfe,0xfe,0xff,foo1);
	packet2	= newPacketHandler.createPacket(0xff,0xff,0xfe,0xfe,0xff,foo2);
	packet3	= newPacketHandler.createPacket(0x1,0x01,0x02,0x01,0x03,foo3);
	packet1Copy=newPacketHandler.createPacket(0xff,0xff,0xfe,0xfe,0xff,foo1);
	std::cout <<"Created Packet1. Packet1 crc:" <<endl;
	std::cout << hex << int( packet1.packetHeader.crc) <<endl;
	std::cout <<"Created Packet2. Packet2 crc:" <<endl;
	std::cout << hex << int( packet2.packetHeader.crc) <<endl;
	std::cout <<"Created Packet3. Packet3 crc:" <<endl;
	std::cout << hex << int( packet3.packetHeader.crc) <<endl;
	std::cout <<"Created Packet1Copy. Packet1Copy crc:" <<endl;
	std::cout << hex << int( packet1Copy.packetHeader.crc) <<endl;

	if (newPacketHandler.crcCheck(packet1)) {
		std::cout << "CRC for input packet matches"<<endl;
	}else {
		std::cout << "CRC for input packet does not match"<<endl;
	}
	packet1.packetHeader.crc=0xFF;
	if (newPacketHandler.crcCheck(packet1)) {
		std::cout << "CRC for input packet matches" <<endl;
	}else {
		std::cout << "CRC for input packet does not match" <<endl;
	}
	newPacketHandler.sendPacket(packet1Copy,p);
  return 0;
}
