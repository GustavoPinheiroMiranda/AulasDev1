#include <Arduino.h>

unsigned long valorA = 0;
unsigned long valorB = 1;
unsigned long resultado = 0;



void setup()
{
    Serial.begin(9600);
    Serial.println( );

    for (int i = 2; i < 20; i++)
    {
        Serial.print("A soma de ");
        Serial.print(valorA);
        Serial.print(" e ");
        Serial.print(valorB);
        Serial.print(" é ");
        resultado = valorA + valorB;
        Serial.println(resultado);
        delay(1000);

        valorA = valorB;
        valorB = resultado;
    }
}

void loop()
{
}