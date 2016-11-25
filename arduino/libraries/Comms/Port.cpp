#include "Port.h"
#include <HardwareSerial.h>

#define STARTBYTE 0xfe
#define ENDBYTE 0xff

Port::Port(HardwareSerial *serial) {
	_serial = serial;
	_start_last = false;
	_end_last = false;
	_packet_start_rcvd = false;
	_buffer.reserve(64);
}

void Port::read() {
	while (_serial->available > 0) {
		byte b = _serial->read();
		if (b == STARTBYTE) {
			if (_start_last) { // byte-stuffed start byte
				if (_packet_start_rcvd) {
					_buffer.push_back(b);
					_start_last = false;
				}
			} else if (_end_last) {
				// packet end
				packet_t p = getPacketFromBuffer();
				// send the packet to the packet queue
				// clear the buffer
				_packet_start_rcvd = false;
			} else {
				_start_last = true;
			}
			_end_last = false;
		} else if (b == ENDBYTE) {
			if (_end_last) { // byte-stuffed end byte
				if (_packet_start_rcvd) {
					_buffer.push_back(b);
					_end_last = false;
				}
			} else {
				_end_last = true;
			}
			_start_last = false;
		} else {
			if (_start_last) {
				// start of new packet
				// clear the buffer
				_start_last = false;
				_packet_start_rcvd = true;
			} else if (_end_last) {
				// something went wrong - we have a single end byte
				// clear the buffer
				_packet_start_rcvd = false;
			}
			if (_packet_start_rcvd) {
				_buffer.push_back(b);
			}
		}
	}
}

void Port::write(vector<byte> packet) {
    std::vector<byte>::const_iterator it;
	for (it = packet.begin(); it != packet.end(); ++it) {
    	_serial->write(*it);
	}
}

packet_t Port::getPacketFromBuffer() {
	// Check if buffer has complete packet, if so return
	// TODO - implement Port::getPacketFromBuffer
	packet_t testPacket;
	testPacket.packetHeader.flags = 0x0;
	return testPacket;
}
