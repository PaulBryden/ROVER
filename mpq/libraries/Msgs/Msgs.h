#ifndef Msgs_h
#define Msgs_h

#include "Arduino.h"
#include <string>

#define NO_OF_SERVICES 256

typedef unsigned short int uint_t;
/*
typedef struct {
  uint_t id : 8;
  char *name;
  uint_t port : 2;
  uint_t dist : 4;
} service_t;

typedef struct {
  service_t *from;
  service_t *to;
  char *content;
} message_t;
*/
class Service {
    uint_t id;
    string name;
    uint_t port;
    uint_t dist;
  public:
    Service(uint_t id, string name, uint_t port, uint_t dist);
};

class Message {
  Service from;
  Service to;
  string content;
public:
  Message();
};

class Msgs {
  public:
    Msgs();
    void readMessage(Message m);
    bool sendMessage(Message m);
  private:
    Service[] _serviceTable;
    Packet[] messageToPackets(Message m);
    Packet createPacket(char[] content);
    bool sendPacket(Packet p);
    char* serialisePacket(Packet p);
    bool writePacketToSerial(char[] p);
};

#endif

