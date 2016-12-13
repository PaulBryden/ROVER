#ifndef Comms_h
#define Comms_h

#include <Types.h>
#include <Message.h>
#include <Message.cpp>
#include <PacketHandler.h>
#include <PacketHandler.cpp>
#include <PacketQueue.h>
#include <PacketQueue.cpp>
#ifndef NOARDUINO
#include <Port.h>

#else
#include <DummyPort.h>
#include <Port.h>

#endif

#include <MessageQueue.h>
#include <MessageQueue.cpp>
#include <ServiceTable.h>
#include <ServiceTable.cpp>
#include <Service.h>
#include <Service.cpp>
#include <iterator>
#include <vector>


static PacketQueue packetQueue;
static MessageQueue messageQueue;
static vector<Port*> portList;
static ServiceTable serviceTable;
extern PacketHandler handle;


class Comms {


public:
	Comms();
	void sendMessage(Message m);

	void checkMessages();

	void initialiseNode(std::vector<Port*> serials);
};

#endif
