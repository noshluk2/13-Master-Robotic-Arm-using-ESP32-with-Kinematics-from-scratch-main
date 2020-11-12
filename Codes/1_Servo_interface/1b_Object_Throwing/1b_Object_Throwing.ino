/*
- Read angles after delay
- Try your best to create motion so it throws the object

Author : Muhammad Luqman
Date   : 15-10-2020
License: MIT

*/


#include <ESP32Servo.h> 

const int servoPin1 = 18;
const int servoPin2 = 5;
const int servoPin3 = 17;
const int servoPin4 = 16;
//ultrasonic sensor pins
const int trigger = 13;
const int echo= 15;

int motor,angle;
long duration;
int distance;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
void setup() {
  Serial.begin(115200);
  pinMode(trigger, OUTPUT); 
  pinMode(echo, INPUT);
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  get_in_position();delay(3000);
}

void loop() {
    get_distance();
  if(distance<10){
    throw_object();
  }

}

void get_distance(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance= duration*0.034/2;
  // Serial.print("Current Distance = ");
  // delay(500);
  // Serial.println(distance);
}
void get_in_position(){
  //get to holding positing=
  servo2.write(50);delay(500);
  servo3.write(50);delay(500);
  servo4.write(15);delay(500);
  servo1.write(0);delay(1000);
}

void throw_object(){

  //hold the object
  servo1.write(30);delay(1000);
  //move towards the bin
  servo2.write(150);delay(1000);
  servo3.write(0);delay(1000);
  servo4.write(60);delay(1000);
  //Drop the object
  servo1.write(0);delay(3000);
  //return to basic position
  get_in_position();
}

  
