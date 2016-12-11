#ifndef Port_h
#define Port_h
#include <iterator>
#include <vector>
#include <string>
#include <Types.h>

#include <wiringSerial.c>
class Port {

private:
	vector<byte> _buffer;

	bool _start_last;
	bool _end_last;
	bool _packet_start_rcvd;


public:
	Port(int id);
	int _id;
	void read();

	void write(vector<byte> serializedPacket);

	packet_t getPacketFromBuffer();

};

#endif
