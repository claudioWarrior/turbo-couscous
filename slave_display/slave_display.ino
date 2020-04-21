#include<Wire.h>
#include<Servo.h>
#include <LiquidCrystal.h>
#define servo1 6
  const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Servo myserv1;
void setup() {
  myserv1.attach(servo1);
  pinMode(servo1,OUTPUT);
  lcd.begin(16, 4);
  Serial.begin(9600);
  Wire.begin(3);
  Wire.onReceive(execFun);
  lcd.setCursor(0, 0);
  lcd.print("** Welcome **");
  lcd.setCursor(0, 1);
  lcd.print(" To Kolkata ");
  lcd.setCursor(0, 3);
  lcd.print("___Pay Toll___");
}

void loop() {

}

void execFun(int hm){
  String data;
  while(Wire.available()){
    char c=Wire.read();
    data=c;
//    datas=data.substring(0,1);
//    datat=data.substring(1,data.length());

  }
  Serial.println(data);
//  Serial.println(datat);
      if(data=="1"){
      myserv1.write(90);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("New Lane is Open");
      lcd.setCursor(0, 2);
      lcd.print("Move this Way-->");
      lcd.setCursor(0, 3);
      lcd.print("Avoid Traffic");
      delay(15000);
  }
    if(data=="0"){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The New Lane");
      lcd.setCursor(0,1);
      lcd.print("will close soon");
      lcd.setCursor(0,3);
      lcd.print("Move this Way<--");
      delay(15000);
//      lcd.clear();
      myserv1.write(0);
    }
}
