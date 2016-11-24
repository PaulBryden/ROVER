#include "../Comms/Message.cpp"
#include "../Comms/MessageQueue.cpp"
#include <stdio.h>

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
	Message m1((byte) 0x00,(byte) 0x00, (byte) 0x00, (byte) 0x00, (byte) 0x00, testContent);
	return 1;
}

int main(){
	printf("%d", makeMessage());
	return 1;
	
}