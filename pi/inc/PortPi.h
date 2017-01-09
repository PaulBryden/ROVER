#ifndef PortPi_h
#define PortPi_h
#include <iterator>
#include <vector>
#include <string>
#include <Types.h>
#include <Port.h>
#include <Comms.h>
#include <wiringSerial.c>

class PortPi : public Port {

public:
	 PortPi(int id);
	void read();

	void write(vector<byte> serializedPacket);

	packet_t getPacketFromBuffer();

};

#endif
