#include "Msgs.h"

static HardwareSerial *serials[4] = {&Serial, &Serial1, &Serial2, &Serial3};

service_t _serviceTable[NO_OF_SERVICES];

class Service {
  public:
    Service(uint_t id, string name, uint_t port, uint_t dist);
    uint_t id;
    string name;
    uint_t port;
    uint_t dist;
};

class Message {
public:
  Message();
  Service from;
  Service to;
  string content;
};

Service::Service(uint_t id, string name, uint_t port, uint_t dist) {
	this->id = id;
	this->name = name;
	this->port = port;
	this->dist = dist;
}

Message::Message(Service from, Service to, string content) {
	this->from = from;
	this->to = to;
	this->content = content;
}

Msgs::Msgs() {
  
}

void Msgs::sendMessage(message_t *msg) {
	// pack message and write to msg->to->port
    Serial.println(msg->to->name);
    serials[msg->to->port].printm(msg);
}


void Msgs::readMessage(message_t *msg) {
  if (msg->to->dist) {
    sendMessage(msg);
  } else {
    // handle message execution here
    Serial.println(msg->from->name);
    Serial.println(msg->content);
  }
}
