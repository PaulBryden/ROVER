#include <Comms.h>


/* Arduino sketch for testing messages. To run, set your 
 * sketchbook folder (in preferences) to the parent directory 
 * (rover16/mpq), or copy the Msgs library to the library 
 * folder of your sketchbook. 
 */

#include <Comms.h>
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Comms test;
}

// the loop routine runs over and over again forever:
void loop() {
}


