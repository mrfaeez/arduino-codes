const int BUZZER_PIN = 9;

const int POT_PIN = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal = analogRead(POT_PIN);
  potVal = map(potVal, 0, 1023, 0, 255);

  analogWrite(BUZZER_PIN, potVal);
}
