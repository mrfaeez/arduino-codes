#include <SoftwareSerial.h>
#include <Servo.h>

const int RX = 11;
const int TX = 10;

int pos = 0;

int last;

SoftwareSerial btSerial (RX, TX);

const int IN_1_LEFT = 8;
const int IN_2_LEFT = 7;
const int IN_3_RIGHT = 4;
const int IN_4_RIGHT = 2;
const int EN_A_LEFT = 5;
const int EN_B_RIGHT = 6;

const int SERVO = 9;
Servo myservo;

const int LDR1 = A0;
const int LDR2 = A1;
const int LDR3 = A2;

const int IR_PIN = 12;

void setup()
{
  Serial.begin (9600);
  pinMode (LDR1, INPUT);
  pinMode (LDR2, INPUT);
  pinMode (LDR3, INPUT);

  btSerial.begin (9600);
  myservo.attach(SERVO);

  pinMode (IN_1_LEFT, OUTPUT);
  pinMode (IN_2_LEFT, OUTPUT);
  pinMode (IN_3_RIGHT, OUTPUT);
  pinMode (IN_4_RIGHT, OUTPUT);
  pinMode (EN_A_LEFT, OUTPUT);
  pinMode (EN_B_RIGHT, OUTPUT);

  pinMode (IR_PIN, INPUT);
}

//motor fucntions start
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
//motor functions end

void loop()
{
  int irstate = digitalRead (IR_PIN);



  myservo.write(pos);

  if (btSerial.available())
  {
    //previousMillis = millis();
    char data = btSerial.read();

    myservo.write(pos);
    if (data == 'A')
    {
      forward(180, 180);
      delay(100);
      stopp();
    }
    else if (data == 'B')
    {
      backward(180, 180);
      delay(100);
      stopp();
    }

    else if (data == 'C')
    {
      left(170, 170);
      delay(100);
      stopp();
    }

    else if (data == 'D')
    {
      right (170, 170);
      delay(100);
      stopp();
    }

    else if (data == 'F')
    {
      pos = pos + 10;
      Serial.println (data);
      Serial.print(" ");
      Serial.println (pos);
      stopp();
    }

    else if (data == 'G') {
      pos = pos - 10;
      Serial.println (data);
      Serial.print(" ");
      Serial.println (pos);
      stopp();

    }

    else if (data == 'M')
    {
      int start = 0;
      while (start == 0) {
        int ldrval1 = analogRead(LDR1);
        int ldrval2 = analogRead(LDR2);
        int ldrval3 = analogRead(LDR3);

        if (ldrval2 >= 256) //ldr2 hitam
        {
          forward(90, 90);
//          last = 2;
        }

        if (ldrval1 >= 254 ) // ldr 1 hitam
        {
          left(110, 110);
          last = 1;
        }

        if (ldrval3 >= 302) // ldr3 hitam
        {
          right (110, 110);
          last = 3;
        }

        if (ldrval1 <= 230 && ldrval2 <= 230 && ldrval3 >= 244) // ldr1&ldr2 putih, ldr3 hitam
        {
          right (110, 110);
          last = 3;
        }

        if (ldrval3 <= 230 && ldrval2 <= 230 && ldrval1 >= 244) // ldr3&ldr2 putih, ldr1 hitam
        {
          left(110, 110);
          last = 1;
        }


        //        else if (ldrval2 >= 256 && ldrval1 >= 284 && ldrval3 >= 254 ) // semua hitam
        //        {
        //          stopp();
        //          delay(5000);
        //        }

        if (last == 1)
          left(110, 110);

//        if (last == 2)
//          forward(90, 90);

        if (last == 3)
          right (110, 110);

        //        else if (irstate == 0)
        //        {
        //          stopp();
        //          delay(1500);
        //          right(100, 100);
        //          delay(200);
        //          forward(110, 110);
        //          delay(500);
        //        }

         if (btSerial.available())
          start = 1;

      }
    }
  }


}
