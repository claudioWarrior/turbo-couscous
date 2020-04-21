//Ma2Di coder.
#include<LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12,11,10,9,8,7);

int iro=6; //visitor out.
int iri=5; // visitor in.
#define ir2 4 // for exit.
#define ir1 2 // for entry.
int servo = 3;
Servo Servo1; // object to servo.
int count=20;

void IN(){
    count--;
    lcd.clear();
    lcd.print("Seats Available:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}

void OUT(){
  count++;
    lcd.clear();
    lcd.print("Seats Available:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
}

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("** WELCOME **");
  delay(2000);
  pinMode(iri, INPUT);
  pinMode(iro, INPUT);
  Servo1.attach(servo);
  lcd.clear();
  lcd.print("Seats Available:");
  lcd.setCursor(0,1);
  lcd.print(count);
}

void loop(){  

    if(digitalRead(ir1)==0 || digitalRead(ir2)==0){
//    Serial.print("//////////////////");
//    Serial.println(digitalRead(ir1));
//    Serial.print("......................");
//    Serial.println(digitalRead(ir2));
  Servo1.write(100); // gate open.
  delay(1000);
  }
  else {
   Servo1.write(10); // gate closed.
  }
  
  if(digitalRead(iri)==0){
    Serial.print("//////////////////");
    Serial.println(digitalRead(iri));
  IN();
  }
  if(digitalRead(iro)==0){
    Serial.print("......................");
    Serial.println(digitalRead(iro));
  OUT();
  }
//  if(digitalRead(ir1)==0 || digitalRead(ir2)==0){
//    Serial.print("//////////////////");
//    Serial.println(digitalRead(ir1));
//    Serial.print("......................");
//    Serial.println(digitalRead(ir2));
//  Servo1.write(100); // gate open.
//  delay(2000);
//  }
//  else {
//   Servo1.write(10); // gate closed.
//  }
}
