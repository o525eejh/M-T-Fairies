/*
AET Hansel and Gretel Enclosure
Team Name: M&T Fairies
Team Members: Reece, Yujin, and Keith
Description: button and servo program
 */

#include <Servo.h>
#define SW 7

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

bool one_time_high=true;
bool one_time_low=true;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(SW, INPUT);
}

void loop() {
  if(digitalRead(SW)==LOW)
  {
      Serial.print("sw:LOW");
      Serial.print(",one_time_low=");
      Serial.print(one_time_low,DEC);
      Serial.print(",one_time_high=");
      Serial.print(one_time_high,DEC);
      
      if(one_time_low)
      {

        for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
           myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }      
        one_time_high = true;
        one_time_low = false;
      }
  }
  else
  {
      Serial.print("sw:HIGH");    
      Serial.print(",one_time_low=");
      Serial.print(one_time_low,DEC);
      Serial.print(",one_time_high=");
      Serial.print(one_time_high,DEC);
      if(one_time_high)
      {
        for (pos=0 ; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
        one_time_high = false;
        one_time_low = true;
      }
      //for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      //  myservo.write(pos);              // tell servo to go to position in variable 'pos'
      //  delay(15);                       // waits 15ms for the servo to reach the position
      //}
  }
  Serial.print("\n");
  delay(1); 
}
