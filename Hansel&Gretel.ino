/*
AET Arduio P2
Team Name: M&T Faeries
Team Members: Keith, Reece, Yujin
Description: Hansel and Gretel Interactive Piece
*/

#include <Servo.h>

//Youtube Link: https://youtu.be/J3CR9XhoJNA
//Final Product: https://youtu.be/Y9ZcG4om1NY

const int doorPin = 3;
const int witchPin = 6;
const int birdPin = 5;
const int ledPin = 11;

const int fireIn = 8;
const int birdIn = 2;
const int witchIn = 4;
const int doorIn = 7;

int birdPos = 0;
int fadeAmount = 5;
int brightness = 0;

bool one_time_high = true;
bool one_time_low = true;
int witchPos = 0;

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
  pinMode(ledPin, OUTPUT);

  analogWrite(ledPin, 0);

  Serial.begin(9600);
  Serial.println("Starting");
}

void loop() {
  birdFlies();
  fireGlowing();
  witchFlips();
  doorOpens();
  reset();
}

void birdFlies(){
  //Serial.print("Waiting for input from bird...");
  while(digitalRead(birdIn) == LOW){
  }
    Serial.println("birding");
    for (birdPos=0; birdPos <= 180; birdPos += 1) {
      birdServo.write(birdPos);
      delay(15);
    }
    for (birdPos = 180; birdPos >= 0; birdPos -= 1) {
      birdServo.write(birdPos);
      delay(15);
    }
}

void witchFlips(){
  for (witchPos = 180; witchPos >= 0; witchPos -= 1) { // goes from 180 degrees to 0 degrees
          witchServo.write(witchPos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
  }      
  while(digitalRead(witchIn) == LOW){
  }
  //digitalWrite(ledPin, HIGH);
  for (witchPos=0 ; witchPos <= 180; witchPos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    witchServo.write(witchPos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void fireGlowing(){
  int change = 1;
  int fire = 1;
  //Serial.println("fire starting");
  while(digitalRead(fireIn) == LOW){
  }
  //Serial.println("fire glowing");
  while(digitalRead(witchIn) == LOW){
    analogWrite(ledPin, brightness);
    Serial.println(brightness);
    brightness = brightness + fadeAmount;
    if(brightness <= 0 || brightness >= 255){
      fadeAmount = -fadeAmount;
    }
    delay(30);
  }
  analogWrite(ledPin, HIGH);
  
}

void doorOpens(){
  //Serial.print("Waiting for input from door...");
  while(digitalRead(doorIn) == LOW){
  }
    Serial.println("dooring");
    //doorServo.write(90);
    doorServo.write(180);
    delay(3000);
    doorServo.write(0);
//    Serial.println("dooring");
//    doorServo.write(90);
//    doorServo.write(180);
}

void reset(){
  for (witchPos = 180; witchPos >= 0; witchPos -= 1) { // goes from 180 degrees to 0 degrees
          witchServo.write(witchPos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
  }      
  birdServo.write(0);
  doorServo.write(0);
  digitalWrite(ledPin, LOW);
}