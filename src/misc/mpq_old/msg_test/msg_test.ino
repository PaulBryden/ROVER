/* Arduino sketch for testing messages. To run, set your 
 * sketchbook folder (in preferences) to the parent directory 
 * (rover16/mpq), or copy the Msgs library to the library 
 * folder of your sketchbook. 
 */

#include <Msgs.h>

service_t a = {1, "srv1", 1, 1};
service_t b = {2, "srv2", 2, 0};
message_t m = {&a, &b, "hello"};

Msgs msgs;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  msgs.readMessage(&m);
}


