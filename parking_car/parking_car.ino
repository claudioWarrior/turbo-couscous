//Ma2Di coder.
#include <Servo.h>

#define trigPin 4
#define echoPin 3
#define ir2 8 // for exit.
#define ir1 7 // for entry.
#define ledG1 5
#define ledR1 6
#define ledR2 9
int servo = 2;
Servo Servo1; // object to servo.

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ledG1, OUTPUT);
  pinMode(ledR1, OUTPUT);
  pinMode(ledR2, OUTPUT);
  Servo1.attach(servo);

}

void loop() {
  int a=digitalRead(ir1);
  int b=digitalRead(ir2);
  digitalWrite(ledR2, HIGH);

  Serial.println(a);
  Serial.println("////////////////////");
  Serial.println(b);
  
  if(a==1 || b==0){
  Servo1.write(90); // gate open.
  delay(2000);
  }
  else {
   Servo1.write(0); // gate closed.
  }

  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if (distance < 7) {
  digitalWrite(ledG1, LOW);
  digitalWrite(ledR1, HIGH);
}
  else {
    digitalWrite(ledG1, HIGH);
    digitalWrite(ledR1, LOW);
  }

}
