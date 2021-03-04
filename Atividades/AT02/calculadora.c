#include <stdio.h>

int main (){
	
	int num1, num2, resultado;
	int i = 1;
	
	while (i != 0){

    printf("Insira o primeiro valor:\n");
    scanf("%d", &num1);
    
    printf("Insira o segundo valor:\n");
    scanf("%d", &num2);
		
		printf("CALCULAR:\n 0 - Sair\n 1 - Somar\n 2 - Subtrair\n 3 - Multiplicar\n 4 - Dividir\n");
		scanf("%d", &i);
		
		if(i == 1){
			resultado = num1 + num2;
			printf("Resultado:\n%d\n", resultado);
		}else if(i == 2){
			resultado = num1 - num2;
			printf("Resultado:\n%d\n", resultado);
		}else if(i == 3){
			resultado = num1 * num2;
			printf("Resultado:\n%d\n", resultado);
		}else if(i == 4){
			resultado = num1 /num2;
      			num1 %= num2;
			printf("Resultado:\n%d(%d)\n", resultado, num1);
		}else{
			printf("Opcao invalida!\n");
		}
		
		printf("\nSair?\n 0 - SIM / 1 - NAO \n");
		scanf("%d", &i);
	}
}
