//! botao.h

#ifndef __BOTAO_H__
#define __BOTAO_H__

#include <Arduino.h>

class Botao
{
   private:
    uint8_t _pinoBotao;
    bool _estadoAtualBotao = 1;
    bool _estadoAnteriorBotao = 1;

   public:

   Botao(uint8_t pino);

   void iniciar();
   void atualizar();
   bool pressionou();
   bool soltou();


};

#endif