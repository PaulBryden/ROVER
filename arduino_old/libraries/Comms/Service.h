#ifndef Service_h
#define Service_h

#ifdef NOARDUINO
#include "DummyPort.h"
#else
#include "Port.h"
#endif

#include <iterator>
#include <map>
#include <string>

class Service {

private:
	byte _id;
	char* _name;
	std::map<int, int> _portMap; // port id to distance
	bool _local;

public:
	Service(byte id, char* name, bool local);
	~Service();
	byte getId();
	char* getName();
	int getOutgoingPort();
	int getShortestDistance();
	void setPortDistance(int port, int distance);
	std::map<int, int> getPortMap();
};

#endif
