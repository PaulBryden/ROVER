#include <stdio.h>
#include <msg.h>
#include <stdlib.h>

char *generate_ping(char *data){
	
packet_message *packetTest=malloc(62);
int sizeOfBody=1;
//packet_packet packetTest;
packetTest->packetHeader.flags=0x00;
packetTest->packetHeader.messageID=0x01;
packetTest->packetHeader.targetService=0xF1;
packetTest->packetHeader.sourceService=0xF0;
packetTest->packetHeader.packetID=0xF0;
packetTest->packetHeader.CRC=0;
packetTest->messageHeader.numOfPacketsInMessage=0x01;
packetTest->messageHeader.typeOfMessage=0x00;
packetTest->messageHeader.messageBitfields=0x00;
packetTest->dataContent[0]= 0xF1;
for (int i = 1; i < (((64-2)-8)-1); ++i){
	packetTest->dataContent[i]=0;
}
 unsigned char *  px = (unsigned char*)packetTest;
px = ((char*)px);
	return (char *)px;
}

int main() {


printf("MSG DUMP:\n");
fflush(stdout);
//const unsigned char * const px = (unsigned char*)packetTest;
char *packetTest =generate_ping(packetTest);
const unsigned char * const px = (unsigned char*)packetTest;
for (int i = 0; i < (64); ++i){
printf("%02X ", px[i]);
fflush(stdout);
} 
/**printf("%x",(char*)&packetTest);*/
  return 0;
}