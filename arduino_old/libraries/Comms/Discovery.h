#ifndef Discovery_h
#define Discovery_h

#include "ServiceTable.h"
#include "Service.h"

#ifndef NOARDUINO
#include "Port.h"
#else
#include "DummyPort.h"
#endif



class Discovery {

public:
	void advertise();
	
	/*Requires parameter of either serviceID or 
	body content of message to retrieve this.
	In all 3 methods below in cpp file, this is
	initially set to only serviceID or similar*/
	void receiveAdvertisement();
	
	void sendFailure();
	
	void sendRoutingTable();

}