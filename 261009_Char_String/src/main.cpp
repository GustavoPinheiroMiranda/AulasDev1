#include <Arduino.h>
#include <string.h> //? strlen, strcpy, strcat, strcmp, strchr
#include <stdlib.h> //? atoi


void textoTipoC();
void textoTipoString();


void setup() 
{
   Serial.begin(9600);
   Serial.println();
   textoTipoC();
   textoTipoString();
}


void loop() 
{

}

void textoTipoC()
{
    //? Texto literal
    //? Use const char* quando o texto não será alterado

    const char* cidade = "Sao Paulo";
    const char outraCidade[] = "Sao Caetano";

    Serial.println(cidade);
    Serial.println(outraCidade);

    //? Descobrindo o tamanho do texto
    //? strlen conta quantos caracteres antes de '\0'
    int tamanhoTextoCidade = strlen(cidade);
    int tamanhoOutraCidade = strlen(outraCidade);

    Serial.print("Comprimento do texto em carecteres: ");
    Serial.println(tamanhoTextoCidade);

    Serial.print("Tamanho do conteudo do ponteiro: ");
    Serial.println(tamanhoOutraCidade);

    //? Descobrindo o tamanho ocupado

    int tamanhoVariavel = sizeof(outraCidade);
    int tamanhoPonteiro = sizeof(cidade);

    //? Quando usado o sizeof em uma string sempre retornará
    //? um byte a mais do que a quantidade de caracteres por 
    //? causa do '\0 que finaliza o texto

    Serial.print("Tamanho de Variavel em bytes: ");
    Serial.println(tamanhoVariavel);

    //? Qunado usamos o sizeof em ponteiros retorna sempre 4 bytes
    //? pois o conteudo dele é um endereço de memoria como 0xFF00C245

    Serial.print("Tamanho do ponteiro: ");
    Serial.println(tamanhoPonteiro);

    // o caractere '\0' é colocado automaticamente quando escrevemos
    // um texto entre aspas duplas " ".

    const char vetorTexto[8] = {'G' , 'U' , 'S' , 'T' , 'A' , 'V', 'O' , '\0'};
    Serial.println ( vetorTexto);

    //? Comparar texto
    const char* cidade1 = "Porto Alegre";
    const char* cidade2 = "Porto Alegre";

    if(strcmp(cidade1, cidade2) == 0)
      Serial.println("As strings são iguais");

    else 
      Serial.println("As strings são diferentes");

  //? strcmp analiza a ordem lexica das palavras, se a primeira palavra vem antes
  //? que a segunda o valor retornado será menor que zero, se a primeira vem após
  //? a segunda o retorno será maior que zero.

  //================================================================================
  //? Texto Editavel com char()
  //================================================================================

  char nomeAluno[8] = "Gustavu";
    Serial.println(nomeAluno);
  nomeAluno[6] = 'o';
    Serial.println(nomeAluno);

  //? Copiando outro texto para dentro do vetor
  //! Cuidado; o vetor precisa ter espaço suficiente 

  strcpy(nomeAluno, "Tadeu");
  Serial.println(nomeAluno);

  //? Concatenando texto ao final

  char frase[40] = "Ola ";
  strcat(frase, "Mundo Cuel !! ");
  Serial.println(frase);

  //? Procurando um caractere no texto

  char* posicaoLetra = strchr(frase, 'M');

  if(posicaoLetra != NULL)
  {
     Serial.println("Letra encontrada");
     Serial.println(posicaoLetra);
  }
  else 
  Serial.println("Letra não encontrada");

  //? Convertendo texto numérico para inteiro
  char idadeTexto[] = "39";
  int idade = atoi(idadeTexto);

  //? Montando Texto
  
  char buffer [100];
  char* local = "Sala de Aula";
  float  temperatura = 26.4;
  int umidade = 72;

  snprintf (buffer, sizeof(buffer), " %s | Temp: %f | Umid: %d %% \n\r", local, temperatura, umidade);

  Serial.print(buffer);

  //? snprintf monsta o texto dentro de um vetor de char
  //? Isso é muito útil quando depois você quer:'
  //? - envirar por MQTT
  //? - salvar em variavel
  //? - mandar para o display
  //? - Imprimir na Serial
  //?
  // ===== esorecificadores 
  //?
  //?     %d ou %i     -int
  //?     %u           -unsigned int
  //?     %ld          -long
  //?     %lu          -unsigned long
  //?     %f           -float
  //?     %e           -notação cientifica
  //?     %g           -foat, formato mais curto
  //?     %c           -char
  //?     $s           -char*
  //?     %x ou %X     -hexadecimal minúsculo/maiúsculo
  //?     %o           -octal
  //?     %p           -ponteiro
  //?     %%           - o próprio %
  //?
  //?  Flags, largura e precisão
  //?
  //?     %5d    -imprime com largura minima de 5, alinhado a direita [   3] [   100] [100000]
  //?     %-2d   -imprime com largura mínima de 2 , alinhado a esquera
  //?     %04d   -completa com zeros ex. 0022
  //?     %+d    -sempre mostra o sinal ex. +5
  //?     %.2f   -2 casas decimais
  //?     %4.2f  -largura de 4 com 2 casas 
  //?     %02X   -hexadecimal com 2 digitos
  //?     %#x    -prefixo 0x
  //?     %.3s  -Só os primeiros 3 caracteres da string
  //?     %*d    -largura passada como argumento ex. snprintf(buffer, sizeof(buffer), "%*d", 5, 42) [   42]

}

