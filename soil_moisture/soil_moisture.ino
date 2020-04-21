void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);

}
void loop() {
  
  int sensorValue = analogRead(A1);
  
  Serial.println(sensorValue);
  delay(500);

          if(sensorValue < 700 && sensorValue > 350){

              digitalWrite(9,LOW);
            digitalWrite(5,LOW);
            digitalWrite(8,LOW);
digitalWrite(7,LOW);
}
          else{

              digitalWrite(9,HIGH);
            digitalWrite(5,LOW);
            digitalWrite(8,HIGH);
            digitalWrite(7,LOW);
          }
}
