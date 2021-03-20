#include <stdio.h>

typedef struct{
	char digito1[2];
	char digito2[2];
	char digito3[2];
} letras;

letras funcaoletra();

int main(){
	
	letras letra;
	letra = funcaoletra();
	
	printf("Palavra armazenada:%s\n", letra.digito1);
	printf("Palavra armazenada:%s\n", letra.digito2);
	printf("Palavra armazenada:%s\n", letra.digito3);
}

letras funcaoletra(){
	
	letras letra;
		
		printf("Insira uma letra:\n");
		scanf("%s", &letra.digito1);
		
		printf("Insira uma letra:\n");
		scanf("%s", &letra.digito2);
		
		printf("Insira uma letra:\n");
		scanf("%s", &letra.digito3);
		
		return letra;

}

