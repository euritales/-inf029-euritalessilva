#include <stdio.h>

int main(){
	
	int soma (int x, int y);
	
	int num1, num2, resultado;
	
	printf("Insira dois numeros a serem somados:\n");
	scanf("%d%d", &num1, &num2);
	
	resultado = soma(num1, num2);
	
	printf("Valor dos numeros somados:\n%d", resultado);
	
}

int soma(int x, int y){
	
	int resultado;
	resultado = x + y;
	
	return (resultado);
}