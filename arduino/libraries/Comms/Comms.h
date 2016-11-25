#ifndef Comms_h
#define Comms_h

#include "Types.h"
#include "Message.h"

#include "PacketHandler.h"


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
extern PacketHandler handle;


class Comms {


public:
	void sendMessage(Message m);

	void checkMessages();

	void initialiseNode(Port* serials[]);
};

#endif
