#define led1 10 //mini combo.
#define led2 12 //daily combo.
#define led3 11 //special combo.


void setup() {
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
}

void loop() {
 
  if(Serial.available()>0){
    char data=Serial.read();
    
    switch(data){
      case 'A': digitalWrite(led1, HIGH);
      case 'B': digitalWrite(led2, HIGH);
      case 'C': digitalWrite(led3, HIGH);
      case 'E': digitalWrite(led1, LOW);
      case 'F': digitalWrite(led2, LOW);
      case 'G': digitalWrite(led3, LOW);
      default : break;
    }
    Serial.println(data);
  }
  delay(50);
}
