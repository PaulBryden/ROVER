#include <Service.h>

Service::Service(byte id, string name, bool local) {
	_id = id;
	_name = name;
	_local = local;
}

Service::~Service() {}

/* Returns the ID number of the service. */
byte Service::getId() {
	return _id;
}

/* Returns the name of the service. */
string Service::getName() {
	return _name;
}

/* Returns the port with the shortest associated distance to this service. 
Requires that there is an outgoing port - check getShortestDistance > 0 first. */
int Service::getOutgoingPort() {
	if (_local)
		return -1;
	/*NEED TO ADD INPUT VALIDATION TO ENSURE THAT WE RETURN A PORT IN THE LIST THAT ACTUALLY EXISTS!!*/
	int p = -1;
	int d = -1;
	for (std::map<int, int>::iterator it = _portMap.begin(); it != _portMap.end(); ++it) {
		if (p < 0 || it->second < d && it->second > 0) {
			p = it->first; 
			d = it->second;
		}
	}
	return p;
}

/* Returns the shortest distance associated with this service (0 for local service). */
int Service::getShortestDistance() {
	if (_local)
		return 0;
	int d = -1;
	for (std::map<int, int>::iterator it = _portMap.begin(); it != _portMap.end(); ++it) {
		fflush(stdout);
		if (d < 0 || it->second < d && it->second > 0) {
			d = it->second;
		}
	}
	return d;
}

/* Sets the associated distance for this service on a particular port. Will only 
overwrite an existing entry if the new distance is less than the old distance.
Or adds it if the port doesnt already exist. */
void Service::setPortDistance(int port, int distance) {
	if (_portMap.find(port) == _portMap.end()
		|| _portMap[port] > distance) {
		_portMap[port] = distance;
	}
}

/* Flag port - this port will not be used. */
void Service::flagPort(int port) {
	setPortDistance(port, -1);
}

/* Returns the port map */
std::map<int, int> Service::getPortMap() {
	return _portMap;
}
#include <Service.h>

Service::Service(byte id, string name, bool local) {
	_id = id;
	_name = name;
	_local = local;
}

Service::~Service() {}

/* Returns the ID number of the service. */
byte Service::getId() {
	return _id;
}

/* Returns the name of the service. */
string Service::getName() {
	return _name;
}

/* Returns the port with the shortest associated distance to this service. 
Requires that there is an outgoing port - check getShortestDistance > 0 first. */
int Service::getOutgoingPort() {
	if (_local)
		return -1;
	/*NEED TO ADD INPUT VALIDATION TO ENSURE THAT WE RETURN A PORT IN THE LIST THAT ACTUALLY EXISTS!!*/
	int p = -1;
	int d = -1;
	for (std::map<int, int>::iterator it = _portMap.begin(); it != _portMap.end(); ++it) {
		if (p < 0 || it->second < d && it->second > 0) {
			p = it->first; 
			d = it->second;
		}
	}
	return p;
}

/* Returns the shortest distance associated with this service (0 for local service). */
int Service::getShortestDistance() {
	if (_local)
		return 0;
	int d = -1;
	for (std::map<int, int>::iterator it = _portMap.begin(); it != _portMap.end(); ++it) {
		fflush(stdout);
		if (d < 0 || it->second < d && it->second > 0) {
			d = it->second;
		}
	}
	return d;
}

/* Sets the associated distance for this service on a particular port. Will only 
overwrite an existing entry if the new distance is less than the old distance.
Or adds it if the port doesnt already exist. */
void Service::setPortDistance(int port, int distance) {
	if (_portMap.find(port) == _portMap.end()
		|| _portMap[port] > distance) {
		_portMap[port] = distance;
	}
}

/* Flag port - this port will not be used. */
void Service::flagPort(int port) {
	setPortDistance(port, -1);
}

/* Returns the port map */
std::map<int, int> Service::getPortMap() {
	return _portMap;
}
