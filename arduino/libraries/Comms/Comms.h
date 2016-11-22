#ifndef Comms_h
#define Comms_h

#include "Message.h"
#include "Port.h"

MessageQueue messageQueue;
vector<Port> portList;
ServiceTable serviceTable;

class Comms {


public:
	void sendMessage(Message m);

	void checkMessages();

	void initialiseNode(Port ports[]);
};

#endif
