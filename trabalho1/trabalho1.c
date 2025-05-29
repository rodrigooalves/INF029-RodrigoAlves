// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Rodrigo Amorim Alves 
//  email: rodrigoamorim.bc@hotmail.com
//  Matrícula: 20241160002
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalho1.h" // Substitua pelo seu arquivo de header renomeado

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;
  DataQuebrada novaData = quebraData(data);
  if(novaData.valido == 0)
    datavalida = 0; 
  int dia = novaData.iDia, mes = novaData.iMes, ano = novaData.iAno;
  if(mes < 1 || mes < 12)
    datavalida = 0;
  if(ano < 0)
    datavalida = 0;
  if(mes == 2){
    if(dia > 29) {
      datavalida = 0;
    } 
  } else if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
    if(dia>29){
      datavalida = 0;
    }
    else {
      if(dia > 28){
        datavalida = 0;
      }
    }
  }

  if( mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
    if ( dia > 31){
      datavalida = 0;
    }
  }

  if (mes == 3|| mes == 6|| mes == 9 || mes == 11) {
    if ( dia > 30 )
      datavalida = 0;
  }

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      DataQuebrada dataInicial = quebraData(datainicial);
      DataQuebrada dataFinal = quebraData(datafinal);
      if(dataInicial.iAno > dataFinal.iAno || (dataInicial.iAno == dataFinal.iAno && dataInicial.iMes > dataFinal.iMes) || (dataInicial.iAno == dataFinal.iAno && dataInicial.iMes == dataFinal.iMes && dataInicial.iDia > dataFinal.iDia)){
        dma.retorno = 4;
        return dma;
      }  
      int dias = dataFinal.iDia - dataInicial.iDia;
      int meses = dataFinal.iMes - dataInicial.iMes;
      int anos = dataFinal.iAno - dataInicial.iAno;
      if(dias < 0){
        meses--;
        dias = dias + quantidadeDeDias((dataFinal.iMes == 1 ? 12 : dataFinal.iMes - 1), dataFinal.iAno);
      }
      if(meses < 0){
        anos--;
        meses = meses + 12;
      } 
      dma.qtdAnos = anos;
      dma.qtdMeses = meses;
      dma.qtdDias = dias;      
      dma.retorno = 1;
      return dma;      
    }    
}


/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
  int qtdOcorrencias = 0;
  int i = 0;
  char fraseSemAcento[127];
  if(isCaseSensitive){
    removerAcentos(texto, fraseSemAcento);
    while(texto[i] != '\0'){
      if(c == texto[i]){
        qtdOcorrencias++;
      }
      i++;
    }
  }
  if(!isCaseSensitive){
    removerAcentos(texto, fraseSemAcento);
    tudoMinusculo(fraseSemAcento);
    if(c>='A' && c<= 'Z'){
      c=c+32;
    }
    while(fraseSemAcento[i] != '\0'){
      if(fraseSemAcento[i] == c){
        qtdOcorrencias++;
      }
      i++;
    }    
  }
  return qtdOcorrencias;
}



/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0, j=0, k=0;
    int tamTexto = strlen(strTexto);
    int tamBusca = strlen(strBusca);
    
    for(int i = 0; i<tamTexto; i++){
      if(strBusca[0] == strTexto[i]){
        for(j=0; j<tamBusca; j++){
          if(strBusca[j] != strTexto[i+j]){
            break;
          }
        }
        if(j == tamBusca){
          qtdOcorrencias++;
          posicoes[k] = i + 1;
          k++;          
          posicoes[k] = i + tamBusca;
          k++;
          i = i + j - 1;
        }
      }
    }
    return qtdOcorrencias;
}
/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
  int casas = tamanhoNumero(num);
  int digitos[127];
  int base = 1;
  int numInvertido=0;
  for(int i=0; i < casas; i++){
    digitos[i] = (num/base)%10;
    base *= 10;
  }
  for(int i = 0; i < casas; i++){
    numInvertido = numInvertido + digitos[i]*base;
    base = base/10;
  }
  numInvertido = numInvertido/10;
  return numInvertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0;
    int j;
    int tamNumBase = tamanhoNumero(numerobase);
    int tamNumBusca = tamanhoNumero(numerobusca);
    char numBaseString[127];
    sprintf(numBaseString, "%d", numerobase); // 3567
    char numBuscaString[127];
    sprintf(numBuscaString, "%d", numerobusca); //56
    for(int i = 0; i <= tamNumBase - tamNumBusca; i++){
      if(numBuscaString[0]==numBaseString[i]){
        for(j = 0; j < tamNumBusca; j++){
          if(numBuscaString[j] != numBaseString[j+i]){
            break;
          }
        }
        if(j == tamNumBusca){
          qtdOcorrencias++;
          i = i + tamNumBusca - 1;          
        }
      }
    }
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[5]) {
    int linhas = 8, colunas = 10;
    int tamPalavra = strlen(palavra);
    
    int direcoes[8][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}};
    
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            for (int d = 0; d < 8; d++) {
                int dirX = direcoes[d][0], dirY = direcoes[d][1];
                int k, x = i, y = j;
                int encontrado = 1;
                
                for (k = 0; k < tamPalavra; k++) {
                    if (x < 0 || x >= linhas || y < 0 || y >= colunas || matriz[x][y] != palavra[k]) {
                        encontrado = 0;
                        break;
                    }
                    x += dirX;
                    y += dirY;
                }
                
                if (encontrado) {
                    return 1;  
                }
            }
        }
    }
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}