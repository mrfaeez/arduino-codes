int count;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("This code run once");

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("This code run repeatedly");
  Serial.println(count++);
}
