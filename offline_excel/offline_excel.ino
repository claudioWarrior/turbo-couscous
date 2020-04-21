int i=0;
String chk="1234567890";
void setup() {
 Serial.begin(9600);
 Serial.println("Date & Time, carno, Uniqueid");
}

void loop() {
  String tag,data;
  
    for(int j=1;j<11;j++){
  if(Serial.available()>0){
    char c=(char)Serial.read();
    tag =tag+c;
    }
    }
    data=tag.substring(1,11);
    delay(150);
    if(data.equals(chk)== false && data.length()==9){
      i++;
 Serial.print(",");
 Serial.print(i);
 Serial.print(",");
 Serial.println("Off"+data);
 chk=data;
// delay(1000);
    }
}
