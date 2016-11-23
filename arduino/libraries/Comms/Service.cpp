#include "Service.h"
#include "Comms.h"

Service::Service(byte id, string name) {
	_id = id;
	_name = name;
}

/* Returns the ID number of the service. */
byte Service::getId() {
	return _id;
}

/* Returns the name of the service. */
string Service::getName() {
	return _name;
}

/* Returns the port with the shortest associated distance to this service. */
Port Service::getOutgoingPort() {
	int p; // port number
	int d = -1;
	map<int, int>::iterator it = _portMap.begin();
	while(it != _portMap.end()) {
		if (d < 0 || it->second < d) {
			d = it->second;
			p = it->first;
		}
	}
	return portList[p];
}

/* Returns the shortest distance associated with this service. */
int Service::getShortestDistance() {
	int d = -1;
	map<int, int>::iterator it = _portMap.begin();
	while(it != _portMap.end()) {
		if (d < 0 || it->second < d) {
			d = it->second;
		}
	}
	return d;
}

/* Sets the associated distance for this service on a particular port. Will only 
overwrite an existing entry if the new distance is less than the old distance. */
void Service::setPortDistance(int port, int distance) {
	if (_portMap.find(port) == _portMap.end()
		|| _portMap[port] > distance) {
		_portMap[port] = distance;
	}
}

/* Returns the port map */
map<int, int> Service::getPortMap() {
	return _portMap;
}
