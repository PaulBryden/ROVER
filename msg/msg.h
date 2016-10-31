
typedef unsigned short int uint_t;

typedef struct
{
	unsigned char sizeOfPacket : 6;
	unsigned char flags : 5;
	unsigned char messageID : 5;
	unsigned char targetService;
	unsigned char sourceService;
	unsigned char packetID;
	unsigned char CRC;
	
} packet_header_t

typedef struct
{
	unsigned char numOfPacketsInMessage;
	unsigned char typeOfMessage : 3;
	
} message_header_t

typedef struct
{
	unsigned int filler=0;
	
} empty_data_t

typdef struct{
	packet_header_t packetHeader;
	message_header_t messageHeader;
	char *dataContent;
	
} example_packet_1_t

typdef struct{
	packet_header_t packetHeader;
	char *dataContent;
	
} example_packet_t

char *create_message(unsigned char targetService, unsigned char sourceService, char *dataContent, unsigned int sizeOfData){
	/**DO malloc and crc calculation, and header population here.
	return pointer to memory location containing packet data.
	first 6 bits can be extracted to determine packet size**/
	return 0;
}

example_packet_t parse_raw_message(char *rawMessage){
	/**extract raw packet data from pointer and populate fields.**/
	return 0;
}



void sendMessage(message_t *msg) {
	// pack message and write to msg->to->port
}

