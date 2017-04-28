#ifndef PortIPAddr_h
#define PortIPAddr_h
#include <iterator>
#include <vector>
#include <string>
#include <Types.h>
#include <Port.h>
#include <Comms.h>

class PortIPAddr : public Port {

public:
	 PortIPAddr(int id);
	void read();
	void handleData(char *data, int dataSize);
	void write(vector<byte> serializedPacket);

	packet_t getPacketFromBuffer();

};

#endif
