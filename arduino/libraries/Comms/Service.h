#ifndef Service_h
#define Service_h

#ifdef Arduino_h
#include "Port.h"
#else
#include "DummyPort.h"
#endif

#include <iterator>
#include <map>
#include <string>

struct PortComparator
{
   bool operator() (const Port& lhs, const Port& rhs) const
   {
       return lhs.id < rhs.id;
   }
};

class Service {

private:
	byte _id;
	string _name;
	map<int, int> _portMap;

public:
	Service(byte id, string name);
	byte getId();
	string getName();
	Port getOutgoingPort();
	int getShortestDistance();
	void setPortDistance(int port, int distance);
	map<int, int> getPortMap();
};

#endif
