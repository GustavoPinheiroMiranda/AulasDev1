#include "func.h"

//======================================================
String obterNomeDaCor(int codigoDaCor)
{
  switch (codigoDaCor)
  {
  case 0:
  return "preto";

  case 1:
    return "marrom";

  case 2:
    return "vermelho";

  case 3:
  return "Laranja";
  
  case 4:
    return "Amarelo";

  case 5:
    return "Verde";

  case 6:
  return "Azul";

  case 7:
    return "Violeta";

  case 8:
    return "Cinza";

  case 9: 
    return "Branco";
  
  default:
     return "Invalido, escolha entre 0 á 9";
    
  }
}

//===============================================================
float calcularMedia(float valor1, float valor2)
{
  float resultado = (valor1 + valor2) / 2.0 ;
  return resultado;
}

//==============================================================
bool verificarTemperatura(int tempAtual, int limiteTemp)
{ 
  if(tempAtual <= limiteTemp)
    return true;

  else
    return false;
}
    // return tempAtual<= limiteTemp ? true : false;
//================================================================
bool botaoEstaPressionado(int pinBotao)
{
   bool estado = digitalRead(pinBotao);
   return estado ? false : true;

}