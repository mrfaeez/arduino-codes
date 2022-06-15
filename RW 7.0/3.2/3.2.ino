const int LED_PIN = 13;

const int IR_PIN = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int irState = digitalRead(IR_PIN);

  digitalWrite(LED_PIN, !irState);

}
