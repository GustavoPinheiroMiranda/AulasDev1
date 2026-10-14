#include <Arduino.h>
#include "led.h"

Led ledAmarelo1(4);
Led ledAmarelo2(5);
Led ledAmarelo3(6);
Led ledAmarelo4(7);


void setup()
{
 ledAmarelo1.iniciar();
 ledAmarelo1.piscar(300);
 ledAmarelo1.ativarPiscar();


 ledAmarelo2.iniciar();
 ledAmarelo2.piscar(400);
 ledAmarelo2.ativarPiscar();

 ledAmarelo3.iniciar();
 ledAmarelo3.piscar(600);
 ledAmarelo3.ativarPiscar();

 ledAmarelo4.iniciar();
 ledAmarelo4.piscar(800);
 ledAmarelo4.ativarPiscar();
}

void loop() 
{
   ledAmarelo1.atualizar();
   ledAmarelo2.atualizar();
   ledAmarelo3.atualizar();
   ledAmarelo4.atualizar();
}