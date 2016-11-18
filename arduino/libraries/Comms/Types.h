#ifndef Types_h
#define Types_h

using namespace std;

typedef unsigned char byte;

typedef struct
{
	unsigned char flags : 3;
	unsigned char messageID : 5;
	unsigned char targetService;
	unsigned char sourceService;
	unsigned char packetID;
	unsigned char crc;
	
} packet_header_t;

typedef struct
{
	unsigned char numOfPacketsInMessage;
	unsigned char typeOfMessage : 5;
	unsigned char messageBitfields : 3;
} message_header_t;

typedef struct
{
	packet_header_t packetHeader;
	unsigned char *dataContent;
	
} packet_t;

#endif
