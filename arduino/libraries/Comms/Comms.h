#ifndef Comms_h
#define Comms_h

#include "Message.h"

#ifndef NOARDUINO
#include "Port.h"
#endif

#include "MessageQueue.h"
#include "ServiceTable.h"
#include <iterator>
#include <vector>


extern MessageQueue messageQueue;
extern vector<Port> portList;
extern ServiceTable serviceTable;
extern Message message;

class Comms {


public:
	void sendMessage(Message m);

	void checkMessages();

	void initialiseNode(Port ports[]);
};

#endif
