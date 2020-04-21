int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
void setup() {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);

}

void loop() {

  digitalWrite(a,HIGH);
  delay(500);
    digitalWrite(c,HIGH);
  delay(500);
    digitalWrite(e,HIGH);
  delay(500);
    digitalWrite(a,LOW);
  delay(500);
    digitalWrite(c,LOW);
  delay(500);
    digitalWrite(e,LOW);
  delay(500);

  
      digitalWrite(b,HIGH);
  delay(500);
    digitalWrite(d,HIGH);
  delay(500);
    digitalWrite(f,HIGH);
  delay(500);
    digitalWrite(b,LOW);
  delay(500);
    digitalWrite(d,LOW);
  delay(500);
    digitalWrite(f,LOW);
  delay(500);

  
    digitalWrite(a,HIGH);
  delay(500);
    digitalWrite(b,HIGH);
  delay(500);
    digitalWrite(c,HIGH);
  delay(500);
    digitalWrite(d,HIGH);
  delay(500);
    digitalWrite(e,HIGH);
  delay(500);
    digitalWrite(f,HIGH);
  delay(500);
  
digitalWrite(a,LOW);
  delay(500);
    digitalWrite(b,LOW);
  delay(500);
    digitalWrite(c,LOW);
  delay(500);
    digitalWrite(d,LOW);
  delay(500);
    digitalWrite(e,LOW);
  delay(500);
    digitalWrite(f,LOW);
  delay(500);

}
