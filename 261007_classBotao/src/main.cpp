#include <Arduino.h>
#include "botao.h"

Botao botao1(10);
int Led1 = 4;
int _contador = 0;

void setup() 
{
  Serial.begin(9600);
 pinMode(Led1, OUTPUT);
 botao1.iniciar();
 
//  botao1.setTempoDebounce(15);
}

void loop() 
{
  
  botao1.atualizar();
  
  if(botao1.pressionou())
  {
    digitalWrite(Led1, HIGH);
    _contador++;
  }
  // else 
  //  {
  //   if (botao1.soltou())
  //   {
  //   digitalWrite(Led1, LOW);
  //   }
  //  }
  
   Serial.println(_contador);
}


//@param 