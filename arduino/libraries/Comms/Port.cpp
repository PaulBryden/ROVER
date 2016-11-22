#include "Port.h"

Port::Port(HardwareSerial serial) {
	_serial = serial;
}

void Port::read() {
	// Read from _serial and add to _buffer
	// TODO - implement Port::read
}

void Port::write(vector<char> serializedPacket) {
	_serial.write(p);
}

packet_t Port::getPacketFromBuffer() {
	// Check if buffer has complete packet, if so return
	// TODO - implement Port::getPacketFromBuffer
	packet_t testPacket;
	testPacket.packetHeader.flags = 0x0;
	return testPacket;
}

