#include <stdio.h>

int main(){
	
	int subtracao(int x, int y, int z);
	
	int num1, num2, num3, resultado;
	
	printf("Insira os tres numeros a serem subtraidos:\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	
	resultado = subtracao(num1, num2, num3);
	
	printf("Valor dos numeros subtraidos:\n%d", resultado);
	
	
}

int subtracao(int x, int y, int z){
	
	int resultado;
	resultado = x - y - z;
	
	return (resultado);
}
