/*
- Add Forloops to iterate over angles with delay
- Enjoy smooth servo motion known as sweep
- There is a problem with sweeping :)

Author : Muhammad Luqman
Date   : 15-10-2020
License: MIT

*/

//new library from this link https://randomnerdtutorials.com/esp32-servo-motor-web-server-arduino-ide/

#include <ESP32Servo.h> 
static const int servoPin1 = 18;
static const int servoPin2 = 5;
static const int servoPin3 = 17;
static const int servoPin4 = 16;
int motor,angle;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
void setup() {
    Serial.begin(115200);
    servo1.attach(servoPin1);
    servo2.attach(servoPin2);
    servo3.attach(servoPin3);
    servo4.attach(servoPin4);

}

void loop() {
  if (Serial.available() > 0) {
    String first  = Serial.readStringUntil(',');
    String second = Serial.readStringUntil('\0');
  
    motor=first.toInt();
    angle=second.toInt();
  if (motor == 1){ 
     Serial.println("Driving Servo 1  ");
      for (int pos = 0; pos <= angle; pos += 1)
      {servo1.write(pos);delay(15);}}
      
  if (motor == 2){  Serial.println("Driving Servo 2  "); for (int pos = 0; pos <= angle; pos += 1) {servo2.write(pos);delay(15);}}
  if (motor == 3){  Serial.println("Driving Servo 3  "); for (int pos = 0; pos <= angle; pos += 1) {servo3.write(pos);delay(15);}}
  if (motor == 4){  Serial.println("Driving Servo 4  "); for (int pos = 0; pos <= angle; pos += 1) {servo4.write(pos);delay(15);}}
  }


}
  
