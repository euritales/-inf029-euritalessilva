#include <stdio.h>

int main(){
int ler3numeros();

	int resultado[3];
	int i;
	
	for(i = 0; i < 3; i++){
		resultado[i] = ler3numeros();
	}
	for(i = 0; i < 3; i++){
		printf("\nResultado numero %d :\n%d",i+1, resultado[i]);
	}
}


int ler3numeros(){
	
	int num[3];
	int i;
	
	for(i = 0;i < 3; i++){
		
		printf("Insira os valores:\n");
		scanf("%d", &num[i]);
		
		return num[i];
	}
	
}
