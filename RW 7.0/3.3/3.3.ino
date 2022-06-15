const int ECHO_PIN = 9;
const int TRIG_PIN = 10;
const float SOUND_SPEED = 0.034;

void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);
pinMode (ECHO_PIN, INPUT);
pinMode (TRIG_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (TRIG_PIN, LOW);
delayMicroseconds (2);
digitalWrite (TRIG_PIN, HIGH);
delayMicroseconds (10);
digitalWrite (TRIG_PIN, LOW);

long duration = pulseIn (ECHO_PIN, HIGH);
int distance = (duration*SOUND_SPEED)/2;

Serial.print ("Distance : ");
Serial.println (distance);

}
