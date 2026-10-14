//=========================================
//Projeto: Aplicação de POO
//Descrição: Aplicar conhecimentos do poo para criação do projeto
//Autor: Gustavo Pinheiro
//Versão: 0.1
//=========================================
#include <Arduino.h>
#include "led.h"
#include "botao.h"

Led ledAmarelo1(5);
Led ledAmarelo2(6);

Botao btn1(10);
Botao btn2(11);

void setup()
{
    btn1.iniciar();
    btn2.iniciar();

    ledAmarelo1.iniciar();
    ledAmarelo2.iniciar();

    ledAmarelo1.estadoLento();
    ledAmarelo2.estadoLento();
}

void loop()
{
   
    if (btn1.pressionou())
    {
        ledAmarelo1.estadoRapido();
        ledAmarelo2.estadoRapido();
    }

   
    if (btn2.pressionou())
    {
        ledAmarelo1.estadoLento();
        ledAmarelo2.estadoLento();
    }

    ledAmarelo1.atualizar();
    ledAmarelo2.atualizar();
}