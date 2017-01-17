
#include <Comms.h>
#include <HardwareSerial.h>
#include <SerialPort.h>
#include <string>
#include <pnew.cpp>

//extern MessageQueue messageQueue;
//extern vector<Port> portList;
//extern ServiceTable serviceTable;
//extern PacketHandler handle;

static std::map<int,int> servicePortMap; //WIll be specific to individual arduino boards... simple translation to serial1,2,3,etc.
#include <stdlib.h> // for malloc


/* Arduino sketch for testing messages. To run, set your 
 * sketchbook folder (in preferences) to the parent directory 
 * (rover16/mpq), or copy the Msgs library to the library 
 * folder of your sketchbook. 
 */

  static SerialPort p0(0, &Serial);
	
// the setup routine runs once when you press reset: 
void setup() {

  Serial.println("Initializing");
	static string service1String ="Service1";
	static string service2String= "Service2";
	static Service s1(0, service1String,true);
	static Service s2(1, service2String,false); //NEEDS TO BE STATIC !!! once function ends, the object memory will be deallocated otherwise!!!
	serviceTable.addService(&s1);
	serviceTable.addService(&s2);

	s1.setPortDistance(0,0);
	s2.setPortDistance(0,1);
	portList.push_back(&p0);
}

// the loop routine runs over and over again forever:
void loop() {
  p0.read();
  
  Serial.println("Loop");
}





