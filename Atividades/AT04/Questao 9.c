#include <stdio.h>

    typedef struct{
        int dia;
        int mes;
        int ano; 
    } data;

    typedef struct{
    char nome[20];
    char cpf [12];
    data dataNascimento;
    char sexo;
    } cadastro;

    cadastro info;
    
    int verificador; 

int funcaoCadastrarCliente();
int valdNome(char nome);
int valdCpf(char cpf[]);
int valdNascimento(int data);
int valdSexo(validSexo);

int main(){
    
    int cadastrar = 0;
    cadastrar = funcaoCadastrarCliente();
    if(cadastrar == 0){
        printf("Cadastro Realizado!");
    }else{
        switch (cadastrar)
        {
        case -1:printf("ERRO NOME!");break;
        case -2:printf("ERRO CPF!");break;
        case -3:printf("ERRO DATA!");break;
        case -4:printf("ERRO SEXO!");break;        
        }
    }

}


int funcaoCadastrarCliente(){

    int nome, cpf, data, sexo; 

    printf("Seu nome:\n");
    fgets(info.nome, 20, stdin);

    nome = valdNome(info.nome);
    if(nome == -1){
        return -1;
    }

    printf("Seu cpf:\n");
    fgets(info.cpf, 12, stdin);

    cpf = valdCpf(info.cpf);
    if(cpf == -2){
        return -2;

    }

    printf("Sua data de nascimento -\nDia:\n");  
	scanf("%d", &info.dataNascimento.dia);
   
    data = valdNascimento(data);
    if(data == -3){
        return -3;
    }

    printf("Escolha seu sexo( M / F / O):\n", info.sexo);
    scanf("%s", &info.sexo);

    sexo = valdSexo(info.sexo);
    if(sexo == -4){
        return -4;
    }

    return verificador;
}

int valdNome(char nome){

    int lenght = strlen(nome) - 1;

    if(lenght <= 20){
        return 1;
    }else{
        return -1;
    }

}

int valdCpf(char cpf[]){
    
    int lenght = strlen(cpf) - 1;

    if(lenght == 11){
        return 2;
    }else{
        return -2;
    }
    
    
}
int valdNascimento(int data){
    
    int verificador = 0;

    info.dataNascimento.dia = data / 1000000;
    info.dataNascimento.mes = data % 1000000 / 10000;
    info.dataNascimento.ano = data % 1000000 % 10000;

    if(info.dataNascimento.dia < 1 || info.dataNascimento.dia > 31){
        verificador = 1;
    }
    if(info.dataNascimento.mes < 1 || info.dataNascimento.mes > 12){
        verificador = 1;
    }
    if(info.dataNascimento.ano < 1500 || info.dataNascimento.ano > 2021){
        verificador = 1;
    }
    if(verificador == 1){
        return 3;
    }else{
        return -3;
    }

    
}


int valdSexo(validSexo){

    if(validSexo == "m" || validSexo == "M"){
        return 4;
    }else{
        return -4;
    }
    
    if(validSexo == "f" || validSexo == "F"){
        return 4;
    }else{
        return -4;
    }
    
    if(validSexo == "o" || validSexo == "O"){
        return 4;
    }else{
        return -4;
    }
    
    
}
