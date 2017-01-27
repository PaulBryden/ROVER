#ifndef Comms_h
#define Comms_h

#include <Types.h>
#include <Message.h>
#include <Message.cpp>
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

extern PacketHandler handle;
static MessageQueue messageQueue;
static vector<Port*> portList;
static ServiceTable serviceTable;

#include <PacketQueue.h>
#include <PacketQueue.cpp>
static PacketQueue packetQueue;


#include <PacketHandler.h>
#include <PacketHandler.cpp>
class Comms {


public:
	Comms();
	void sendMessage(Message m);

	void checkMessages();

	void initialiseNode(std::vector<Port*> serials);
};

#endif
