int resval = 0;  // holds the value
int respin = A5; // sensor pin used
  
void setup() { 
  Serial.begin(9600);
} 
  
void loop() { 
 
  resval = analogRead(respin); //Read data from analog pin and store it to resval variable
   
  if (resval<=100){ 
    Serial.println("Empty "); 
  } 
  else if (resval>100 && resval<=300){ 
    Serial.println("Low "); 
  } 
  else if (resval>300 && resval<=330){
   Serial.println("Medium "); 
  }
  else if (resval>330){ 
    Serial.println("High"); 
  }
  delay(1000); 
}