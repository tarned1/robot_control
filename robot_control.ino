#include <Servo.h>

Servo myservo; 

int pos = 0;    
const int trigPin = 7; 
const int echoPin = 6;
float duration, distance; 



int  ena = 13;
int  in1 = 12;
int  in2 = 11;
int  in3 = 10;
int  in4 = 9;
int  enb = 8;


void forwards();
void backwards();
void turnLeft();
void turnRight();
void stop1();
float getDistance();
void servoLeft();
bool servo();

void setup() {
  Serial.begin(9600);
  pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enb,OUTPUT);

    myservo.attach(3);  
   pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 
 Serial.begin(9600); 
}

void loop() {
   
  char keyboard = '/';
  if(Serial.available() > 0)
  {
    keyboard = Serial.read();
    Serial.println(keyboard);
    switch(keyboard)
    {
      case 'w': case 'W':
         if(servo())
         {
          forwards();
          delay(2000);
          break;
         }
      case 's': case 'S':
         backwards();
         delay(2000);
         break;
     case 'a': case 'A':
        turnLeft();
        delay(2000);
       break;
     case 'd': case 'D':
       turnRight();
       delay(2000);
       break; 
     default:
        stop1();
        break;  
    }
  }
}
void forwards()
{
  digitalWrite(ena,HIGH);
  digitalWrite(enb,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
}
void backwards()
{
  digitalWrite(ena,HIGH);
  digitalWrite(enb,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}
void turnLeft()
{
  digitalWrite(enb,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
}
void turnRight()
{
  digitalWrite(ena,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
}
void stop1()
{
  digitalWrite(ena,LOW);
  digitalWrite(enb,LOW);
}

float getDistance()
{
  digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH); 
 distance = (duration*.0343)/2; 
}
bool servo()
{
  bool not_to_close = true; 
  for (pos = 65; pos <= 180; pos += 1) 
  { 
    myservo.write(pos);
    if(pos < 8)
      not_to_close = false;     
    delay(1);                       
  }
  return not_to_close;
}
