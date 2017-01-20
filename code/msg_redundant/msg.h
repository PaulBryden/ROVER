
typedef unsigned short int uint_t;

typedef struct
{
	unsigned char flags : 3;
	unsigned char messageID : 5;
	unsigned char targetService;
	unsigned char sourceService;
	unsigned char packetID;
	unsigned char CRC;
	
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
	message_header_t messageHeader;
	unsigned char dataContent[];
	
} packet_message;

typedef struct
{
	packet_header_t packetHeader;
	unsigned char dataContent[0];
	
} packet_packet;

typedef struct
{
	packet_header_t packetHeader;
	char *dataContent;
	
} example_packet_t;

char *create_message(unsigned char targetService, unsigned char sourceService, char *dataContent, char messageType){
	/**DO malloc and crc calculation, and header population here.
return pointer to memory location containing packet data. It is then message passing’s responsibility to send the data off.
	**/
	return 0;
}

void parse_raw_packet(char *rawPacket){
	/**extract raw packet data from pointer and populate fields.
Also execute relevant function based on parsed data, and pass relevant data to it.**/
	return 0;
}


