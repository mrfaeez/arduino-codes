void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    char inputChar = Serial.read();
    Serial.println(inputChar);
    if(inputChar == 'i')
      Serial.println("character i");
    }
}
