#include <dht11.h>  // tem_sens
#define DHT11PIN 4 // tem_sens
dht11 DHT11;  // tem_sens
#include <Wire.h>
#include <LiquidCrystal_I2C.h>         
int water_sens_pin = A1;  
int moisture_sens_pin = A0; 
int pump_pin = 2; //relay pin

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() { 

  Serial.begin(9600);
  lcd.init();         
  lcd.backlight();
  pinMode(water_sens_pin, INPUT);
  pinMode(moisture_sens_pin, INPUT); // input bo szczytuje 
  pinMode(pump_pin, OUTPUT); // out bo wysyłam do niego

} 
  
void loop() { 

  // WATER LEVEL SENSOR
  int water_sens_val = analogRead(water_sens_pin); 
  Serial.println("NEW"); 
  Serial.println(); 
  Serial.println(); 
  Serial.println(); 
   
  if (water_sens_val<=100){ 
    Serial.println("Empty "); 
    Serial.println("Put water in water tank "); 
    lcd.setCursor(0,0);
    lcd.print("Put water in water tank" + String("                  "));
    delay(2000);
  }

  // TEMP SENSOR val_humidity
  DHT11.read(DHT11PIN);
  float val_humidity = ((float)DHT11.humidity, 2); 
  float val_temp = ((float)DHT11.temperature, 2);

  if (val_humidity > 90){
    Serial.println("humidity too high "); 
    lcd.setCursor(0,0);
    lcd.print("humidity too high" + String("                  "));
    delay(2000);
  }
  if (val_temp < 10){
    Serial.println("Temperature too low "); 
    lcd.setCursor(0,0);
    lcd.print("Temperature too low" + String("                  "));
    delay(2000);
  }

  // SOIL_MOISTURE_SENSOR
  int moisture_sens_val = 0;
  moisture_sens_val = analogRead(moisture_sens_pin);
  Serial.println(moisture_sens_val);

  if (moisture_sens_val > 900) {

    Serial.println("goes to pumpOn func");
    pumpOn();
     
  }

  lcd.setCursor(0,0);
  lcd.print("temp C: " + String((float)DHT11.temperature, 2) + "                  ");
  
  lcd.setCursor(0,1);
  lcd.print("humanidy: " + String((float)DHT11.humidity) + "                  " );

  delay(2000);

  lcd.setCursor(0,0);
  lcd.print("moisture: " + String(moisture_sens_val) + "                  ");
  
  lcd.setCursor(0,1);
  lcd.print("pump off" + String("                  "));

  delay(10000);
  } 

  void pumpOn() {
    lcd.clear(); 
    lcd.setCursor(0,0);
    lcd.print("pump on" + String("                  "));                               
    int curr_moisture_sens_val = 901;
    while (curr_moisture_sens_val > 900){
    Serial.println("Water Pump is ON ");
    digitalWrite(pump_pin, HIGH);
    Serial.println(curr_moisture_sens_val);
    curr_moisture_sens_val = analogRead(moisture_sens_pin);
    }
    digitalWrite(pump_pin, LOW);
  }
  
