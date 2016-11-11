#ifndef Types_h
#define Types_h

#include "Service.h"

typedef unsigned char byte;

typedef struct {
	
  Service from;
  Service to;
  char *content;

} packet_t;

#endif
