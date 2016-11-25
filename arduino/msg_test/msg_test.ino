#include <Types.h>
#include <ServiceTable.h>
#include <Port.h>
#include <Service.h>
#include <PacketHandler.h>
#include <Message.h>
#include <PacketQueue.h>
#include <MessageQueue.h>
#include <Comms.h>


/* Arduino sketch for testing messages. To run, set your 
 * sketchbook folder (in preferences) to the parent directory 
 * (rover16/mpq), or copy the Msgs library to the library 
 * folder of your sketchbook. 
 */

// the setup routine runs once when you press reset: 
void setup() {
  Serial.begin(9600);
  Comms test;
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.println("h");
}


