/*
  Code First Takes
  - Serial Input , angles of joints
  - Calculate the forward kinematics 
  - Prints on Serial X Y Z values in Cartesian Space.
  - Then Slowly Move the Robot


Author : Muhammad Luqman
Date   : 14-10-2020
License: MIT

*/



#include <ESP32Servo.h> 
static const int servoPin1 = 5;
static const int servoPin2 = 17;
static const int servoPin3 = 16;

int theta_1,theta_2,theta_3;
Servo servo1;
Servo servo2;
Servo servo3;
double x,y,z;
float l_1= 19.1;float l_2=15.69;float l_3=11.7;  // in centimeters
void setup() {

    Serial.begin(115200);
    servo1.attach(servoPin1);
    servo2.attach(servoPin2);
    servo3.attach(servoPin3);
}

void loop() {
    if (Serial.available() > 0) {
    String t_1  = Serial.readStringUntil(',');
    String t_2  = Serial.readStringUntil(',');
    String t_3  = Serial.readStringUntil('\0');
 
    theta_1=t_1.toInt();
    theta_2=t_2.toInt();
    theta_3=t_3.toInt();
    
    calculate_fk();
    print_XYZ();
    move_robot();
    
    }
  
}
void move_robot(){
    for(int pos=0;pos<=180;pos++){
        if(pos<=theta_1){servo1.write(pos);}  
        if(pos<=theta_2){servo2.write(pos);}  
        if(pos<=theta_3){servo3.write(pos);} 
    delay(20);
    }
}

void print_XYZ(){
  Serial.print("Co-ordinates calculated :   ");
  Serial.print(x);Serial.print(" | ");Serial.print(y);Serial.print(" | ");Serial.println(z);

}
void calculate_fk(){
 x=cos(theta_1/57.26) * ( l_3*cos( (theta_2/57.26) + (theta_3/57.26) ) + l_2*cos(theta_2/57.26)  );
 y=sin(theta_1/57.26) * ( l_3*cos( (theta_2/57.26) + (theta_3/57.26) ) + l_2*cos(theta_2/57.26)  );
 z=l_1 + l_3*sin( (theta_2/57.26)+(theta_3/57.26) ) + l_2*sin(theta_2/57.26);
}
