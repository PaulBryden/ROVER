#include "../Comms/Message.cpp"
#include "../Comms/MessageQueue.cpp"
#include <stdio.h>

void messageQueueTest(){
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
	printf("made it\n");
	Message m1((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x02, (byte) 0x00, testContent);
	m1.readMessage();
	mq.addMessage(m1);
	//Message m3 = Message((byte)0x00, (byte)0x00, (byte)0x00, (byte)0x08, (byte)0x00, testContent);
	mq.popMessage().readMessage();

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
	static Message m1 = Message((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x02, (byte) 0x00, testContent);
	m1.readMessage();
	static Message m2 = Message((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x07, (byte) 0x00, testContent);
	m2.readMessage();
	Message m3 = Message((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x08, (byte) 0x00, testContent);
	m3.readMessage();
	Message m4 = Message((byte) 0x00,(byte) 0x00, (byte) 0x00,  (byte) 0x00, (byte) 0x00, testContent);
	m4.readMessage();
	m2.readMessage();
	return 1;
}

int main(){
	printf("test One:\n");
	printf("Make Message : %d", makeMessage());
	printf("\ntest Two: \n");
	messageQueueTest();
	return 1;
	
}