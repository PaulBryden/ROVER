#include <PortIPAddr.h>
#include <Comms.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include <thread>         // std::thread
//#include <mutex>          // std::mutex

#define PORT 1153
#define BUFSIZE 128

struct sockaddr_in myaddr;      /* our address */
struct sockaddr_in remaddr;     /* remote address */
socklen_t addrlen = sizeof(remaddr);            /* length of addresses */
int recvlen;                    /* # bytes received */
int fd;                         /* our socket */
//std::mutex mtx;           // mutex for critical section

PortIPAddr::PortIPAddr(int id) {
	_id = id;
	_buffer.reserve(BUFSIZE);
	  if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
                perror("cannot create socket\n");
        }

        /* bind the socket to any valid IP address and a specific port */

        memset((char *)&myaddr, 0, sizeof(myaddr));
		remaddr.sin_family = AF_INET;
		remaddr.sin_addr.s_addr = inet_addr("192.168.1.1");
		remaddr.sin_port = htons(PORT);
		
        myaddr.sin_family = AF_INET;
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
        myaddr.sin_port = htons(PORT);
		if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
                perror("bind failed");

        }
}

void PortIPAddr::read() {
	//mtx.lock();
	recvlen = recvfrom(fd, _buffer.data(), BUFSIZE, 0, (struct sockaddr *)&remaddr, &addrlen);
	//mtx.unlock();
}

void PortIPAddr::write(vector<byte> packet) {
	//mtx.lock();
	printf( "test");
	sendto(fd, packet.data(), packet.size(), 0, (struct sockaddr *)&remaddr, addrlen);
	//mtx.unlock();
}

packet_t PortIPAddr::getPacketFromBuffer() {
	// Check if buffer has complete packet, if so return
	// TODO - implement Port::getPacketFromBuffer
	packet_header_t tempPacketHeader;
	tempPacketHeader.flags=_buffer[0] & 0x7;
	tempPacketHeader.messageID=_buffer[0] & 0x1F;
	tempPacketHeader.targetService=_buffer[1];
	tempPacketHeader.sourceService=_buffer[2];
	tempPacketHeader.packetID=_buffer[3];
	tempPacketHeader.crc=_buffer[4];
	packet_t testPacket;
	testPacket.packetHeader=tempPacketHeader;
	
	testPacket.dataContent.reserve(59);
	for(int i=5;i<_buffer.size();i++){
		
		testPacket.dataContent.push_back(_buffer[i]);
	}
	
	return testPacket;
}
