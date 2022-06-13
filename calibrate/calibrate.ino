int maxl = 0;
int maxc = 0;
int maxr = 0;
int minl = 1023;
int minc = 1023;
int minr = 1023;

const int LDR1 = A0;
const int LDR2 = A1;
const int LDR3 = A2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (LDR1, INPUT);
  pinMode (LDR2, INPUT);
  pinMode (LDR3, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
