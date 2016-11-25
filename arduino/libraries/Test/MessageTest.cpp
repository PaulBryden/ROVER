#include "../Comms/Message.cpp"
#include "../Comms/MessageQueue.cpp"
#include <stdio.h>

int messageQueueTest(){
	MessageQueue mq;
	vector<byte> testContent;
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	Message m1((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x02, (byte) 0x00, testContent);
	mq.addMessage(m1);
	mq.addPriorityMessage(m1);
	//Message m3 = Message((byte)0x00, (byte)0x00, (byte)0x00, (byte)0x08, (byte)0x00, testContent);
	mq.popMessage();
	return mq.getMessageQueue().size();
}


int makeMessage(){
	vector<byte> testContent;
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	testContent.push_back(0x56);
	testContent.push_back(0x56);		
	testContent.push_back(0x56);
	
	//The readMessage must be called immediately after creation or  doesn't work
	// "Don't know why"
	Message m1((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x02, (byte) 0x00, testContent);
	m1.readMessage();
	Message m2((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x07, (byte) 0x00, testContent);
	m2.readMessage();
	Message m3((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x08, (byte) 0x00, testContent);
	m3.readMessage();
	Message m4((byte) 0x00,(byte) 0x00, (byte) 0x00,  (byte) 0x02, (byte) 0x00, testContent);
	m4.readMessage();
	m2.readMessage();
	return 1;
}

int main(){
	printf("Test One:\n");
	printf("Make Message : %d", makeMessage());
	printf("\nTest Two: \n");
	printf("The test add a message then a priority message, pops then checks the size\n");
	printf("The size of the message queue is: %d",messageQueueTest());
	return 1;
	
}