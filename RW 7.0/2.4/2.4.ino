const int buz = 9;

const int maxpwm = 70;

int pwmval;

void setup() {
  // put your setup code here, to run once:
  pinMode(buz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(buz, pwmval);
  pwmval++;

  if(pwmval > maxpwm)
    pwmval = 0;

   delay(50);
}
