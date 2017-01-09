#ifndef Port_h
#define Port_h
#include <vector>
#include <string>
#include "Types.h"

class Port {

private:
	vector<byte> _buffer;

	HardwareSerial *_serial;


	bool _start_last;
	bool _end_last;
	bool _packet_start_rcvd;


public:
	virtual int id = 0;
	virtual void read() =0;

	Port(int id, HardwareSerial *serial);
	int _id;
	void read();

	virtual void write(vector<byte> serializedPacket) =0;

	virtual packet_t getPacketFromBuffer() = 0;

};

#endif
