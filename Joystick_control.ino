//defines pins
const int stepPin = 6;  //PUL -Pulse
const int dirPin = 7; //DIR -Direction
const int enPin = 8;  //ENA -Enable
float ang_CW ;
float ang_CCW ;
float ang;
float input;
int pul;

void setup(){
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  Serial.begin(9600);
}


void loop(){
  input = analogRead(A0);
  ang_CW = map(input,0,400,90,0);
  ang_CCW = map(input,600,1023,0,-90);
  if(input <= 400)
  {
    ang = ang_CW;
    digitalWrite(dirPin,HIGH);
  }
  else if (input >= 600)
  {
    ang = ang_CCW;
    digitalWrite(dirPin,LOW);
  }
  else
    ang =0;
  pul = map(abs(ang),0,360,0,3000);
   Serial.println(ang);    
  if(ang!= 0)
  {
  for(int i=0;i<=pul;i++)
    {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(1000); 
  }
  }
}
