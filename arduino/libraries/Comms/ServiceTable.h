#ifndef ServiceTable_h
#define ServiceTable_h

#include "Service.h"

class ServiceTable {


public:
	void addService(Service s);

	void mergeTable(ServiceTable t);
};

#endif
