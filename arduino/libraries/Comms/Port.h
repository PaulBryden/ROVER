#ifndef Port_h
#define Port_h
#include <iterator>
#include <vector>
#include "Types.h"

class Port {

private:
	vector<byte> _buffer;
	HardwareSerial _serial;

public:
	Port(HardwareSerial serial);
	int id;
	void read();

	void write(vector<char> serializedPacket);

	packet_t getPacketFromBuffer();

};

#endif
