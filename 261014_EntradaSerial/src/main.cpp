#include <Arduino.h>

void funcaoBloquante() ;
void funcaoNaoBloqueante();
void processarFrase(char* texto);



void setup()
{
  Serial.begin(115200);

  //? o metodo readStringUntil espera no maximo por carcter esse tempo(ms) pelo '\n'
  Serial.setTimeout(2000);
  Serial.println();
  

}

void loop() 
{
  funcaoNaoBloqueante();
   
}

void funcaoNaoBloqueante()
{
  const int TAMANHO_MAX = 50;  //? TAMANHO DO VETOR QUE INCLUI '\0 ' 
   static char frase[TAMANHO_MAX];
   static int position = 0;


   while(Serial.available() > 0)
   {
    char c = Serial.read();
    
    if(c == '\r') continue;
    //? o continue pula o restante do while() naquela volta e passa para leitura
    //? odo proximo caractere. O '\r'é lido e simplesmente descartado, sem entrar no vetor

    if(c== '\n')
    {
      
      frase[position] = '\0';
      if(position > 0) processarFrase(frase);
      position = 0;
    }

    else if(position < TAMANHO_MAX - 1)
    {
      frase[position] = c;
      position++;
    }
   }

}
//? VERMELHO, VERDE ,  AZUL , BRANCO, DESLIGA
//? RGB  r g b  (ex.: RGB 255 180 5 )
//? BRILHO n (0 a 100%)

void processarFrase(char* texto)
{
    Serial.printf("Recbido: [%s]\n\r" , texto);

    char* comando = texto;
    char* parametro = NULL; //? '\0
    
    char* espaco = strchr(texto, ' '); //* procura pelo primeiro espaço no texto

    if(espaco != NULL)
    {
      *espaco = '\0';  //* substitui o espaço por um '\0'
      parametro  = espaco + 1;
     
    }

    if(strcasecmp(comando, "VERMELHO") == 0)
    {


    }
    
    else if(strcasecmp(comando, "VERDE") == 0)
    {

    }
    else if(strcasecmp(comando, "AZUL") == 0)
    {

    }
    else if(strcasecmp(comando, "BRANCO") == 0)
    {
      
    }
    else if(strcasecmp(comando, "DESLIGA") == 0)
    {
      
    }
    else if(strcasecmp(comando, "RGB") == 0)
    {
      
    }
    else if(strcasecmp(comando, "BRILHO") == 0)
    {
      
    }
    else
    {
      
    }



//     if(strcmp(texto , "ola") == 0)
//     {
//       Serial.println("Ola para voce tambem");
//     }
// }


}

void funcaoBloquante() 
{
  //? available() diz quantos bytes já chegaram e estao esperando leitura
  if(Serial.available() > 0)
  {
    String texto = Serial.readStringUntil('\n') ; //! FUNCAO BLOQUANTE
    
    //? trim() remove do fim do texto os espaços, '\r' , '\t' , '\n' que alguns terminaris enviam 
    texto.trim();

    if(texto.length() == 0) return;
    Serial.printf("Seu nome é %s\n\r" , texto.c_str() );

    String textoMaiusculas = texto;
    textoMaiusculas.toUpperCase();
    
    if(textoMaiusculas == "GUSTAVO")
    Serial.println("Esse é o seu nome correto. ");

  }

}


