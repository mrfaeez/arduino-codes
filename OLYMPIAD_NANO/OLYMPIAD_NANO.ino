#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleEsp8266.h>

#include <dht.h>
#define dht_apin A2

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
dht DHT;

char auth[] = "AuthTokenNano";
char ssid[] = "NetworkNano";
char pass[] = "PasswordNano";

WidgetBridge bridge1(V1);

BLYNK_CONNECTED() {
  
  // Place the AuthToken of the Uno here
  bridge1.setAuthToken("AuthTokenUno");
}

void sendSensor() {
  // get readings from the DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send command to the second ESP
  // WHEN Temperature IS OVER 28 C
  // in order to open the 220V Relay
  // Also update the VIRTUAL port 5
  // on the second ESP
  if (t > 28) {
    bridge1.digitalWrite(2, HIGH);
    bridge1.virtualWrite(V5, h);
    bridge1.digitalWrite(3, HIGH);
    bridge1.virtualWrite(V6, t);
  } 
  
  else {
    bridge1.digitalWrite(2, 0);
    bridge1.virtualWrite(V5, 0);
    bridge1.digitalWrite(3, 0);
    bridge1.virtualWrite(V6, 0);
  }

  // Send temperature and humidity to Blynk App
  // on VIRTUAL ports 5 and 6 in order to
  // display on Gauge Widget
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup() {

  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  delay(500);//Wait before accessing Sensor
  dht.begin();
  lcd.begin (16, 2);
  lcd.backlight();
  lcd.clear();
}

void loop() {

  DHT.read11(dht_apin);

  float humid = DHT.humidity;
  float temper = DHT.temperature;

  lcd.print ((String)"The temperature is : " + temper + " C");
  delay (1000);
  lcd.print ((String)"The humidity is : " + humid);
  delay (1000);
  lcd.clear();

  Blynk.run();

}
