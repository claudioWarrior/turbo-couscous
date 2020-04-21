#include <Wire.h>

char tag[12];

void setup() {
  Serial.begin(9600);
  Wire.begin(8); //12c comm bus
  Wire.onRequest(reqEvntOne);
}

void loop() {
  for(int i=0;i<=11;i++){
  if(Serial.available()>0){
    char c=(char)Serial.read();
    tag[i]= c;
//        Serial.print(c);
    }
  }
//    Serial.println();
    delay(150);
}
void reqEvntOne() {
    Wire.write(tag);
//    Wire.write(wt);
}
