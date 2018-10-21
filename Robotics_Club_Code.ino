#include <NewPing.h>
const int motor1a=5;
const int motor1b=4;
const int motor2a=7;
const int motor2b=6;
const int trigger_pin_front;
const int trigger_pin_left;
const int trigger_pin_right;
const int echo_pin_front;
const int echo_pin_left;
const int echo_pin_right;
const int max_distance=200;
int distance_left=0;
int distance_right=0;
int distance_forward=0; 
 
NewPing sonar1(trigger_pin_front,echo_pin_front,max_distance)
NewPing sonar2(trigger_pin_left,echo_pin_left,max_distance);
NewPing sonar3(trigger_pin_right,echo_pin_right,max_distance);
void setup() {
  Serial.beign(9600);
  pinMode(motor1a,OUTPUT);
  pinMode(motor1b,OUTPUT);
  pinMode(motor2a,OUTPUT);
  pinMode(motor2b,OUTPUT);


}

void loop() {
  turnLeft();
  

}
void turnLeft()
{
  digitalWrite(motor1a,HIGH);
  digitalWrite(motor1b,LOW);
  digitalWrite(motor2a,LOW);
  digitalWrite(motor2b,HIGH);
  delay(1000);
}
void goStraight()
{
  digitalWrite(motor1a,HIGH);
  digitalWrite(motor1b,LOW);
  digitalWrite(motor2a,HIGH);
  digitalWrite(motor2b,LOW);
}
void turnRight()
{
  digitalWrite(motor1a,LOW);
  digitalWrite(motor1b,HIGH);
  digitalWrite(motor2a,HIGH);
  digitalWrite(motor2b,LOW);1
}
void stop()
{
   digitalWrite(motor1a,LOW);
     digitalWrite(motor1b,LOW);u
   digitalWrite(motor2a,LOW);
   digitalWrite(motor2b,LOW);
}
/*void getDistanceFront()
{
  distance_front=sonar1.ping_cm();
  Serial.println(distance_front);
}
void getDistanceLeft()
{
  distance_left=sonar2.ping_cm();
}
void getDistanceRight()
{
  distance_right=sonar3.ping_cm();
}
*/
