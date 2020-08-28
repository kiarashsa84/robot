#include <LiquidCrystal.h>
#include <stdio.h>


#define echoPin 13
#define trigPin 12


#define slow 64
#define normal 128
#define fast 255


int reciver = 16;
int reciver2 = 18;
int reciver3 = 14; 
int reciver4 = 15; 
int reciver5 = 17 ; // middle sensor 
/*
int sensorValue=0;
int ledValue=0;
*/

int enablePin2 = 8;
int enablePin3 = 4;
int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int in3Pin = 5;
int in4Pin = 6;
int in5Pin = 3;
int in6Pin = 2;

int Speed;

void rotate_right(void){
  Speed = slow; 
  analogWrite(enablePin2, Speed);
  analogWrite(enablePin, Speed);
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, HIGH);
}
void rotate_left(void){
  Speed = slow;
  analogWrite(enablePin3, Speed);
  digitalWrite(in5Pin, LOW);
  digitalWrite(in6Pin, HIGH);
  analogWrite(enablePin2, Speed);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, HIGH);
}
void Brake(void){
  
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, HIGH);
  
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, HIGH);
  
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, HIGH);
  
}



void Forward_Rev(void){
  
  analogWrite(enablePin, 128);
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);



  analogWrite(enablePin3, 128);
  digitalWrite(in5Pin, LOW);
  digitalWrite(in6Pin, HIGH );
  

}


void Backward_Rev(void){
  int speed = 128 ; 

  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  
  analogWrite(enablePin3, speed);
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, LOW);
  
  
}

void Backward_ramp_up(void){

  for (int i=0; i<255; i++) { 
  analogWrite(enablePin, i);
  analogWrite(enablePin3, i);
  
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, LOW);
  delay(10); } 
    } 


void setup()
{


Serial.begin (9600);



pinMode(reciver , INPUT);
pinMode(reciver2 , INPUT);
pinMode(reciver3 , INPUT);
pinMode(reciver4 , INPUT);
pinMode(reciver5 , INPUT);
/*
pinMode(led2 , OUTPUT);
pinMode(led , OUTPUT);
  
digitalWrite(led2 , HIGH);
digitalWrite(led , HIGH);
*/



pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(in3Pin, OUTPUT);
pinMode(in4Pin, OUTPUT);
pinMode(in5Pin, OUTPUT);
pinMode(in6Pin, OUTPUT); 
pinMode(enablePin2, OUTPUT);
pinMode(enablePin3, OUTPUT);
pinMode(enablePin, OUTPUT);


}
void loop() {
  
  Forward_Rev();
  
  
  
/*
  
  sensorValue= (A0 );
  ledValue=map(sensorValue , 0,1023 ,0,255);
  analogWrite(17,ledValue);
  */
  

/*

  float duration, distance;
  
  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) * 0.0344;
  */
/*
    if (distance <= 20){
    delay(1000);
    Backward_ramp_up();  
    delay(1000);
    Backward_ramp_up();
    delay(2000);
    Brake();
    delay(3000);
    rotate_right();
    delay(10000);
    Brake();
    delay(3000);
    
 

    
  }


    
  if (distance >= 400 || distance <= 2){

    Serial.print("Distance = ");

    Serial.println("Out of range");

    
    

  }

  else  {

    Serial.print("Distance = ");

    Serial.print(distance);

    Serial.println(" cm");

    

    delay(500);

  }

  delay(500);
  
  */
  
  
  
  
  int reading = digitalRead(reciver);
  int reading2 = digitalRead(reciver2);
  int reading3 = digitalRead(reciver3);
  int reading4 = digitalRead(reciver4);
  int reading5 = digitalRead(reciver5);  
  
  if (reading == HIGH & reading2 == HIGH & reading3 == HIGH & reading4 == HIGH & reading5 == HIGH)
  {
    Brake();
  }
  
  if (reading == HIGH & reading2 == HIGH & reading3 == HIGH & reading4 == HIGH & reading5 == LOW)
  {
    
  Forward_Rev();

  } else if (reading == LOW & reading2 == LOW & reading3 == LOW & reading4 == LOW & reading5 == LOW)
  {
  Brake();     
 
  }else if (reading == LOW & reading2 == HIGH & reading3 == LOW  & reading4 == HIGH & reading5 == LOW)
 { 
  rotate_left();
  delay(2000);
  Brake();

 } else if (reading == HIGH & reading2 == LOW & reading3 == HIGH & reading4 == LOW & reading5 == LOW)
 {
   rotate_right();
   delay(2000);
   Brake();
 }
  
  /* if (reading == HIGH )
  {
    delay(1000);
    
    rotate_left();
    
    delay(3000);
    
    Brake();
  }
  if (reading2 == HIGH) 
  {
    
    delay(1000);
    
    rotate_right();
    
    delay(3000);
    
    Brake();
  }
  */
    
  /*
  
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
  */


}
