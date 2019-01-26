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
int n =10;
 
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

//goStraight();
Serial.println(distance_forward);
//delay(150);


//---------------------------TESTING--------------------------

if (n==0){
  turnRight();
  n = 1;
}

if(n==1){
  goStraight();
  delay(1000);
  n = 2;
}

if(n==2){
  turnLeft();
  n =3;
}

if(n==4){
  goStraight();
}
//--------------------------------------------------------

//----------- CURRENT ALGORITH / MAZE 1: WORKS // MAZE 2: KINDA WORKS------------------------------
  
 
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

 
   else if (stopped&&((distance_left-distance_right)<10))
   {
    turnLeft();
    
   }
   
//-------------------------------------------------------------------------------------------------------------*/
   //NEW ALGORITHM

   /*
   Serial.print("Front:");
   Serial.println(distance_forward);
   
   Serial.print("Right:");
   Serial.println(distance_right);

   delay(250);

   if(distance_right < 20 && distance_forward> 17){
      goStraight();
   }
   
   
   
   if(distance_right > 20 || distance_forward < 17){
    stopMotor();
    stopped = true;
   }

   if(stopped){
      if(distance_right <= 12 && distance_forward < 17){
        turnLeft(); 
      }

      else if(distance_right > 15){
        turnRight();
      }
   }

   */
     
}
void turnRight()
{
  analogWrite(motor1b,180);
  analogWrite(motor1a,0);
  analogWrite(motor2a,0);
  analogWrite(motor2b,0);
  delay(730);
  stopMotor();
  delay(100);
}
void goStraight()
{
  //1 is left motor
  //2 is right motor;
  analogWrite(motor1b,179);
  analogWrite(motor1a,0);
  analogWrite(motor2a,173);
  analogWrite(motor2b,0);
}
void turnLeft()
{
  analogWrite(motor1b,0);
  analogWrite(motor1a,0);
  analogWrite(motor2a,180);
  analogWrite(motor2b,0);
  delay(720);
  stopMotor();
  delay(100);
  
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
