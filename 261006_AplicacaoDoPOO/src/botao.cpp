// botao.cpp


#include "botao.h"

Botao::Botao(uint8_t pino) : _pinoBotao(pino)
{
   // this-> pino = pino;
}

void Botao :: iniciar()
{
    _estadoAnteriorBotao;
    pinMode(_pinoBotao, INPUT_PULLUP);

}
void Botao :: atualizar()
{
   digitalRead(_pinoBotao);
}

bool Botao::pressionou()
{
     
     if ( _estadoAtualBotao = ! _estadoAnteriorBotao )
     {
        if(_estadoAnteriorBotao = 1)
        {
            return 1;
        }
     }
 
}

bool Botao :: soltou()
{
        
     if ( _estadoAtualBotao = ! _estadoAnteriorBotao )
     {
        if(_estadoAnteriorBotao = 0)
        {
            return 1;
        }
     }
 

}