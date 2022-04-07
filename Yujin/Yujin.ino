/*
AET Arduio P2
Team Name: M&T Faeries
Team Members: Keith, Reece, Yujin
Description: Hansel and Gretel Interactive Piece
*/

//Servo Code library
#include<Servo.h>

//VARIABLES
Servo myServo;
const int buttonPin = 7;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}
