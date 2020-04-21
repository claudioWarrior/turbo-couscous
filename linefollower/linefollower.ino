#define LM1 5 // left motor M1a
#define RM1 6 // right motor M2a
int LS=2;
int RS=3;
void setup()
{
pinMode(LS, INPUT);
pinMode(RS, INPUT);
pinMode(LM1, OUTPUT);
pinMode(RM1, OUTPUT);
}
void loop()
{
if(digitalRead(LS) && digitalRead(RS)) // Move Forward on line
{
digitalWrite(LM1, HIGH);
digitalWrite(RM1, HIGH);
}
if(digitalRead(LS) && !(digitalRead(RS))) // turn right by rotationg left motors in forward and right ones in backward direction
{
digitalWrite(LM1, HIGH);
digitalWrite(RM1, LOW);
}
if(!(digitalRead(LS)) && digitalRead(RS)) // Turn left by rotating right motors in forward and left ones in backward direction
{
digitalWrite(LM1, LOW);
digitalWrite(RM1, HIGH);
}

if(!(digitalRead(LS)) && !(digitalRead(RS))) // Finish line, stop both the motors
{
digitalWrite(LM1, LOW);
digitalWrite(RM1, LOW);
}
}
