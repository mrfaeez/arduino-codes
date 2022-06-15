// ---------------- LCD I2C ----------------- //


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //set LCD address
const int POT_PIN = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin (16, 2);
  lcd.backlight();
  lcd.clear();
  pinMode (POT_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potval = analogRead (POT_PIN);
  lcd.print (potval);
  delay (100);
  lcd.clear();
  Serial.println(potval);
}
