#include <SoftwareSerial.h>
#include <Servo.h>

const int RX = 11;
const int TX = 10;

int pos = 0;

SoftwareSerial btSerial (RX, TX);

const int IN_1_LEFT = 8;
const int IN_2_LEFT = 7;
const int IN_3_RIGHT = 4;
const int IN_4_RIGHT = 2;
const int EN_A_LEFT = 5;
const int EN_B_RIGHT = 6;

const int SERVO = 9;
Servo myservo;

unsigned long previousMillis;

void setup() {

  Serial.begin (9600);
  btSerial.begin (9600);
  myservo.attach(SERVO);

  pinMode (IN_1_LEFT, OUTPUT);
  pinMode (IN_2_LEFT, OUTPUT);
  pinMode (IN_3_RIGHT, OUTPUT);
  pinMode (IN_4_RIGHT, OUTPUT);
  pinMode (EN_A_LEFT, OUTPUT);
  pinMode (EN_B_RIGHT, OUTPUT);

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


void loop() {

  myservo.write(pos);

  if (btSerial.available())
  {
    //previousMillis = millis();
    char data = btSerial.read();

    myservo.write(pos);
    if (data == 'A')
    {
      forward(255, 255);
      delay(100);
      stopp();
    }
    else if (data == 'B')
    {
      backward(250, 250);
      delay(100);
      stopp();
    }

    else if (data == 'C')
    {
      left(150, 150);
      delay(100);
      stopp();
    }

    else if (data == 'D')
    {
      right (150, 150);
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
    

  }
  //stopp();
}
