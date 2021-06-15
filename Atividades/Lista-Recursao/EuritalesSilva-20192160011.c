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


//Q1
int fatorial(int n) {
	if(n < 2) {
		return 1;
	}
	return n * fatorial(n - 1);
}

//Q2
int fibo(int n) {
	if(n < 2) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

//Q4
int somarVetor(int vet[], int n) {
	if(n == 1) {
		return vet[0];
	}
	return vet[n - 1] + somarVetor(vet, n - 1);
}

//Q5
int soma1(int n) {
	if(n == 1) {
		return 1;
	}
	return n + soma1(n - 1);
}

//Q6
int potencia(int k, int n) {
	if(n == 1) {
		return k;
	}
	return k * potencia(k, n - 1);
}

//Q8
int mDC(int a, int b) {
	if( b == 0) {
		return a;
	}
	mDC(b, a % b);
}

//Q10
int findNum(int n, int k, int i) {
	if(n % 10 == k) {
		i++;
	}
	if(n % 10 == n) {
		return i;
	}
	findNum(n / 10, k, i);
}

//Q11
int somaSucessiva(int a, int b) {
	if(a == 0 || b == 0) {
		return 0;
	}
	if(b == 1) {
		return a;
	}
	return a + somaSucessiva(a, b - 1);
}

//Q16
int fatDuplo(int n) {
	if(n == 1) {
		return 1;
	}
	if(n % 2 == 0) {
		return 0;
	}
	return n * fatDuplo(n - 2);
}

//Q21
int tribonacci(int n) {
	if(n == 0 || n == 1) {
		return 0;
	}
	if(n == 2) {
		return 1;

	}
	return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

//Q22
int tetranacci(int n) {
	if(n == 0 || n == 1 || n == 2) {
		return 0;
	}
	if(n == 3) {
		return 1;
	}
	return tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
}

//Q23
int padovan(int n) {
	if(n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return padovan(n - 2) + padovan(n - 3);
}
//Q24
int pell(int n) {
	if(n == 0) {
		return 0;
	}
	if(n == 1) {
		return 1;
	}
	return 2 * pell(n - 1) + pell(n - 2);
}

//Q25
int catalan(int n) {
	if(n == 0) {
		return 1;
	}
	return 2 * (2 * n - 1) * catalan(n - 1) / (n + 1);
}