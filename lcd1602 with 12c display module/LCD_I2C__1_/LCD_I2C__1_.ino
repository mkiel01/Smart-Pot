#include <Wire.h>
#include <LiquidCrystal_I2C.h>         

LiquidCrystal_I2C lcd(0x27, 16, 2);     

void setup()
{
  lcd.init();         
  lcd.backlight();    
  Serial.begin(9600); // so the Serial.printl works
}

void loop()
{
  lcd.clear(); 
  Serial.println("Working");                     
  lcd.setCursor (3, 0);             
  lcd.print("Get Started");         
  lcd.setCursor (0, 1);             
  lcd.print("with ARDUINO");        
  delay(2000);
  lcd.clear();                      
  lcd.setCursor (0, 0);             
  lcd.print("Experiment #6");       
  lcd.setCursor (3, 1);             
  lcd.print("LCD with I2C");        
  delay(2000);
}
