
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.print("ME: ");
    while (Serial.available()) {
      delay(3);
      byte b = Serial.read();
      Serial1.write(b);
      Serial.write(b);
    }
    Serial.println();
  }
  if (Serial1.available()) {
    Serial.print("PAUL: ");
    while (Serial1.available()) {
      delay(3);
      Serial.write(Serial1.read());
    }
    Serial.println();
  }
}

