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
void setup() {
  Serial.begin(9600);
  pinMode(ena,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enb,OUTPUT);
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
       forwards();
       delay(10000);
       break;   
    case 's': case 'S':
       backwards();
       delay(10000);
       break;
    case 'a': case 'A':
      turnLeft();
      delay(10000);
      break;
    case 'd': case 'D':
      turnRight();
      delay(10000);
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

