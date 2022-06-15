const int led = 2;
unsigned long prevmil;
int ledstate;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - prevmil > 500){
    ledstate = !ledstate;
    digitalWrite(led, ledstate);
    prevmil = millis();
  }
}
