#ifndef ServiceTable_h
#define ServiceTable_h

#include "Service.h"

class ServiceTable {

private:
	std::map<byte, Service> _table;

public:
	ServiceTable();
	Service getService(byte id);
	void addService(Service s);
	void mergeTable(ServiceTable t);
};

#endif
