#include <stdio.h>

int main(){
	
	int numero;
	int resultado;
  
	printf("Insira um numero para o seu fatorial:\n",numero);
	scanf("%d", &numero);
	
	if(resultado == -1){
		printf("%d nao e uma opcao valida", numero);
	}else{
		resultado = fatorial(numero);
		printf("Fatorial e: %d", resultado);
	}
  
	return 0;
}


int fatorial(int num)
{
	int resultado;
	
	if ( num == 1 || num == 0 ){
		return (1);
	}else if(num < 0){
		resultado = -1;
		return resultado;
	}
	else{
		resultado = num * fatorial(num - 1);
	}
	
	return (resultado);
}

