
typedef unsigned short int uint_t;

typedef struct
{
	unsigned char startByte : 8;
	unsigned char flags : 3;
	unsigned char messageID : 5;
	unsigned char targetService;
	unsigned char sourceService;
	unsigned char packetID;
	unsigned char CRC;
	
} packet_header_t

typedef struct
{
	unsigned char numOfPacketsInMessage;
	unsigned char typeOfMessage : 5;
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

char *create_message(unsigned char targetService, unsigned char sourceService, char *dataContent, char messageType){
	/**DO malloc and crc calculation, and header population here.
return pointer to memory location containing packet data. It is then message passing’s responsibility to send the data off.
	**/
	return 0;
}

example_packet_t parse_raw_message(char *rawMessage){
	/**extract raw packet data from pointer and populate fields.
Also execute relevant function based on parsed data, and pass relevant data to it.**/
	return 0;
}


