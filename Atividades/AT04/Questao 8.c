#include <stdio.h>

typedef struct{
    char nome[20];
    char dataNascimento[20];
    char cpf[20];
    char sexo[20];
} cadastro;

cadastro funcaoCadastrarCliente();
int main(){

    cadastro info;
    info = funcaoCadastrarCliente();

    printf("Seu nome:\n%s\n", info.nome);
    printf("Seu cpf:\n%s\n", info.cpf);
    printf("Sua data de nascimento:\n%s\n", info.dataNascimento);
    printf("Seu sexo:\n%s\n", info.sexo);

}
cadastro funcaoCadastrarCliente(){

    cadastro info;
        
        printf("Insira o seu nome:\n");
        scanf("%s",&info.nome);

        printf("Insira sua data de nascimento:\n");
        scanf("%s", &info.dataNascimento);

        printf("Insira seu cpf:\n");
        scanf("%s", &info.cpf);

        printf("Informe seu sexo:\n");
        scanf("%s", &info.sexo);
    
        return info;

}