#ifndef Comms_h
#define Comms_h

#include "Types.h"
#include "Message.h"

#include "PacketHandler.h"
#include "PacketQueue.h"

#ifndef NOARDUINO
#include "Port.h"
#else
#include "DummyPort.h"
#endif

#include "MessageQueue.h"
#include "ServiceTable.h"
#include <iterator>
#include <vector>


static PacketQueue packetQueue;
static MessageQueue messageQueue;
extern vector<Port> portList;

extern ServiceTable serviceTable;
extern PacketHandler handle;


class Comms {


public:
	Comms();
	void sendMessage(Message m);

	void checkMessages();

	void initialiseNode(std::vector<Port> serials);
};

#endif
