
#include<SoftwareSerial.h>

const int RX_PIN = 0;
const int TX_PIN = 1;

const int LED_PIN = 13;

SoftwareSerial btSerial (RX_PIN, TX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  btSerial.begin (38400);
  Serial.println ("Enter At command : ");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (btSerial.available())
  {
  char input = (btSerial.read());
  if (input == 'A' or input == 'B')
  digitalWrite (LED_PIN, !digitalRead (LED_PIN));
  }
      

}
