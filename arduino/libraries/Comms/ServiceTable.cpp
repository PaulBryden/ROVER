#include "ServiceTable.h"

ServiceTable::ServiceTable() {

}

Service ServiceTable::getService(byte id) {
	return _table[id];
}

/* Add a service to the look-up table. Existing service will be overwritten if present. */
void ServiceTable::addService(Service s) {
	_table[s.getId()] = s;
}

void ServiceTable::mergeTable(ServiceTable t) {
	// TODO - implement ServiceTable::mergeTable
}
