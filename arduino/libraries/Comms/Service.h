#ifndef Service_h
#define Service_h

#include "Port.h"
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
	map<Port, int, PortComparator> _portMap;

public:
	Service(byte id, string name);
	byte getId();
	string getName();
	Port getOutgoingPort();
	void setPortDistance(Port port, int distance);
};

#endif
