#ifndef Msgs_h
#define Msgs_h

#include "Arduino.h"

#define NO_OF_SERVICES 256

typedef unsigned short int uint_t;

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

class Msgs {
  public:
    Msgs();
    void readMessage(message_t *m);
    void sendMessage(message_t *m);
  private:
    service_t *_serviceTable;
};

#endif

