#include <stdio.h>
#include <msg.h>
#include <stdlib.h>
int main() {

packet_packet packetTest;
packetTest.packetHeader.flags=0x00;
packetTest.packetHeader.messageID=0x01;
packetTest.packetHeader.targetService=0xF1;
packetTest.packetHeader.sourceService=0xF0;
packetTest.packetHeader.packetID=0xF0;
packetTest.packetHeader.CRC=0;
packetTest.messageHeader.numOfPacketsInMessage=0x01;
packetTest.messageHeader.typeOfMessage=0x00;
packetTest.messageHeader.messageBitfields=0x00;
packetTest.dataContent=(unsigned char*)malloc(2*sizeof(unsigned char));
packetTest.dataContent[0]= 0xF1;
packetTest.dataContent[1]= 0xF1;
const unsigned char * const px = (unsigned char*)&packetTest;

for (int i = 0; i < sizeof(packetTest); ++i) printf("%02X ", px[i]);
/**printf("%x",(char*)&packetTest);*/
  return 0;
}