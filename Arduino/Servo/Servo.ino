#include <Servo.h>

Servo myServo;
int cwPin = 7;
int acwPin = 6;
int servoPin = 5;
int pos = 0;

void setup(){
  pinMode(cwPin, INPUT);
  pinMode(acwPin, INPUT);
  pinMode(servoPin, OUTPUT);
  myServo.attach(servoPin);
}

void loop(){
  if(digitalRead(cwPin)==HIGH && pos <= 160){
    pos++;
    myServo.write(pos);
    delay(15);
  } else if(digitalRead(acwPin)==HIGH && pos >= 30){
    pos--;
    myServo.write(pos);
    delay(15);
  } 
}