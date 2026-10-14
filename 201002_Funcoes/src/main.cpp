#include <Arduino.h>
#include "func.h"



void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
    for(int i =0; i< 10; i++)
  {
    Serial.print(i);
    Serial.print(" - ");
    Serial.println(obterNomeDaCor(i) );
  }

  Serial.print("Média entre 27.2 e 43.8 é :  ");
  Serial.println( calcularMedia(27.2 , 43.8));


  if (verificarTemperatura(30,35))
    Serial.print("Temperatura OK");
  if(verificarTemperatura(36,35))
    Serial.print("temperatura OK");
  else 
    Serial.print("temperatura Alta");


  while(botaoEstaPressionado(12))
  {
    Serial.println("Botao pressionado");
  }
    
  

  

}

