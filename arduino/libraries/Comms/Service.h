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
	string _name;
	map<int, int> _portMap;

public:
	Service(byte id, string name);
	~Service();
	byte getId();
	string getName();
	Port getOutgoingPort();
	int getShortestDistance();
	void setPortDistance(int port, int distance);
	map<int, int> getPortMap();
};

#endif
