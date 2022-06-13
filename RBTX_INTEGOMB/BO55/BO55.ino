int pos = 0;

int last;

const int IN_1_LEFT = 12;
const int IN_2_LEFT = 8;
const int IN_3_RIGHT = 13;
const int IN_4_RIGHT = 9;
const int EN_A_LEFT = 10;
const int EN_B_RIGHT = 11;

const int IR1_FARLEFT = A0;
const int IR2_ LEFT = A1;
const int IR3_MID = A2;
const int IR4_RIGHT = A3;
const int IR5_FARRIGHT = A4;

const int LED = A5;

const int LDR = 5;

void setup() {
  Serial.begin (9600);
  pinMode (IR1_FARLEFT, INPUT);
  pinMode (IR2_LEFT, INPUT);
  pinMode (IR3_MID, INPUT);
  pinMode (IR4_RIGHT, INPUT);
  pinMode (IR5_FARRIGHT, INPUT);

  pinMode (IN_1_LEFT, OUTPUT);
  pinMode (IN_2_LEFT, OUTPUT);
  pinMode (IN_3_RIGHT, OUTPUT);
  pinMode (IN_4_RIGHT, OUTPUT);
  pinMode (EN_A_LEFT, OUTPUT);
  pinMode (EN_B_RIGHT, OUTPUT);

  pinMode (IR_PIN, INPUT);

}

void forward(int pwmLeft, int pwmRight)
{
  digitalWrite (IN_1_LEFT, HIGH);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, LOW);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void backward (int pwmLeft, int pwmRight)
{
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, HIGH);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, LOW);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void left (int pwmLeft, int pwmRight)
{
  digitalWrite (IN_1_LEFT, HIGH);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, LOW);
  digitalWrite (IN_4_RIGHT, LOW);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void right (int pwmLeft, int pwmRight)
{
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, pwmLeft);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, LOW);
  analogWrite (EN_B_RIGHT, pwmRight);
}

void stopp ()
{
  digitalWrite (IN_1_LEFT, LOW);
  digitalWrite (IN_2_LEFT, LOW);
  analogWrite (EN_A_LEFT, 0);
  digitalWrite (IN_3_RIGHT, HIGH);
  digitalWrite (IN_4_RIGHT, HIGH);
  analogWrite (EN_B_RIGHT, 0);
}

void loop()
{
  int irstate = digitalRead (IR_PIN);

  int ldrval1 = analogRead(LDR1);
  int ldrval2 = analogRead(LDR2);
  int ldrval3 = analogRead(LDR3);


  if (ldrval2 >= 256) //ldr2 hitam
  {
    forward(150, 150);
    last = 2;
  }

  else if (ldrval1 >= 284) // ldr 1 hitam
  {
    left(150, 150);
    last = 1;
  }

  else if (ldrval3 >= 302) // ldr3 hitam
  {
    right (150, 150);
    last = 3;
  }

  else if (ldrval1 <= 230 && ldrval2 <= 230 && ldrval3 >= 302) // ldr1&ldr2 putih, ldr3 hitam
  {
    right (150, 150);
    last = 3;
  }

  else if (ldrval3 <= 230 && ldrval2 <= 230 && ldrval1 >= 284 ) // ldr3&ldr2 putih, ldr1 hitam
  {
    left(150, 150);
    last = 1;
  }

  else if (ldrval2 >= 256 && ldrval1 >= 284 && ldrval3 >= 302) // semua hitam
  {
    stopp();
    delay(5000);
  }

 

}
