#include <Types.h>
#include <ServiceTable.h>
#include <Port.h>
#include <Comms.h>
#include <DummyPort.h>
#include <Service.h>
#include <PacketHandler.h>
#include <Message.h>
#include <PacketQueue.h>
#include <MessageQueue.h>

#include <Types.h>
#include <string>
#include <stdlib.h> // for malloc
void* operator new(unsigned int size, void* v) { 
  return malloc(size); 
}

#define STARTBYTE '#'
#define ENDBYTE '+'

boolean _start_last;
boolean _end_last;
boolean _packet_start_rcvd;
string _buffer;
HardwareSerial* _serial;

void setup() {
  Serial.begin(9600);
  _start_last = false;
  _end_last = false;
  _packet_start_rcvd = false;
  _buffer.reserve(64);
  _serial = &Serial;
}

void loop() {
  while (_serial->available() > 0) {
    byte b = _serial->read();
    _serial->write(b);
    _serial->println();
    if (b == STARTBYTE) {
      if (_start_last) { // byte-stuffed start byte
        if (_packet_start_rcvd) {
          _buffer.push_back(b);
          _start_last = false;
        }
      } 
      else if (_end_last) {
        if (_packet_start_rcvd) {
          // packet end
          //packet_t p = getPacketFromBuffer();
          char ca[1024];
          strcpy(ca, _buffer.c_str());
          _serial->println(ca);
          // send the packet to the packet queue
          _buffer.clear();
          _packet_start_rcvd = false;
        }
      } 
      else {
        _start_last = true;
      }
      _end_last = false;
    } 
    else if (b == ENDBYTE) {
      if (_start_last) {
        _packet_start_rcvd = true;
        _start_last = false;
      }
      if (_end_last) { // byte-stuffed end byte
        if (_packet_start_rcvd) {
          _buffer.push_back(b);
          _end_last = false;
        }
      } 
      else {
        _end_last = true;
      }
      _start_last = false;
    } 
    else {
      if (_start_last) {
        // start of new packet
        _serial->println("Start of new packet.");
        _buffer.clear();
        _start_last = false;
        _packet_start_rcvd = true;
      } 
      else if (_end_last) {
        // something went wrong - we have a single end byte
        _serial->println("Incomplete packet - starting again.");
        _buffer.clear();
        _end_last = false;
        _packet_start_rcvd = false;
      }
      if (_packet_start_rcvd) {
        _buffer.push_back(b);
      }
    }
  }
}

