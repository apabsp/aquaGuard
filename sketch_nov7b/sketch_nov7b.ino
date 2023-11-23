//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int boiaPin = 3;



void setup()
{
  pinMode(boiaPin, INPUT_PULLUP);
  lcd.init();                      
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("AquaSight");
  delay(2000);
}


void loop()
{
  bool estadoBoia = digitalRead(boiaPin);
  while (estadoBoia == true){

    
    lcd.setCursor(0, 0);
    lcd.print("Sem problemas.");
    lcd.setBacklight(1);
    delay(2000);
    estadoBoia = digitalRead(boiaPin);
    if (estadoBoia == false){
      lcd.clear();
    }
    
    
  }
  while (estadoBoia == false){
    lcd.setCursor(0, 0);
    lcd.print("PERIGO!!! VIA");
    lcd.setCursor(0, 1);
    lcd.print("CONGESTIONADA!");
    lcd.setBacklight(1);
    estadoBoia = digitalRead(boiaPin);
    if (estadoBoia == true){
      lcd.clear();
    }
  }

}