void textoTipoString()
{
  String nome = "Gustavo";
  String curso = "Desenvolvimento de Sistema";
  String mensagem = "Olá";

  mensagem = mensagem + ", " + nome + "! Bem vindo ao curso de " + curso + ".";
  Serial.println(mensagem);

  //* Tamanho da String

  int tamanhoMensagem = mensagem.length();
  Serial.printf("Tamanho da String em letra: %u\n\r", tamanhoMensagem);

  //* Acessando um caractere em uma posição especifica
  char primeiraLetra = mensagem.charAt(0);
  Serial.printf("Primeira letra: %c\n\r", primeiraLetra);
  
  //* Tambem é possivel acessar com colcheste
  char ultimaLetra = mensagem[tamanhoMensagem - 1];
  Serial.printf("Ultima letra : %c\n\r" , ultimaLetra);

  //* Procurando umt exto dentro da String
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.printf("A palavra procurada está na posicao: %d\n\r", posicaoTextoProcurado);

  int inicioNomeCurso = posicaoTextoProcurado + 9; // posição da palavra curso + 9 posições a frente

  String nomeDoCursoTexto =  mensagem.substring(inicioNomeCurso, tamanhoMensagem -1);
  Serial.printf("Nome do curso: %s\n\r", nomeDoCursoTexto.c_str());

  //* Subtituindo um trecho dentro da String 
  mensagem.replace("Olá, " , "Boa tarde!!! ");
  Serial.println(mensagem);

  //* Convertendo tudo em maiusculas
  mensagem.toUpperCase ();
  Serial.println(mensagem);

  //* Convertendo tudo em Minusculas
  mensagem.toLowerCase();
  Serial.println(mensagem);

  // char letraMinuscula = mensagem[0] + ' ';
  // Serial.println(letraMinuscula);


  //* Verificando se uma string está vazia
  String textoVazio = "";
  if(textoVazio.length() == 0 ) Serial.println("O texto está Vazio");

  //* Convertendo texto numérico para inteiro
  String textoNumero = "725";
  int numero = textoNumero.toInt();
  Serial.print(numero / 5);

  //* Convertendo String para const char* (texto tipo c)
  //* Isso é util quando alguma biblioteca espera texto estilo C)
  const char* textoComoChar = mensagem.c_str();
Serial.println ( textoComoChar);
  
}
