#include "Service.h"
#include <iterator>

Service::Service(byte id, String name) {
	_id = id;
	_name = name;
}

/* Returns the ID number of the service. */
byte Service::getId() {
	return _id;
}

/* Returns the name of the service. */
String Service::getName() {
	return _name;
}

/* Returns the port with the shortest associated distance to this service. */
Port Service::getOutgoingPort() {
	Port p;
	int d = -1;
	std::map<Port, int>::iterator it = _portMap.begin();
	while(it != _portMap.end()) {
		if (d < 0 || it->second < d) {
			d = it->second;
			p = it->first;
		}
	}
	return p;
}

/* Sets the associated distance for this service on a particular port. Will only 
overwrite an existing entry if the new distance is less than the old distance. */
void Service::setPortDistance(Port port, int distance) {
	if (_portMap.find(port) == _portMap.end()
		|| _portMap[port] > distance) {
		_portMap[port] = distance;
	}
}
