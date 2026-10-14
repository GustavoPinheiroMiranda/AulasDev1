#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Botao.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

Botao btnCima(13);
Botao btnBaixo(14);
Botao btnEnter(12);

const int pinLeds[4] = {5, 6, 7, 15};

void telaInicial();

void setup()
{

  btnCima.iniciar();
  btnBaixo.iniciar();
  btnEnter.iniciar();

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  for (int i = 0; i < 4; i++)
    pinMode(pinLeds[i], OUTPUT);

  telaInicial();
}
void loop()
{

  btnBaixo.atualizar();
  btnCima.atualizar();
  btnEnter.atualizar();

  static int posicaoSeletor = 0;
  static int posicaoSeletorAnterior = 0;
  static bool estadosLeds[4] = {0, 0, 0, 0};
  bool alteracaoDisplay = 0;

  if (btnBaixo.pressionou())
  {
    if (posicaoSeletor < 3)
      posicaoSeletor++;
  }

  if (btnCima.pressionou())
  {
    if (posicaoSeletor > 0)
      posicaoSeletor--;
  }

  if (btnEnter.pressionou())
  {
    estadosLeds[posicaoSeletor] = !estadosLeds[posicaoSeletor];
    alteracaoDisplay = 1;
  }

  // ===============LEDS================
  for (int i = 0; i < 4; i++)

    digitalWrite(pinLeds[i], estadosLeds[i]);

  //==================Displays================
  if (posicaoSeletor != posicaoSeletorAnterior)
  {
    lcd.setCursor(0, posicaoSeletor);
    lcd.print(">");
    lcd.setCursor(0, posicaoSeletorAnterior);
    lcd.print(" ");

    posicaoSeletorAnterior = posicaoSeletor;
  }

  if (alteracaoDisplay)
  {
    lcd.setCursor(8, posicaoSeletor);
    lcd.print(estadosLeds[posicaoSeletor] ? "LIGADO   " : "DESLIGADO");
    // estadosLeds[posicaoSeletor] ? lcd.print("LIGADO    ") :  lcd.print("DESLIGADO");
  }

  void telaInicial();
  {

    lcd.setCursor(0, 0);
    lcd.print(" LED A DESLIGADO");

    lcd.setCursor(0, 1);
    lcd.print(" LED B DESLIGADO");

    lcd.setCursor(0, 2);
    lcd.print(" LED C DESLIGADO");

    lcd.setCursor(0, 3);
    lcd.print(" LED D DESLIGADO");
  }
}

// if(condicao)
// {
//   true
// }
//  else
//  {
//   false
//  }

//  condicao ? true : false