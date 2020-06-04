#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

Servo servo_motor;
ros::NodeHandle  nh;

void servo_cb( const std_msgs::UInt16& msg){
     //servo_motor.write(msg.data); //set servo angle, should be from 0-180  
     //digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}

ros::Subscriber<std_msgs::UInt16> sub("servo_motor", servo_cb);

void setup()
{
 Serial.begin(9600);
 pinMode(13, OUTPUT);
 nh.initNode();
 nh.subscribe(sub);
 pinMode(A2, OUTPUT);
 pinMode(A3, OUTPUT);
 digitalWrite(A2, HIGH);
 digitalWrite(A3,LOW);
 servo_motor.attach(9);
}
 
void loop()
{
 //nh.spinOnce();
 int readJoyStickValue = analogRead(A1); //read joystick input
 Serial.println(readJoyStickValue);
 readJoyStickValue = map(readJoyStickValue,0,1023,0,180); //map joystick analog value for servo motor 
 servo_motor.write(readJoyStickValue); //servo motor perform
 delay(50);
}
