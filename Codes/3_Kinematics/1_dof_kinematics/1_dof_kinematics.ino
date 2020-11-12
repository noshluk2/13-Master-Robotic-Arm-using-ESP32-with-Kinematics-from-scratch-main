/*
  Code First Takes
  - Serial Input , angles of joint ( 1DOF_2nd link)
  - Prints on Serial X Y values in Cartesian Space.
  - Then Fast move the Robot


Author : Muhammad Luqman
Date   : 14-10-2020
License: MIT

*/

#include <ESP32Servo.h> 
static const int servoPin1 = 17;
int servo_angle;
Servo servo1;
double x,y;
float l= 12.5;
void setup() {
    Serial.begin(115200);
    servo1.attach(servoPin1);
}

void loop() {
  if (Serial.available() > 0) {
    String first  = Serial.readStringUntil('\0');  
    servo_angle=first.toInt();
    Serial.println(servo_angle);
    // Understnad these equations of right angle triangle in output

    x=l * (cos(servo_angle/57.26 )) ;  // input radians ---> coverted degrees to radian first
    y=l * (sin(servo_angle/57.29 ));


    Serial.print(x);Serial.print(" | ");Serial.println(y);

    servo1.write(servo_angle);
}
  
}
