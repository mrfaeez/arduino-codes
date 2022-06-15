#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int LDR1 = A0;//red
const int LDR2 = A1;//blue
const int LDR3 = A2;


void setup() {
  // put your setup code here, to run once:
  pinMode (LDR1, INPUT);
  pinMode (LDR2, INPUT);
  Serial.begin (9600);

  lcd.begin (16, 2);
  lcd.backlight();
  lcd.clear();


}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrVal = analogRead (LDR1);
  int ldrVal2 = analogRead (LDR2);
  
  lcd.setCursor (0,0);
  lcd.print (ldrVal);
  //delay (500);
  //lcd.clear();

  lcd.setCursor (0,1);
  lcd.print (ldrVal2);
  delay (500);
  lcd.clear();
  
  
 
  Serial.print ("ldrVal1 : ");
  Serial.print (ldrVal);
  


}
