#include "PacketHandler.h"


packet_t PacketHandler::createPacket(byte flags,byte messageID, byte packetID, byte targetService, byte sourceService, byte dataContent[]) {
	packet_t packet;
	packet_header_t packetHeader;
	packetHeader.flags=flags & 0x7;
	packetHeader.messageID=messageID & 0x1F;
	packetHeader.targetService=targetService;
	packetHeader.sourceService=sourceService;
	packetHeader.packetID=packetID;
	packetHeader.crc=0x0;
	packet.packetHeader=packetHeader;
	packet.dataContent=dataContent;
	packet.packetHeader.crc=calculateCrc(packet);
	return packet;
	
}

void PacketHandler::sendPacket(packet_t p, Port port) {
	vector<byte> serializedPacket;
	
	byte size= sizeof(p.packetHeader)+sizeof(p.dataContent); //get total packet size
	byte b[64]; //ready memory for byte array cast
	memcpy(b, &p, sizeof(p.packetHeader));//copy header to first part of byte array
	memcpy(b+sizeof(p.packetHeader), &p, sizeof(p.dataContent));
	//copy data content to remaining part of byte array
	
	serializedPacket.push_back (0xFE); //ADD START BYTE
	
	for( int index=0; index<size; index++){
		serializedPacket.push_back (b[index]);
		if (b[index]==0xFE){
			serializedPacket.push_back (0xFE);
		}else if(b[index]==0xFF){
			serializedPacket.push_back (0xFF);
		}
	}
	
	serializedPacket.push_back (0xFF); //ADD END BYTE
	
	
	
}

bool PacketHandler::crcCheck(packet_t p) {
	
	packet_t pCopy = p;
	pCopy.packetHeader.crc=0;
	return (p.packetHeader.crc==calculateCrc(pCopy));
	
}


byte PacketHandler::calculateCrc(packet_t p) {
	// CRC8 calculator.
	// Credit to Dallas/Maxim
	byte crc = 0x00;
	byte size = sizeof(p.packetHeader) + sizeof(p.dataContent); //get total packet size
	byte b[64]; //ready memory for byte array cast
	memcpy(b, &p, sizeof(p.packetHeader));//copy header to first part of byte array
	memcpy(b + sizeof(p.packetHeader), &p, sizeof(p.dataContent));  //copy data content to remaining part of byte array
	for (int index = 0; index<size; index++) {
		byte extract = b[index];
		for (byte tempI = 8; tempI; tempI--) {
			byte sum = (crc ^ extract) & 0x01;
			crc >>= 1;
			if (sum) {
				crc ^= 0x8C;
			}
			extract >>= 1;
		}
	}
	return crc;
}



