const int LED_PIN = 7;

const int LDR_PIN = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(LDR_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrVal = analogRead(LDR_PIN);

  if(ldrVal <= 100)
    digitalWrite(LED_PIN, HIGH);

   else
    digitalWrite(LED_PIN, LOW);
}
