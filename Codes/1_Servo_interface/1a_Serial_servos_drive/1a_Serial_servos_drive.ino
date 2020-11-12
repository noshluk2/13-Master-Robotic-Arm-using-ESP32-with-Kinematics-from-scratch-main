/*
- Install ESP32 Servo Library
- Setup All servo motors
- Read From serial about angles
- Turn Servo Motors according to input

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
    
  if (motor == 1){servo1.write(angle); Serial.println("Driving Servo 1  ");}
  if (motor == 2){servo2.write(angle); Serial.println("Driving Servo 2  ");}
  if (motor == 3){servo3.write(angle); Serial.println("Driving Servo 3  ");}
  if (motor == 4){servo4.write(angle); Serial.println("Driving Servo 4  ");}
}

}

  