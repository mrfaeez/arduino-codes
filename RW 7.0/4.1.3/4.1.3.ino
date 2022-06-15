const int IN_1_LEFT = 11;
const int IN_2_LEFT = 9;
const int IN_3_RIGHT = 5;
const int IN_4_RIGHT = 3;
const int LDR_PIN1 = A0;
const int LDR_PIN2 = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode (IN_1_LEFT, OUTPUT);
  pinMode (IN_2_LEFT, OUTPUT);
  pinMode (IN_3_RIGHT, OUTPUT);
  pinMode (IN_4_RIGHT, OUTPUT);
  pinMode (LDR_PIN1, INPUT);
  pinMode (LDR_PIN2, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int ldrVal1 = analogRead(LDR_PIN1);
  int ldrVal2 = analogRead(LDR_PIN2);

  Serial.print("ldrVal1: ");
  Serial.print(ldrVal1);
  Serial.print(" ");
  Serial.print("ldrVal2: ");
  Serial.println(ldrVal2);

  if (ldrVal1 < 600 && ldrVal2 < 600)
  {
    forwardleft();
    forwardright();
  }

  else if (ldrVal1 < 600 )
  {
    forwardright();
  }

  else if (ldrVal2 < 600)
  {
    forwardleft();


  }

}
