
#define NO_OF_SERVICES 256

typedef unsigned short int uint_t;

typedef struct
{
	service_t *from;
	service_t *to;
	char *content;
} message_t;

typedef struct
{
	uint_t id : 8;
	char *name;
	uint_t port : 2;
	uint_t dist : 4;
} service_t;

service_t serviceTable[NO_OF_SERVICES];

message_t *unpackMessage(char *rawmsg) {

}

char *packMessage(message_t *msg) {

}

void readMessage(message_t *msg) {
	if (msg->to->dist) {
		sendMessage(msg);
	} else {
		// handle message execution here
		printf(msg->content);
	}
}

void sendMessage(message_t *msg) {
	// pack message and write to msg->to->port
}

