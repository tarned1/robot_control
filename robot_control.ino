#include <Servo.h>

Servo myservo; 

float duration, distance; 
int  ena = 13;
int  in1 = 12;
int  in2 = 11;
int  in3 = 10;
int  in4 = 9;
int  enb = 8;
int trigPin = 7; 
int echoPin = 6;

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
  stop1();
  if(Serial.available() > 0)
  {
    keyboard = Serial.read();
    Serial.println(keyboard);
    switch(keyboard)
    {
      case 'w': case 'W':
      for(int analolg = 50, i = 0;i < 500 ;++i)
      {
         if(Serial.available() > 0)
         {
             keyboard = Serial.read();
             if(keyboard == 'e')
             {
              stop1();
              break;
             }
         }
         if(servo())
         {
          forwards();
          delay(1);
         }
         else
         {
          stop1();
          break;
         }
      }
       break;
      case 's': case 'S':
        for(int i =0;i<500;++i)
        {
         backwards();
          if(Serial.available() > 0)
         {
             keyboard = Serial.read();
             if(keyboard == 'e')
             {
             stop1();
             break;
            }
          }
           delay(1);
        }
         break;
     case 'a': case 'A':
     for(int i = 0;i < 500;++i)
     {
        turnLeft();
         if(Serial.available() > 0)
        {
           keyboard = Serial.read();
           if(keyboard == 'e')
           {
            stop1();
            break;
           }
        }
        delay(1);
     }
       break;
     case 'd': case 'D':
     for(int i = 0;i<500;++i)
     {
       turnRight();
        if(Serial.available() > 0)
        {
           keyboard = Serial.read();
           if(keyboard == 'e')
           {
            stop1();
            break;
           }
        }
       delay(1);
     }
       break; 
     default:
        stop1();
        break;  
    }
  }
}
void forwards()
{
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);
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
  digitalWrite(ena,LOW);
  digitalWrite(enb,HIGH);
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
}
void turnRight()
{
  digitalWrite(ena,HIGH);
  digitalWrite(enb,LOW);
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
 return distance;
}
bool servo()
{
  bool not_to_close = true; 
  myservo.write(118);
  if(getDistance() < 17)
  not_to_close = false;
  Serial.println(distance);     
  return not_to_close;
}
