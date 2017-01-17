#include "Discovery.h"



void advertise(){
	//Find your own service id 
	//Publish to all other nodes e.g makeMessage() to ports - 1,2,3
}


void receiveAdvertisement(byte serviceID){
	map<byte, Service*> table;
	table = getTable();
	//If we don't have this service add it to the table
	if (getService(serviceID) == NULL){
		Service s = Service(serviceID, "", false);
		addService(s);
	} 
	
  /*Increment distance for that serviceID
  Publish to all other nodes - e.g makeMessage() to ports - 1,2,3
  */
}

void sendFailure(byte serviceID){
	map<byte, Service*> table;
	table = getTable();
	Service s = getService(serviceID);
	//Think a remove service method in ServiceTable might be needed to do this
	//create message with flipped return flag and return to sender
	
}


void sendRoutingTable(byte target/sourceAddress){
	map<byte, Service*> table;
	table = getTable();
	//create message with table
}
