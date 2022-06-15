//const int EN_A_LEFT = 6;
const int IN_1_LEFT = 11;
const int IN_2_LEFT = 9;
//const int EN_B_RIGHT = 5;
const int IN_3_RIGHT = 5;
const int IN_4_RIGHT = 3;



void setup() {
  // put your setup code here, to run once:
  pinMode (IN_1_LEFT, OUTPUT);
  pinMode (IN_2_LEFT, OUTPUT);
  //pinMode (EN_A_LEFT, OUTPUT);
  pinMode (IN_3_RIGHT, OUTPUT);
  pinMode (IN_4_RIGHT, OUTPUT);
  //pinMode (EN_B_RIGHT, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  forward (100,100);
  delay (1000);
  forward (200,200);
  delay (1000);
  forward (0,0);
  delay (1000);
  forward (255,255);
  delay (1000);
 

}
