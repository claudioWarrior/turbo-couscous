void setup() {

   Serial.begin(9600);

   Serial.println("Reading From The Field At Node One ...");
   pinMode (9, OUTPUT);
   pinMode (10, OUTPUT);
   pinMode (12, OUTPUT);
   pinMode (11, OUTPUT);
   }

void loop() {

   
   int a = analogRead(A1);

   if (a >=600 && a<=850){
   digitalWrite(9, HIGH);
   
   digitalWrite(10,HIGH);
   
   Serial.println(a);
   }
   else {
      
 digitalWrite(9, LOW);
   
   digitalWrite(10,LOW);
   Serial.println(a);
    
   }

 int b = analogRead(A3);

   if (b >=600 && b<=850){
   digitalWrite(9, HIGH);
   
   digitalWrite(11,HIGH);
   
   Serial.println(b);
   }
   else {

      
 digitalWrite(9, LOW);
   
   digitalWrite(11,LOW);
   Serial.println(b);
    
   }
 int c = analogRead(A2);

   if (c >=600 && c<=850){
   digitalWrite(9, HIGH);
   
   digitalWrite(12,HIGH);
   
   Serial.println(c);
   }
   else {
      
 digitalWrite(9, LOW);
   
   digitalWrite(12,LOW);
   Serial.println(c);
    
   }
   
}
   
