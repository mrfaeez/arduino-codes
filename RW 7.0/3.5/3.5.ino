#include <Servo.h>

const int SERVO_PIN = 9;
const int MIN_ANGLE = 0, MAX_ANGLE = 180;

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(SERVO_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:
  static int pos;

  for(pos = MIN_ANGLE;pos <= MAX_ANGLE; pos++) {
    myservo.write(pos);
    delay(15);
  }

  for(pos = MAX_ANGLE;pos >=MIN_ANGLE; pos--) {
    myservo.write(pos);
    delay(15);
  }
}
