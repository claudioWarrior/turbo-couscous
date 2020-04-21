#include <SPI.h>
#include <MFRC522.h>
 //SCK to 13 MOSI to 11 MISO 12
#define SS_PIN 53 //SDA
#define RST_PIN 5
#define LED_G 3 //define green LED pin
#define LED_R 4 //define red LED
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
//  pinMode(BUZZER, OUTPUT);
//  noTone(BUZZER);
//  Serial.println("Put your card to the reader...");
//  Serial.println();

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
//  Serial.print("UID tag :");
  String content= "";
//  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
//     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
//  Serial.println();
//  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "D6 80 DB 1A") //change here the UID of the card/cards that you want to give access
  {
//    Serial.println("Authorized access");
//    Serial.println();
//    delay(500);
    digitalWrite(LED_G, HIGH);
//    tone(BUZZER, 500);
//    delay(300);
//    noTone(BUZZER);
    delay(5000);
    digitalWrite(LED_G, LOW);
  }
 
 else   {
//    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH);
//    tone(BUZZER, 300);
    delay(1000);
    digitalWrite(LED_R, LOW);
//    noTone(BUZZER);
  }
}
