#include "Port.h"
#include <HardwareSerial.h>

#define STARTBYTE 0xfe
#define ENDBYTE 0xff

Port::Port(int id, HardwareSerial *serial) {
	_id = id;
	_serial = serial;
	_start_last = false;
	_end_last = false;
	_packet_start_rcvd = false;
	_buffer.reserve(64);
}

void Port::read() {
	while (_serial->available() > 0) {
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
				_buffer.clear();
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
				_buffer.clear();
				_start_last = false;
				_packet_start_rcvd = true;
			} else if (_end_last) {
				// something went wrong - we have a single end byte
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

void Port::write(vector<byte> packet) {
    /*std::vector<byte>::const_iterator it;
	for (it = packet.begin(); it != packet.end(); ++it) {
    	_serial->write(*it);
	}*/
	_serial->write(STARTBYTE);
	string s(packet.begin(), packet.end());
	byte b;
	for (int i = 0; i < s.length(); i++) {
		b = s[i];
		_serial->write(b);
		if (b == STARTBYTE || b == ENDBYTE) 
			_serial->write(b);
	}
	_serial->write(ENDBYTE);
	_serial->write(STARTBYTE);
}

packet_t Port::getPacketFromBuffer() {
	// Check if buffer has complete packet, if so return
	// TODO - implement Port::getPacketFromBuffer
	packet_t testPacket;
	testPacket.packetHeader.flags = 0x0;
	return testPacket;
}
