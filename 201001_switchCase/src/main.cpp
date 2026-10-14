#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int valor = 3;

  switch (valor)
  {
  case 1:

    Serial.println("um");

    break;

  case 2:
    Serial.println("dois");
    break;

  case 3:
    Serial.println("tres");
    break;

  case 4:

    Serial.println("quatro");

    break;

  default:

    Serial.println("numero nao reconhecido");

    break;
  }
}
