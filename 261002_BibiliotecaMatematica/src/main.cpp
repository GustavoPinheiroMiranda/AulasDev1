#include <Arduino.h>
#include "func.h"


void setup() 
{
   Serial.begin(9600);

}

void loop()
 {
   for(int i = 1; i < 4; i++)
   {
    Serial.println("  ");
    Serial.println( i);
    Serial.println(" - ");
    Serial.println(calculadoraMagica(i,30,60));
   }
   while (1);
 
   
}