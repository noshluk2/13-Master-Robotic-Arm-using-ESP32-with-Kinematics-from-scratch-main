/* first joint is ignored here
  Code First Takes
  - Serial Input , angles of joints (2only)
  - Calculate the forward kinematics 
  - Prints on Serial X Y Z values in Cartesian Space.
  - Then Slowly Move the Robot


Author : Muhammad Luqman
Date   : 14-10-2020
License: MIT

*/


#include <ESP32Servo.h> 

static const int servoPin1 = 17;
static const int servoPin2 = 16;
int servos_angle[2];
Servo servo1;
Servo servo2;
double x,y;
float l_1= 15.6;float l_2=11.7;  // in centimeters
void setup() {
    Serial.begin(115200);
    servo1.attach(servoPin1);
    servo2.attach(servoPin2);
}

void loop() {
  if (Serial.available() > 0) {
    String first  = Serial.readStringUntil(',');
    String second = Serial.readStringUntil('\0');
  
    servos_angle[0]=first.toInt();
    servos_angle[1]=second.toInt();  
    // input radians so coverted degrees to radian first
    x=(l_1 * cos(servos_angle[0]/57.26) ) +  (l_2 * (cos(servos_angle[0]/57.26 + servos_angle[1]/57.26 )  ));  
    y=(l_1 * sin(servos_angle[0]/57.26) ) +  (l_2 * (sin(servos_angle[0]/57.26 + servos_angle[1]/57.26 )  ));
    Serial.print("Co-ordinates calculated :   ");Serial.print(x);Serial.print(" | ");Serial.println(y);
    
    
        for(int pos=0;pos<=180;pos++){
          if(pos<=servos_angle[0]){servo1.write(pos);}  
          if(pos<=servos_angle[1]){servo2.write(pos);}  
          delay(20); }

                               }
                               
}
