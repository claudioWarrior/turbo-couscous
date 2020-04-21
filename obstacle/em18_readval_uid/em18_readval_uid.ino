boolean stringComplete = false;
String inputString = "";
int n = 0;
#define BUZZ 8


void setup() {
  Serial.begin(9600);
  pinMode(BUZZ,OUTPUT);
  inputString.reserve(200);
}

void loop() {
  if(stringComplete){
    Serial.println(inputString);
    if(inputString.equals("180001493565")){//A
      digitalWrite(BUZZ,HIGH);
    }
    if(inputString.equals("1300711F7508")){//B
      digitalWrite(BUZZ,LOW);
    }
   
    stringComplete = false;
    inputString = "";
  }
}

void serialEvent(){
  while(Serial.available()){
    n++;
    char inChar = (char) Serial.read();
    inputString += inChar;
    if(n>=12){
      n=0;
      stringComplete = true;
    }
  }
}
