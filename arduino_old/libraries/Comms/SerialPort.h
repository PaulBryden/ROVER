#ifndef SerialPort_h
#define SerialPort_h
#include "Port.h"
#include <iterator>
#include <HardwareSerial.h>

class SerialPort : public Port{

private:
	HardwareSerial* _serial;

public:
	SerialPort(HardwareSerial *serial);
};

#endif
