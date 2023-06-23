int resval = 0;  // holds the value
int respin = A5; // sensor pin used
int pumpPin = 2; //relay pin

void setup() {

  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  resval = analogRead(respin); //Read data from analog pin and store it to resval variable

   if (resval>100 && resval<=300){
   Serial.println("Low "); 
   Serial.println("should now pour water");

   digitalWrite(pumpPin, HIGH);
   }
   else{
   digitalWrite(pumpPin, LOW);
    Serial.println("should now stop water");

   }

   delay(1000); // each 1 secound

    // digitalWrite(pumpPin, HIGH);
    // Serial.println("in the loop");
    // Serial.println("should now pour water");
    // delay(3000); // Pump runnig time (3 second)
    // digitalWrite(pumpPin, LOW);
    // Serial.println("should now stop water");
    // delay(30000); // Pump runnig time (30 second)


}