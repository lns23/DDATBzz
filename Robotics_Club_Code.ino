#include <NewPing.h>
#define SONAR_NUM  3
#define MAX_DISTANCE 200
const int motor1a=3;
const int motor1b=5;
const int motor2a=6;
const int motor2b=9;
int distance_left=0;
int distance_right=0;
int distance_forward=0; 
int n =0;
 
NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(10, 11, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(13, 12, MAX_DISTANCE), 
  NewPing(4, 8, MAX_DISTANCE)};
  
void setup() {
  Serial.begin(9600);
  pinMode(motor1a,OUTPUT);
  pinMode(motor1b,OUTPUT);
  pinMode(motor2a,OUTPUT);
  pinMode(motor2b,OUTPUT);
  


}

void loop() {
bool stopped=false;
distance_right= getDistanceRight();
distance_left= getDistanceLeft();
distance_forward=getDistanceFront();

  Serial.println(distance_forward);
  delay(150);
  
  if(17<distance_forward)
  {
    goStraight();
  }
  
   else
   {
    stopMotor();
    stopped=true;
   }
   if(stopped&&(distance_right<distance_left))
   {
    turnLeft();
   }
   else if(stopped&&(distance_left<distance_right))
   {
    turnRight();
   }

 
  /* else if (stopped&&((distance_left-distance_right)<10))
   {
    turnLeft();
    delay(150);
    stopMotor();
   }*/

}
void turnRight()
{
  analogWrite(motor1b,150);
  analogWrite(motor1a,0);
  analogWrite(motor2a,0);
  analogWrite(motor2b,150);
  delay(490);
  stopMotor();
  
}
void goStraight()
{
  analogWrite(motor1b,150);
  analogWrite(motor1a,0);
  analogWrite(motor2a,150);
  analogWrite(motor2b,0);
}
void turnLeft()
{
  analogWrite(motor1b,0);
  analogWrite(motor1a,150);
  analogWrite(motor2a,150);
  analogWrite(motor2b,0);
  delay(490);
  stopMotor();
  
}
void stopMotor()
{
   digitalWrite(motor1a,LOW);
   digitalWrite(motor1b,LOW);
   digitalWrite(motor2a,LOW);
   digitalWrite(motor2b,LOW);
}
int getDistanceFront()
{
  int distance;
  distance=sonar[2].ping_cm();
  return distance;
}
int getDistanceLeft()
{
  int distance;
  distance=sonar[1].ping_cm();
  return distance;
}
int getDistanceRight()
{
  int distance;
  distance=sonar[0].ping_cm();
  return distance;
}
