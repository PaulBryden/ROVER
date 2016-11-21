#ifndef ServiceTable_h
#define ServiceTable_h

#include "Service.h"
#include <iterator>
#include <map>

class ServiceTable {

private:
	map<byte, Service*> _table;

public:
	ServiceTable();
	Service* getService(byte id);
	void addService(Service s);
	void mergeTable(ServiceTable t);
	map<byte, Service*> getTable();
};

#endif
