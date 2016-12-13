#include <Service.h>

Service::Service(byte id, char* name, bool local) {
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
char* Service::getName() {
	return _name;
}



/* Returns the port with the shortest associated distance to this service. 
Requires that there is an outgoing port - check getShortestDistance > 0 first. */

int Service::getOutgoingPort() {
	//return portList[1];
	/**int p; // port number
	int d = -1;
	for (std::map<int, int>::iterator it = _portMap.begin(); it != _portMap.end(); ++it) {
		if (d < 0 || it->second < d) {
			
  Serial.println(p);
  delay(100);
			d = it->second;
			p = it->first;
		}
	}**/
	return _portMap[_id];
}

/* Returns the shortest distance associated with this service. */
int Service::getShortestDistance() {

	int d = -1;
	for (std::map<int, int>::iterator it = _portMap.begin(); it != _portMap.end(); ++it) {
		if (d < 0 || it->second < d) {
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

/* Returns the port map */
std::map<int, int> Service::getPortMap() {
	return _portMap;
}
