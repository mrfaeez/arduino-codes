#include <SoftwareSerial.h>

const int RX_PIN = 11;
const int TX_PIN = 10;

SoftwareSerial btSerial (RX_PIN, TX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  btSerial.begin (38400);
  Serial.println ("enter at command : ");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
    btSerial.write (Serial.read());

   if (btSerial.available())
    Serial.write (btSerial.read()); 

}
