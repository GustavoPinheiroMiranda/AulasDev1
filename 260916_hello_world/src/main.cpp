#include <Arduino.h>

const int pinLedVermelho = 1;
const int pinLedVerde = 0;
const int pinLedAmarelo = 39;
const int umSegundo = 1000;
  
void setup()
{
  Serial.begin(9600);
  pinMode(pinLedVermelho, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);
  pinMode(pinLedAmarelo, OUTPUT);
}

void loop()
{
  unsigned long agora = millis();
  static unsigned long tempoInicial = 0;
  static bool estadoLedVermelho = 0;
  static bool estadoLedVerde = 0;
  static bool estadoLedAmarelo = 0;
  static int contador = 0;
  static int tempoPisca = 500;
 
  
  if (agora>tempoInicial + tempoPisca)
{
  estadoLedVermelho = !estadoLedVermelho;
  tempoInicial=agora;
}
  digitalWrite(pinLedVermelho, estadoLedVermelho);

}
