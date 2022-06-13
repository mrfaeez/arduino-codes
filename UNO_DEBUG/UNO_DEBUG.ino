#include <SoftwareSerial.h>
SoftwareSerial BTSerial(A4, A5);

// initialize variable to store value send from master
int temp = 0;
// use pin _ for Infrared(IR) sensor
const int IRPin = A3;
// variable to store value of IR sensor
int IRValue = 0;
//creates memory to remember whether the robot had moved to the plant or not
bool memory = 0;

void setup() {
  //set pin mode IR sensor to input as it receive value
  pinMode(IRPin, INPUT);
  //begin serial monitor with baud rate 9600
  Serial.begin(9600);
  //begin serial monitor with baud rate 9600
  BTSerial.begin(38400);
  delay(500);
    Serial.println ("enter at command : ");

}

void loop() {
//
  IRValue = digitalRead(IRPin);
//  Serial.print("IRVALUE : ");
//  Serial.println(IRValue);

    if(BTSerial.available()){
      temp = BTSerial.read();
      Serial.print("The temperature is : ");
      Serial.println(temp);
    }

    if(temp > 20 && IRValue == 1)
      Serial.println("ABOVE 20");

    else if(temp > 20 && IRValue == 0)
      Serial.println("ABOVE 20 and HAVE BLOCKAGE");
    
    temp = 0;
//    if (Serial.available())
//    BTSerial.write (Serial.read());
//
//   if(BTSerial.available())
//    Serial.write (BTSerial.read()); 

  
}
