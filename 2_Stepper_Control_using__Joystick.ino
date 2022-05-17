 //defines pins
const int stepPin = 6;  //PUL -Pulse
const int dirPin = 7; //DIR -Direction
const int enPin = 8;  //ENA -Enable

//defines pins
const int stepPin1 = 9;  //PUL -Pulse
const int dirPin1 = 10; //DIR -Direction
const int enPin1 = 11;  //ENA -Enable

float ang_CW ;
float ang_CCW ;
float ang;
float X_axis;
int pul;

float ang1_CW ;
float ang1_CCW ;
float ang1;
float y_axis;
int pul1;

void setup(){
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  Serial.begin(9600);

  pinMode(stepPin1,OUTPUT); 
  pinMode(dirPin1,OUTPUT);
  pinMode(enPin1,OUTPUT);
  digitalWrite(enPin1,LOW);
 
}


void loop(){
  X_axis = analogRead(A0);
  ang_CW = map(X_axis,0,400,90,0);
  ang_CCW = map(X_axis,600,1023,0,-90);
  if(X_axis <= 400)
  {
    ang = ang_CW;
    digitalWrite(dirPin,HIGH);
  }
  else if (X_axis >= 600)
  {
    ang = ang_CCW;
    digitalWrite(dirPin,LOW);
  }
  else
    ang =0;
  pul = map(abs(ang),0,360,0,3000);
   Serial.print(ang);   
   Serial.print("              ");  
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
y_axis = analogRead(A1);
  ang1_CW = map(y_axis,0,400,90,0);
  ang1_CCW = map(y_axis,600,1023,0,-90);
  if(y_axis <= 400)
  {
    ang1 = ang1_CW;
    digitalWrite(dirPin1,HIGH);
  }
  else if (y_axis >= 600)
  {
    ang1 = ang1_CCW;
    digitalWrite(dirPin1,LOW);
  }
  else
    ang1 =0;
  pul1 = map(abs(ang1),0,360,0,3000);
   Serial.println(ang1);    
  if(ang1!= 0)
  {
  for(int i=0;i<=pul1;i++)
    {
      digitalWrite(stepPin1,HIGH); 
      delayMicroseconds(1000); 
      digitalWrite(stepPin1,LOW); 
      delayMicroseconds(1000); 
  }
  }
}
  
