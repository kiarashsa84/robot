#define slow 64
#define normal 128
#define fast 255

int enablePin2 = 8;
int enablePin3 = 4;
int enablePin = 11;
int in1Pin = 10;
int in2Pin = 9;
int in3Pin = 5;
int in4Pin = 6;
int in5Pin = 3;
int in6Pin = 2;
int switchPin = 7;
int potPin = 0;
int statusPin= 13;

int Speed;
void rotate_right(void){
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
  analogWrite(enablePin3, Speed);
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, LOW);
  analogWrite(enablePin2, Speed);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, HIGH);
}
void Brake(void){
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, HIGH);
  digitalWrite(in4Pin, HIGH);
  digitalWrite(in5Pin, HIGH);
}



void Forward_Rev(void){
  analogWrite(enablePin, Speed);
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  analogWrite(enablePin3, Speed);
  digitalWrite(in5Pin, HIGH);
  digitalWrite(in6Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, HIGH);  

  
}
void Backward_Rev(void){
  analogWrite(enablePin, Speed);
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in5Pin, LOW);
  digitalWrite(in6Pin, HIGH);
  analogWrite(enablePin3, Speed);
  digitalWrite(in4Pin, HIGH);
  digitalWrite(in5Pin, HIGH);
  
}


void setup()
{
pinMode(in1Pin, OUTPUT);
pinMode(in2Pin, OUTPUT);
pinMode(in3Pin, OUTPUT);
pinMode(in4Pin, OUTPUT);
pinMode(in5Pin, OUTPUT);
pinMode(in6Pin, OUTPUT); 
pinMode(enablePin2, OUTPUT);
pinMode(enablePin3, OUTPUT);
pinMode(enablePin, OUTPUT);
pinMode(switchPin, INPUT_PULLUP);
pinMode(statusPin,OUTPUT);
}

void loop()
{
  Speed = fast;

  Forward_Rev();
  delay(10000);
  Brake();
  delay(1000);
  rotate_left();
  delay(10000);
  Brake();
  delay(1000);
  Forward_Rev();
  delay(10000);
  Brake();
  delay(1000);
  rotate_right();
  delay(10000);
  Brake();
  delay(1000);
  Backward_Rev();
  delay(10000);
  Brake();
  delay(1000);

}
