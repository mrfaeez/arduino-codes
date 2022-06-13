#define dir_1 5
#define pwm_1 4
#define dir_2 3
#define pwm_2 2
#define dir_3 6
#define pwm_3 7
#define dir_4 10
#define pwm_4 9

void forward() {
  
  analogWrite(pwm_1, 200);
  digitalWrite(dir_1, LOW);
  analogWrite(pwm_2, 200);
  digitalWrite(dir_2, LOW);
  analogWrite(pwm_3, 200);
  digitalWrite(dir_3, LOW);
  analogWrite(pwm_4, 200);
  digitalWrite(dir_4, LOW);
  
}

void backward() {
  
  analogWrite(pwm_1, 0);
  digitalWrite(dir_1, HIGH);
  analogWrite(pwm_2, 0);
  digitalWrite(dir_2, HIGH);
  analogWrite(pwm_3, 0);
  digitalWrite(dir_3, HIGH);
  analogWrite(pwm_4, 0);
  digitalWrite(dir_4, HIGH);
  
}

void setup() {

  pinMode(pwm_1, OUTPUT);
  pinMode(dir_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir_2, OUTPUT);
  pinMode(pwm_3, OUTPUT);
  pinMode(dir_3, OUTPUT);
  pinMode(pwm_4, OUTPUT);
  pinMode(dir_4, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  forward();
  delay(3000);
  //backward();

}
