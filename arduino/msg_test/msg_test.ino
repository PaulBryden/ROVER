#include <Types.h>
#include <ServiceTable.h>
#include <Port.h>
#include <Service.h>
#include <PacketHandler.h>
#include <Message.h>
#include <PacketQueue.h>
#include <MessageQueue.h>
#include <Comms.h>

#include <string>

//extern MessageQueue messageQueue;
//extern vector<Port> portList;
//extern ServiceTable serviceTable;
//extern PacketHandler handle;
MessageQueue messageQueue;
vector<Port> portList;
ServiceTable serviceTable;
PacketHandler handle;


#include <stdlib.h> // for malloc
void* operator new(unsigned int size, void* v) { 
  return malloc(size); 
}

/* Arduino sketch for testing messages. To run, set your 
 * sketchbook folder (in preferences) to the parent directory 
 * (rover16/mpq), or copy the Msgs library to the library 
 * folder of your sketchbook. 
 */

// the setup routine runs once when you press reset: 
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  Comms comms;
  
  Port p1(0, &Serial1);
  Port p2(1, &Serial2);
  Port p3(2, &Serial3);
  Port* ports[] = {&p1, &p2, &p3};
  Serial.println("KILL ME");
  //p1.write((vector<byte>){'H','E','L','L'});
  delay(2000);
  
  comms.initialiseNode(ports);
  Serial.println("HELP");
  
  Service s3(3, "Service3", true);
  Service s5(5, "Service5", false);
  serviceTable.addService(&s3);
  serviceTable.addService(&s5);
  
  s5.setPortDistance(2, 1); // port 3, distance 1
  
}

// the loop routine runs over and over again forever:
void loop() {
  Service* s = serviceTable.getService(5);
  //Serial.println(s->getName())
  Serial.print("Port ");
  //Serial.println(s->getOutgoingPort()._id);
  Serial.print("Distance ");
  //Serial.println(s->getShortestDistance());
  delay(2000);
}


