#include <stdio.h>

typedef struct{
	char nome1[20];
	char nome2[20];
	char nome3[20];
} palavras;

palavras funcaopalavras();

int main(){
	
	palavras palavra;
	palavra = funcaopalavras();
	
	printf("Palavra armazenada:%s\n", palavra.nome1);
	printf("Palavra armazenada:%s\n", palavra.nome2);
	printf("Palavra armazenada:%s\n", palavra.nome3);
}

palavras funcaopalavras(){
	
	palavras palavra;
		
		printf("Insira uma palavra:\n");
		scanf("%s", &palavra.nome1);
		
		printf("Insira uma palavra:\n");
		scanf("%s", &palavra.nome2);
		
		printf("Insira uma palavra:\n");
		scanf("%s", &palavra.nome3);
		
		return palavra;

}

