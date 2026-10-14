#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int tempoDeEspera = 200;
unsigned int contador = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 3);
  lcd.print(contador);
  Serial.begin(9600);
   
}
void loop()

{
  unsigned long agora = millis();
  static int tempoInicial = 0;

  if (agora > tempoInicial + tempoDeEspera)
    
   {
    contador = contador + 1;
    tempoInicial = agora;
   }
   
   if(contador > 100)
   contador = contador -1;

  Serial.println(contador);
  lcd.setCursor(0, 3);
  lcd.print(contador);

}

