int motor1pin1=2;
int motor1pin2=4;
int enable1=3;
int motor2pin1=7;
int motor2pin2=8;
int motor3pin1=10;
int motor3pin2=11;
int enable3=9;
int motor4pin1=12;
int motor4pin2=13;
int enable4=6;
int state;
int flag=0;
int statestop=0;


void setup()
{
 pinMode(motor1pin1,OUTPUT);
 pinMode(motor1pin2,OUTPUT);
 pinMode(motor2pin1,OUTPUT);
 pinMode(motor2pin2,OUTPUT);
 pinMode(motor3pin1,OUTPUT);
 pinMode(motor3pin2,OUTPUT);
 pinMode(motor4pin1,OUTPUT);
 pinMode(motor3pin2,OUTPUT);
 pinMode(enable1,OUTPUT);
 pinMode(enable3,OUTPUT);
 pinMode(enable3,OUTPUT);
 pinMode(enable4,OUTPUT);
 
 Serial.begin(9600);
}


void loop()
{
 if(Serial.available()>0)
  {
   state=Serial.read();
   flag=0;
  }

//  CODE FOR FORWARD
 if (state=='F')
  {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   digitalWrite(motor2pin1,HIGH);
   digitalWrite(motor2pin2,LOW);
   analogWrite(enable1,255);
 if (flag==0)
  {
   Serial.println("GO FORWARD");
   flag=1;
  }
 }
 // CODE FOR SLOW FORWARD
 else if (state=='A')
  {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   digitalWrite(motor2pin1,HIGH);
   digitalWrite(motor2pin2,LOW);
   analogWrite(enable1,160);
   
 if (flag==0)
  {
   Serial.println("GO SLOW FORWARD");
   flag=1;
  }
 }


// CODE FOR RIGHT

else if (state=='R')
 {
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,HIGH);
  analogWrite(enable1,210);
 if (flag==0)
  {   
   Serial.println("GO RIGHT");
   flag=1;
  }
 }

//  CODE FOR LEFT

else if (state=='L')
 {
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  analogWrite(enable1,210);
 if (flag==0)
  {
   Serial.println("GO LEFT");
   flag=1;
  }
 }

//  CODE FOR BACKWARD

else if (state=='B')
 {
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,HIGH);
  analogWrite(enable1,200);
 if (flag==0)
  {
   Serial.println("GO BACKWARD");
   flag=1;
  }
 }

//  CODE FOR GRAB

else if (state=='G')
 {
  digitalWrite(motor3pin1,LOW);
  digitalWrite(motor3pin2,HIGH);
  analogWrite(enable3,255);
 if (flag==0)
  {
   Serial.println("GRAB");
   flag=1;
  }
 }

//  CODE FOR EJECT

else if (state=='E')
 {
  digitalWrite(motor3pin1,HIGH);
  digitalWrite(motor3pin2,LOW);
  analogWrite(enable3,255);
 if (flag==0)
  {
   Serial.println("EJECT");
   flag=1;
  }
 }

//  CODE FOR UP

else if (state=='U')
 {
  digitalWrite(motor4pin1,HIGH);
  digitalWrite(motor4pin2,LOW);
  analogWrite(enable4,255);
 if (flag==0)
  {
   Serial.println("UP");
   flag=1;
  }
 }

//  CODE FOR DOWN

else if (state=='D')
 {
  digitalWrite(motor4pin1,LOW);
  digitalWrite(motor4pin2,HIGH);
  analogWrite(enable4,255);
 if (flag==0)
  {
   Serial.println("DOWN");
   flag=1;
  }
 }
//  CODE FOR STOP

else if (state=='S')
 {
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  digitalWrite(motor3pin1,LOW);
  digitalWrite(motor3pin2,LOW);
  digitalWrite(motor4pin1,LOW);
  digitalWrite(motor4pin2,LOW);
  analogWrite(enable1,0);
  analogWrite(enable3,0);
  analogWrite(enable4,0);
 }
}

