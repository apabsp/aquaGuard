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
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
}


void loop()
{
  bool estadoBoia = digitalRead(boiaPin);
  if (estadoBoia == true){
    lcd.setCursor(0, 1);
    lcd.begin(16, 2);
    lcd.print("De Boa");
    lcd.setBacklight(1);
    
    
  }
  else if (estadoBoia == false){
    lcd.setCursor(0, 1);
    lcd.begin(16, 2);
    lcd.print("VIA CONGESTIONADA! PERIGO!!!");
    lcd.setBacklight(1);
  }

}