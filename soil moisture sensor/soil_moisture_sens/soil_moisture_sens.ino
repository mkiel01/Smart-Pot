int Moisture_signal = A0;

void setup() {

  Serial.begin(9600);

}

void loop() {
  int value = analogRead(Moisture_signal);
  Serial.print("Soil Moisture Level : ");
  Serial.println(value);
   if (value > 950) {
    Serial.print("Water Pump is ON ");
  } else {
    Serial.print("Water Pump is OFF ");
  }
 
  if (value < 300) {
    Serial.print("Moisture : HIGH");
  } else if (value > 300 && value < 950) {
    Serial.print("Moisture : MID ");
  } else if (value > 950) {
    Serial.print("Moisture : LOW ");
  }
  delay(1000);
  
}
