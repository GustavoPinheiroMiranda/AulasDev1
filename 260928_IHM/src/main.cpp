#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int ledA = 5;
const int ledB = 6;
const int ledC = 7;
const int ledD = 15;

const int pinBotao1 = 14;
const int pinBotao2 = 13;
const int pinBotao3 = 12;

static int selecaoAnterior = 0;

bool estadoLedA = false;
bool estadoLedB = false;
bool estadoLedC = false;
bool estadoLedD = false;

int selecao = 0;

void setup()
{
    lcd.init();
    lcd.backlight();

    pinMode(ledA, OUTPUT);
    pinMode(ledB, OUTPUT);
    pinMode(ledC, OUTPUT);
    pinMode(ledD, OUTPUT);

    pinMode(pinBotao1, INPUT_PULLUP);
    pinMode(pinBotao2, INPUT_PULLUP);
    pinMode(pinBotao3, INPUT_PULLUP);

    // TELA INICIAL

    lcd.setCursor(2, 0);
    lcd.print("LED A: OFF");

    lcd.setCursor(2, 1);
    lcd.print("LED B: OFF");

    lcd.setCursor(2, 2);
    lcd.print("LED C: OFF");

    lcd.setCursor(2, 3);
    lcd.print("LED D: OFF");

    lcd.setCursor(0, 0);
    lcd.print(">");
}

void loop()
{

    bool botaoAtual1 = digitalRead(pinBotao1);
    bool botaoAtual2 = digitalRead(pinBotao2);
    bool botaoAtual3 = digitalRead(pinBotao3);

    static bool botaoAnterior1 = HIGH;
    static bool botaoAnterior2 = HIGH;
    static bool botaoAnterior3 = HIGH;

    // BOTAO 1 - DESCE

    if (botaoAnterior1 == HIGH && botaoAtual1 == LOW)
    {
        selecao++;
        if (selecao > 3) selecao = 0;
    }

    // BOTAO 2 - SOBE

    if (botaoAnterior2 == HIGH && botaoAtual2 == LOW)
    {
        selecao--;
        if (selecao < 0) selecao = 3;
    }

    // BOTAO 3 - LIGA/DESLIGA O LED SELECIONADO

    if (botaoAnterior3 == HIGH && botaoAtual3 == LOW)
    {
        if (selecao == 0)
        {
            estadoLedA = !estadoLedA;
            digitalWrite(ledA, estadoLedA);
        }
        else if (selecao == 1)
        {
            estadoLedB = !estadoLedB;
            digitalWrite(ledB, estadoLedB);
        }
        else if (selecao == 2)
        {
            estadoLedC = !estadoLedC;
            digitalWrite(ledC, estadoLedC);
        }
        else if (selecao == 3)
        {
            estadoLedD = !estadoLedD;
            digitalWrite(ledD, estadoLedD);
        }
    }


    lcd.setCursor(2, 0);
    lcd.print("LED A: ");
    if (estadoLedA == true) lcd.print("ON");
    else lcd.print("OFF");

    lcd.setCursor(2, 1);
    lcd.print("LED B: ");
    if (estadoLedB == true) lcd.print("ON");
    else lcd.print("OFF");

    lcd.setCursor(2, 2);
    lcd.print("LED C: ");
    if (estadoLedC == true) lcd.print("ON");
    else lcd.print("OFF");

    lcd.setCursor(2, 3);
    lcd.print("LED D: ");
    if (estadoLedD == true) lcd.print("ON");
    else lcd.print("OFF");

    

   lcd.setCursor(0, selecaoAnterior);
   lcd.print(" ");

   lcd.setCursor(0, selecao);
   lcd.print(">");

selecaoAnterior = selecao;

    botaoAnterior1 = botaoAtual1;
    botaoAnterior2 = botaoAtual2;
    botaoAnterior3 = botaoAtual3;

    delay(100);
}