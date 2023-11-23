//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // coloca o address do LCD como 0x3F, 16 caracteres em 2 linhas

const int boiaPin = 3; // Aqui teremos o pino do Arduino equivalente à boia



void setup()
{
  pinMode(boiaPin, INPUT_PULLUP);
  lcd.init();                      
  lcd.backlight(); 
  lcd.setCursor(3,0); // se quisermos mudar o espaçamento, seria aqui. é 3,0 porque queremos centralizar a mensagem.
  lcd.print("AquaSight"); 
  delay(2000);
}


void loop()
{
  bool estadoBoia = digitalRead(boiaPin); //verificando se a boia está em pé ou não
  while (estadoBoia == true){ // Se não estiver em pé

    
    lcd.setCursor(0, 0);
    lcd.print("Sem problemas.");
    lcd.setBacklight(1);
    delay(2000);
    estadoBoia = digitalRead(boiaPin);
    if (estadoBoia == false){
      lcd.clear();
    }
    
    
  }
  while (estadoBoia == false){ // Se estiver em pé
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
