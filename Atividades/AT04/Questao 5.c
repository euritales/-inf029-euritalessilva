#include <stdio.h>

typedef struct{
		int num1;
		int num2;
		int num3;
		int num4;
	} numeros;

numeros ler4numeros();
int main(){

	numeros numero;
	numero = ler4numeros();
	
	printf("Valor numero:\n %d\n",numero.num1);
	printf("Valor numero:\n %d\n",numero.num2);
	printf("Valor numero:\n %d\n",numero.num3);
	printf("Valor numero:\n %d\n",numero.num4);
}


numeros ler4numeros(){
		
	numeros numero;
		
		printf("Insira os valores:\n");
		scanf("%d", &numero.num1);
		
		printf("Insira os valores:\n");
		scanf("%d", &numero.num2);
		
		printf("Insira os valores:\n");
		scanf("%d", &numero.num3);
		
		printf("Insira os valores:\n");
		scanf("%d", &numero.num4);
				
		return numero;
}
	
