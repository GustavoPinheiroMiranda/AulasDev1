#include <Arduino.h>
#include "led.h"

Led ledAmarelo1(4);
Led ledAmarelo2(5);
Led ledAmarelo3(6);
Led ledAmarelo4(7);


void setup() 
{
  ledAmarelo1.iniciar();
  ledAmarelo2.iniciar();
  ledAmarelo3.iniciar();
  ledAmarelo4.iniciar();

  ledAmarelo1.ativarPiscar(100);
  ledAmarelo2.ativarPiscar(300);
  ledAmarelo3.ativarPiscar(600);
  ledAmarelo4.ativarPiscar(200);
}

void loop()
{
  ledAmarelo1.atualizar();
  ledAmarelo2.atualizar();
  ledAmarelo3.atualizar();
  ledAmarelo4.atualizar();
  
}