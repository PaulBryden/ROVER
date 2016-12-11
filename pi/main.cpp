
#include <Comms.h>
#include <Comms.cpp>
#include <unistd.h>


#include <PortPi.cpp>
#include <string>

//extern MessageQueue messageQueue;
//extern vector<Port> portList;
//extern ServiceTable serviceTable;
//extern PacketHandler handle;
/*vector<Port> portList;
ServiceTable serviceTable;*/
PacketHandler handle;

static std::map<int,int> servicePortMap; //WIll be specific to individual arduino boards... simple translation to serial1,2,3,etc.
#include <stdlib.h> // for malloc


/* Arduino sketch for testing messages. To run, set your 
 * sketchbook folder (in preferences) to the parent directory 
 * (rover16/mpq), or copy the Msgs library to the library 
 * folder of your sketchbook. 
 */
	static Comms newComms;
  static Port p0(0);
 /* static Port p2(1, &Serial2);
  static Port p3(2, &Serial3);*/
// the setup routine runs once when you press reset: 
void setup() {
  /**Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);**/
	Comms newComms;


  //Service s3(3, "Service3", true);
  //Service s5(5, "Service5", false);
  //serviceTable.addService(&s3);
  //serviceTable.addService(&s5);
  
  //s5.setPortDistance(2, 1); // port 3, distance 1
  
}

// the loop routine runs over and over again forever:
void loop() {
  p0.read();
cout <<"Loop";
  usleep(10000);
}

int main(){
setup();
while(true){

loop();

}

return 1;
}



