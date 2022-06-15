
const int LED = 2;

unsigned long previousMillis;
int ledstate;

void setup() {
  // put your setup code here, to run once:

  pinMode (LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - previousMillis > 1000)
  {
    ledstate = !ledstate;
    digitalWrite (LED, ledstate);
    previousMillis = millis();
  }

}
