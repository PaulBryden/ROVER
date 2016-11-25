// To use this example, you have to connect Rx pin (digital pin 0) to interrupt 0 pin (digital pin 2).
void setup()
{
   // Using interrupt 0 on digital pin 2.
   pinMode(2, INPUT);
   digitalWrite(2, LOW);
   
   Serial.begin(9600);
   attachInterrupt(0, serialInterrupt, CHANGE);

   // Used to signal that main loop is alive.
   pinMode(4, OUTPUT);
   digitalWrite(4, LOW);

   // Used to signal that Serial input was read.
   pinMode(5, OUTPUT);
   digitalWrite(5, LOW);
}

void loop()
{
 // Do something using even delays. There is an interrupt for that (Serial I/O)!

 // Blink led to signal loop is alive.
 digitalWrite(4, HIGH);
 delay(500);
 
 digitalWrite(4, LOW);
 delay(500);
}

// Volatile, since it is modified in an ISR.
volatile boolean inService = false;

void serialInterrupt()
{
 // Trick: since Serial I/O in interrupt driven, we must reenable interrupts while in this Interrupt Service Routine.
 // But doing so will cause the routine to be called nestedly, causing problems.
 // So we mark we are already in service.

 // Already in service? Do nothing.
 if (inService) return;

 // You was not in service. Now you are.
 inService = true;
 
 // Reenable interrupts, to allow Serial to work. We do this only if inService is false.
 interrupts();
 
 // Allow serial to read at least one byte.
 while(!Serial.available());

 // Blink led to signal Serial data arrived.
 digitalWrite(5, !digitalRead(5));
 byte data = Serial.read();

 // Echo data back to developer ;-)
 Serial.print(data);

 // Job done.
 inService = false;
}