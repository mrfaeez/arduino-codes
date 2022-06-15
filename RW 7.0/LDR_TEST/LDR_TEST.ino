const int LDR_PIN1 = A0;
const int LDR_PIN2 = A1;
const int LDR_PIN3 = A2;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (LDR_PIN1, INPUT);
  pinMode (LDR_PIN2, INPUT);
  pinMode (LDR_PIN3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrVal1 = analogRead(LDR_PIN1);
  int ldrVal2 = analogRead(LDR_PIN2);
  int ldrVal3 = analogRead(LDR_PIN3);

  Serial.print("ldrVal1: ");
  Serial.print(ldrVal1);
  Serial.print(" ");
  Serial.print("ldrVal2: ");
  Serial.print(ldrVal2);
  Serial.print(" ");
  Serial.print("ldrVal3: ");
  Serial.println(ldrVal3);
  delay(2000);



}
