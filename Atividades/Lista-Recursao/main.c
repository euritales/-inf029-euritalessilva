// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Euritales Silva dos Santos
//  email: euritales00@gmail.com
//  Matrícula:20192160011
//  Semestre: 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "EuritalesSilva-20192160011.h"

int main(){

int num1 = 6;
int num2 = 2;
int vetor[3] ={21,3,5};
int resultado;

resultado = fatorial(num1);
printf("\nQ1:%d", resultado);

resultado = fibo(num1);
printf("\nQ2:%d", resultado);

resultado = somarVetor(vetor, 3);
printf("\nQ4:%d", resultado);

resultado = soma1(num1);
printf("\nQ5:%d", resultado);

resultado = potencia(num1, num2);
printf("\nQ6:%d", resultado);

resultado = mDC(num1, num2);
printf("\nQ8:%d", resultado);

resultado = findNum(6, 6, 0);
printf("\nQ10:%d", resultado);

resultado = somaSucessiva(num1, num2);
printf("\nQ11:%d", resultado);

resultado = fatDuplo(9);
printf("\nQ16:%d", resultado);

resultado = tribonacci(num1);
printf("\nQ21:%d", resultado);

resultado = tetranacci(num1);
printf("\nQ22:%d", resultado);

resultado = padovan(num1);
printf("\nQ23:%d", resultado);

resultado = pell(num1);
printf("\nQ24:%d", resultado);

resultado = catalan(num1);
printf("\nQ25:%d", resultado);
}

