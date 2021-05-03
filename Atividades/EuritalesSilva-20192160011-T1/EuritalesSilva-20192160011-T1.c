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
//  Nome: Euritales Silva dos Santos
//  email: euritales00@gmail.com
//  Matrícula:20192160011
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    int soma = 0;
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
    int fat = 1;
    return fat;
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
int validarDatas(int dia, int mes, int ano);
int verificadorData(char datas);
int q1(char *data){
    
    int datavalida = 1;
    int i = 0;
    int j = 0;
    int aux = 0;
    char diaString[3];
    char mesString[3];
    char anoString[5];
    int dia = 0;
    int mes = 0;
    int ano = 0;
    int validar;
    
    for (i = 0; data[i] != '/'; i++){

        diaString[i] = data[i];

        if(i > 2){
            return 0;
        }else if(verificadorData(diaString[i]) == 1){
            return 0;
        }
    }

    diaString[i] = '\0';
    i++; 
    
    if(strlen(diaString) == 0){
        return 0;
    }else{
        dia = atoi(dia);
    }

   for(j = i; data[j] != '/'; j++){
        mesString[aux] = data[j];

        if(aux > 1){
            return 0;
        }else if(verificadorData(mesString[aux]) == 1){
            return 0;
        }
        aux++;
    }

    mesString[j] = '\0';
    j++;

    if(strlen(mesString) == 0){
        return 0;
    } 

    mes = atoi(mesString);

    aux = 0;

    for(i = j; i < strlen(data); i++, aux++){
        
        anoString[aux] = data[i];

        if(verificadorData(data[i]) == 1){
            return 0;
        }
    }

    if(aux != 2 || aux != 4){
        return 0;
    }else{
        anoString[aux] = '\0';
        ano = atoi(anoString);
    }

    validar = validarDatas(dia, mes, ano);
    
    return validar;
}
    
    int validarDatas(int dias, int meses, int anos){
    
        if((dias < 1 || dias > 31) || (meses < 1 || meses > 12) || (anos < 1 || anos > 2020)){
            return 0;
        }
        
        if (dias > 29 && (meses == 2 && anos % 4 == 0 || anos % 400 == 0 && anos % 100 != 0)){
            return 0;
        }
        if (dias > 28 && (meses == 2 && anos % 4 != 0 || anos % 400 != 0 && anos % 100 == 0)){
            return 0;
        } 
        if (dias > 30 && (meses == 4 || meses == 6 || meses == 9 || meses == 11)){
            return 0;
        }
        return 1;
    }
    
    int verificadorData(char datas){
        
        if (datas < 48 || datas > 57){
        return 1;
        }else{
            return 0;
        }
    }
   
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
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

    int qtdCaracteres = 0;
    int i = 0;
    int qtdOcorrencias = 0;

    qtdCaracteres = strlen(texto);

    if(isCaseSensitive == 1){
        for(i = 0; i < strlen(texto); i++){
            if(texto[i] == c){
                qtdOcorrencias ++;
            }
        }
    }else{
        for(i = 0; i < strlen(texto); i++){
            if(texto[i] == c || texto[i] == toupper(c) ||texto[i] == tolower(c)){
                qtdOcorrencias++;
            }
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
    int i;
    int j = 0;
    int k = 0;
    int aux = 0;
    int qtdOcorrencias = 0;

   for(i = 0; i < strlen(strTexto); i++){
        if(strBusca[0] == strTexto[i]){
            while(strBusca[j] == strTexto[i]){
                i++;
                j++;
            }
                
            if(j == strlen(strBusca)){
                posicoes[k] = i - (strlen(strBusca) - 1) - aux;
                k++;
                posicoes[k] = i - aux;
                k++;
             }
            j = 0;
        }
        if(strTexto[i] < 0 && strTexto[i+1] < 0){
            aux++;
        }
    }
    
    qtdOcorrencias = k / 2;
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

int q5(int num)
{
    int novoNumero = 0;

    novoNumero = (((num % 100) % 10) * 100) + (((num % 100) / 10) * 10) + (num / 100);
    // 543 = 300+40+3
    num = novoNumero;

    return num;
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

int q6(int numerobase, int numerobusca)//34567368
{
    int qtdOcorrencias = 0;
    int novoNumeroBase = numerobase;
    int novoNumeroBusca = numerobusca;
    int base[100];
    int busca[100];
    int i, j;
    int tamanhoBase = 0;
    int tamanhoBusca = 0;
    int novoTamanhoBase = 0;
    int novoTamanhoBusca = 0;
   
   while(novoNumeroBase >=10){
        novoNumeroBase = novoNumeroBase / 10;
        tamanhoBase++;
    }
    novoTamanhoBase = tamanhoBase;
    novoNumeroBase = numerobase;
    
    while (novoNumeroBusca >=1){
        novoNumeroBusca = novoNumeroBusca /10;
        tamanhoBusca++;
    }
   	novoTamanhoBusca = tamanhoBusca - 1;
    novoNumeroBusca = numerobusca;

    for(i = 0; i <= tamanhoBase; i++){ //34567368 - 4567368
        if(novoTamanhoBase == 7){
            base[i] = novoNumeroBase / 10000000;
            novoNumeroBase =  novoNumeroBase % 10000000;
        } else if(novoTamanhoBase == 6){
            base[i] = novoNumeroBase / 1000000;
            novoNumeroBase =  novoNumeroBase % 1000000;
        } else if(novoTamanhoBase == 5){
            base[i] = novoNumeroBase / 100000;
            novoNumeroBase =  novoNumeroBase % 100000;
        } else if(novoTamanhoBase == 4){
            base[i] = novoNumeroBase / 10000;
            novoNumeroBase =  novoNumeroBase % 10000;
        } else if(novoTamanhoBase == 3){
            base[i] = novoNumeroBase / 1000;
            novoNumeroBase =  novoNumeroBase % 1000;
        } else if(novoTamanhoBase == 2){
            base[i] = novoNumeroBase / 100;
            novoNumeroBase =  novoNumeroBase % 100;
        } else if(novoTamanhoBase == 1){
            base[i] = novoNumeroBase / 10;
            novoNumeroBase =  novoNumeroBase % 10;
        } else{
        	base[i] = novoNumeroBase;
		}
		novoTamanhoBase--;

    }

    for(i = 0; i < tamanhoBusca; i++){ //3
		if(novoTamanhoBusca == 6){
            busca[i] = novoNumeroBusca / 1000000;
            novoNumeroBusca = novoNumeroBusca % 1000000;
        } else if(novoTamanhoBusca == 5){
            busca[i] = novoNumeroBusca / 100000;
            novoNumeroBusca = novoNumeroBusca % 100000;
        } else if(novoTamanhoBusca == 4){
            busca[i] = novoNumeroBusca / 10000;
            novoNumeroBusca = novoNumeroBusca % 10000;
        } else if(novoTamanhoBusca == 3){
            busca[i] = novoNumeroBusca / 1000;
            novoNumeroBusca = novoNumeroBusca % 1000;
        } else if(novoTamanhoBusca == 2){
            busca[i] = novoNumeroBusca / 100;
            novoNumeroBusca = novoNumeroBusca % 100;
        } else if(novoTamanhoBusca == 1){
            busca[i] = novoNumeroBusca / 10;
            novoNumeroBusca = novoNumeroBusca % 10;
        }else{
             busca[i] = novoNumeroBusca;
        }
        novoTamanhoBusca --;
	}   

    int aux = 0;
    int verificador = -1;
    if(numerobase == numerobusca){
        qtdOcorrencias++;
    }else{
        for(i = 0; i <= tamanhoBase; i++){ //3 5 3 5 3 9 3 4 3    (3 5 3)        
            aux = i;
			for(j = 0; j < tamanhoBusca; j++){
                if(busca[j] == base[aux]){
                    verificador = 0;
                    aux++;
                }else{
                    j = tamanhoBusca;
                    verificador = 1;
                }
            }
            if(verificador == 0){
                qtdOcorrencias++;
            }
        }

    }
    

    return qtdOcorrencias;
}