#ifndef Service_h
#define Service_h

#include "Port.h"

class Service {


public:
	Service();

	Port getOutgoingPort();

	void setPortDistance(Port port, int distance);
};

#endif
