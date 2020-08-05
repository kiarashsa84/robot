int reciver = 16;
int reciver2 = 18;
int led = 15;
int led2 = 14;
int sensorValue=0;
int ledValue=0;
void setup()
{
  Serial.begin(9600);

  pinMode(reciver , INPUT);
  pinMode(reciver2 , INPUT);
  
  pinMode(led2 , OUTPUT);
  pinMode(led , OUTPUT);
  
  digitalWrite(led2 , HIGH);
  digitalWrite(led , HIGH);
}


void loop()
{


  
  int reading = digitalRead(reciver);
  int reading2 = digitalRead(reciver2);
  
  sensorValue= (A0 );
  ledValue=map(sensorValue , 0,1023 ,0,255);
  analogWrite(17,ledValue);
  
  
  if (reading == HIGH)
  {
    digitalWrite(led , HIGH);
  }
  else if (reading == LOW)
  {
    digitalWrite(led , LOW);
  }
  
  
  
  if (reading2 == HIGH)
  {
    digitalWrite(led2 , HIGH);
  }
  else if (reading2 == LOW)
  {
    digitalWrite(led2 , LOW);
  }
  

}
