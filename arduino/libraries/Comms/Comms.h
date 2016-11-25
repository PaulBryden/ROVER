#ifndef Comms_h
#define Comms_h

#include "Types.h"
#include "Message.h"
<<<<<<< HEAD
=======
#include "PacketHandler.h"
>>>>>>> 80c05bef427cbc534397e031ab93e1cb01489e83

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
<<<<<<< HEAD
=======
extern PacketHandler handle;
>>>>>>> 80c05bef427cbc534397e031ab93e1cb01489e83

class Comms {


public:
	void sendMessage(Message m);

	void checkMessages();

	void initialiseNode(Port* serials[]);
};

#endif
