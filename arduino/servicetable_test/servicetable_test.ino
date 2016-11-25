#include <Types.h>
#include <ServiceTable.h>
#include <Port.h>
#include <Comms.h>
#include <Service.h>
#include <PacketHandler.h>
#include <Message.h>
#include <PacketQueue.h>
#include <MessageQueue.h>

#include <HardwareSerial.h>
#include <serstream>
#include <string>
#include <sstream>

#include <stdlib.h> // for malloc
void* operator new(unsigned int size, void* v) { return malloc(size); }

ServiceTable table;
ohserialstream serial(Serial);

void setup() {
  serial.begin(9600);
  Service s(3, "myService");
  table.addService(&s);
  s.setPortDistance(1, 3);
  ServiceTable table2;
  Service s2(5, "myOtherService");
  table2.addService(&s2);
  table.mergeTable(table2);
}

void loop() {
  serial << table.toString() << endl;
 // delay(1000);
}
