//code to send sms from arduino
int t= 1;
int count=0;
char phone_no[]="7031405265";
void setup() {

  Serial.begin(9600);
  delay(2000);
  Serial.println("AT+CMGF=1");//set GSM to sms mode
  delay(200);

}

void loop() {

  while(count<t){
  delay(1500);
  Serial.print("AT+CMGS=\"");
  Serial.println(phone_no);
  Serial.print("\"");
  while(Serial.read()!='>'){

    Serial.print("WELCOME TO BENGAL INSTITUTE OF TECHNOLOGY");
    delay(200);
    Serial.write(Ox1A);
    Serial.write(Ox0D);
    Serial.write(Ox0A);
    delay(200);
  }
  count++;
  }
  

}
