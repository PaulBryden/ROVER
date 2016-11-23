#include "ServiceTable.h"

ServiceTable::ServiceTable() {

}

/* Returns the service with a given id. */
Service* ServiceTable::getService(byte id) {
	return _table[id];
}

/* Adds a service to the look-up table. Existing service will be merged into if present. */
void ServiceTable::addService(Service s) {
	int id = s.getId();
	if (_table.find(id) == _table.end()) { // Service is not yet in table
		_table[id] = &s;
	} else { // Service is already in table, so merge
		map<int, int> portMap = s.getPortMap();
		map<int, int>::iterator it = portMap.begin();
		while(it != portMap.end()) {
			_table[id]->setPortDistance(it->first, it->second);
		}
	}
}

/* Merges another service table into this one. */
void ServiceTable::mergeTable(ServiceTable t) {
	map<byte, Service*> otherTable = t.getTable();
	map<byte, Service*>::iterator it = otherTable.begin();
	while(it != otherTable.end()) {
		addService(*it->second);
	}
}

/* Returns the look-up table. */
map<byte, Service*> ServiceTable::getTable() {
	return _table;
}
