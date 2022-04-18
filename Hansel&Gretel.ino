/*
AET Arduio P2
Team Name: M&T Faeries
Team Members: Keith, Reece, Yujin
Description: Hansel and Gretel Interactive Piece
*/

#include <Servo.h>

const int doorPin = 3;
const int witchPin = 6;
const int birdPin = 5;

const int birdIn = 2;
const int witchIn = 4;
const int doorIn = 7;

int pos = 0;

Servo doorServo;
Servo witchServo;
Servo birdServo;

void setup() {
  doorServo.attach(doorPin);
  doorServo.write(0);

  witchServo.attach(witchPin);
  witchServo.write(0);

  birdServo.attach(birdPin);
  birdServo.write(0);

  pinMode(birdIn, INPUT);
  pinMode(doorIn, INPUT);
  pinMode(witchIn, INPUT);

  Serial.begin(9600);
}

void loop() {
  birdFlies();
  witchFlips();
  doorOpens();
}

void birdFlies(){
  while(birdIn == LOW){
    
  }
  for (pos=0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}

void witchFlips(){
  while(witchIn == LOW){
    
  }
  witchServo.write(180);
}

void doorOpens(){
  while(doorIn == LOW){
  }

  doorServo.write(90);
  doorServo.write(180);
}