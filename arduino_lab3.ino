// ─────────────────────────────────────────────────────────────────
//  Rack and Pinion Gear Lab - DEMO
// ─────────────────────────────────────────────────────────────────
#include <Servo.h>
int servoPin = 9; //replace 9 with which pin you used
Servo servo; //creates servo project
int angle = 0; //initial angle, degrees
void setup() {
  Serial.begin(9600); //establishes communication speed for controller and computer
  servo.attach(servoPin); //initializes connection from motor to pin
}
void loop()
{
 //scan for degrees
 for(angle = 0; angle < 120; angle++)
 {
   servo.write(angle);
   delay(20);
 }
 //scan in reverse
 for(angle = 120; angle > 0; angle--)
 {
   servo.write(angle);
   delay(20);
 }
}
