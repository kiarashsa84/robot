int reciver = 16;
int led = 15;
int sensorValue=0;
int ledValue=0;
void setup()
{
  Serial.begin(9600);

  pinMode(reciver , INPUT);
  pinMode(led , OUTPUT);
  digitalWrite(led , HIGH);
}


void loop()
{


  
  int reading = digitalRead(reciver);
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
  

}
