#include "Msgs.h"

static HardwareSerial *serials[4] = {&Serial, &Serial1, &Serial2, &Serial3};

service_t _serviceTable[NO_OF_SERVICES];

Msgs::Msgs() {
  
}

void Msgs::sendMessage(message_t *msg) {
	// pack message and write to msg->to->port
    Serial.println(msg->to->name);
    serials[msg->to->port].print(msg);
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
