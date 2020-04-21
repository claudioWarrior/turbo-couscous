#include <Servo.h>
#include <LiquidCrystal.h>

Servo myserv1;
Servo myserv2;
#define ir1 12  //for entry
#define ir2 11  //for exit
int serv1=10; //for entry
int serv2=9;  //for exit

  const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600); // put your setup code here, to run once:
  myserv1.attach(serv1);
  myserv2.attach(serv2);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//    myserv1.write(90);
//    myserv2.write(0);
  
//  lcd.setCursor(0, 0);
//  lcd.print("** WELCOME **");
//  lcd.setCursor(0, 1);
//  lcd.print("TO TOLL PLAZA");
//  delay(4000);
//  lcd.clear();

//Serial.print(digitalRead(ir1));
//Serial.println("///////////////////");
//delay(3000);
//Serial.println(digitalRead(ir2));  
  
  if(digitalRead(ir1)==0){
    myserv1.write(0);
//    lcd.setCursor(0, 0);
//    lcd.print("PAY YOUR TOLL");
//    lcd.setCursor(0, 1);
//    lcd.print("SCANNING.....");
  delay(4000);
myserv2.write(90);
    delay(10000);
    Serial.println("Payment Successfull");
    Serial.println("Drive Forward");
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    lcd.print("PAYMENT SUCCESS");
//    lcd.setCursor(0, 1);
//    lcd.print("DRIVE FORWARD");
//    delay(4000);
//    lcd.clear();
//    myserv2.write(90);
  }
  
  if(digitalRead(ir2)==0){
  myserv2.write(0);
  delay(2000);
  myserv1.write(90);
  }

}
