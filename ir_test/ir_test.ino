const int IR = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (IR, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int irstate = digitalRead(IR);

  Serial.println(irstate);

}
