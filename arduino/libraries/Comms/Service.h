#ifndef Service_h
#define Service_h

#include "Port.h"
#include <map>

class Service {

private:
	byte _id;
	String _name;
	std::map<Port, int> _portMap;

public:
	Service(byte id, String name);
	byte getId();
	String getName();
	Port getOutgoingPort();
	void setPortDistance(Port port, int distance);
};

#endif
