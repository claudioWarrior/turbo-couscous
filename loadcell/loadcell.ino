#include <HX711.h>
#define DOUT  3
#define CLK  2
HX711 scale;
float calibration_factor = 400; //-7050 worked for my 440lb max scale setup
void setup() {
  Serial.begin(9600);
  scale.begin(DOUT,CLK);
//  Serial.println("HX711 calibration sketch");
//  Serial.println("Remove all weight from scale");
//  Serial.println("After readings begin, place known weight on scale");
//  Serial.println("Press + or a to increase calibration factor");
//  Serial.println("Press - or z to decrease calibration factor");
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
//  long zero_factor = scale.read_average(); //Get a baseline reading
//  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
//  Serial.println(zero_factor);
}
void loop() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
//  Serial.print("Reading: ");
  double wt=(scale.get_units());
  Serial.print(wt);
  Serial.print(" gm"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
//  Serial.print(" calibration_factor: ");
//  Serial.print(calibration_factor);
  Serial.println();
  delay(500);
  if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '+' || temp == 'a')
      calibration_factor += 2;
    else if(temp == '-' || temp == 'z')
      calibration_factor -= 2;
  }
  
}
