/*29/9/2018*/
#include <Servo.h>

const int button = 10;

const int servo = 11;
Servo myservo;
const int MIN_ANGLE = 0, MAX_ANGLE = 180;

int speakerPin = 12;
int length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";
int beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16 };
int tempo = 150;

int a = 2;  //For displaying segment "a"
int b = 3;  //For displaying segment "b"
int c = 4;  //For displaying segment "c"
int d = 5;  //For displaying segment "d"
int e = 6;  //For displaying segment "e"
int f = 8;  //For displaying segment "f"
int g = 9;  //For displaying segment "g"

void setup ()
{
  myservo.attach(servo);
  pinMode (button, INPUT);
  pinMode (speakerPin, OUTPUT);

  pinMode(a, OUTPUT);  //A
  pinMode(b, OUTPUT);  //B
  pinMode(c, OUTPUT);  //C
  pinMode(d, OUTPUT);  //D
  pinMode(e, OUTPUT);  //E
  pinMode(f, OUTPUT);  //F
  pinMode(g, OUTPUT);  //G

}

void turnOff()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void loop()
{
  static int pos=0;
  int buttonstate = digitalRead(button);

  if (buttonstate == 0)
  {


    for (int i = 5; i > 0; i--)
    {
      displayDigit(i);
      delay(1000);
      turnOff();
    }

//    for (pos = MIN_ANGLE; pos <= MAX_ANGLE; pos+100)
//    {
//      myservo.write(pos);
//      delay(15);
//    }

    for (int i = 0; i < length; i++) {

      if (notes[i] == ' ') {

        delay(beats[i] * tempo); // rest

      } else {

        playNote(notes[i], beats[i] * tempo);
        myservo.write(pos);
        delay(15);
        pos=pos+7;
      }

      // pause between notes

      delay(tempo);

    }

  }

}
