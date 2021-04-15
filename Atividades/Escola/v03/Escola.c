#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


typedef struct{
	int matricula;
	char nome[30];
	char cpf [12];
	char dataNascimento[12];
	char sexo[1];
	int status;
} Aluno;

typedef struct{
	int matricula;
	char nome[30];
	char cpf [12];
	char dataNascimento[12];
	char sexo[1];
	int status;
} Professor;

typedef struct{
	char nome[20];
	int codigo;
	int semestre;
	char professor[30];
	int status;
} Disciplina;	

void funcaocadastrarAluno(Aluno alunos[], int *totalAlunos);
void funcaoListarAlunos(Aluno alunos[], int totalAlunos);
void funcaoRemoverAlunos(Aluno alunos[], int totalAlunos);
void funcaoEditarAlunos(Aluno alunos [], int totalAlunos);
void funcaocadastrarProfessor(Professor professores[], int *totalProfessores);
void funcaoListarProfessores(Professor professores[], int totalProfessores);
void funcaoRemoverProfessores(Professor professores[], int totalProfessores);
void funcaoDisciplinas (Disciplina disciplinas[], Professor professores[], Aluno alunos[]);


int validaNome(char *nome);
int validaCpf(char *cpf);
int validarData(char *data);
int validarSexo(char *sexo);


int main() {
	
	int i = -1;
	Disciplina disciplinas[MAX];
	Aluno alunos[MAX];
	Professor professores[MAX];
	int qtd_alunos = 0;
	int qtd_professores = 0;
	int verificador = -1;
	
	while( i != 0 ){
		
		printf("\n\nMenu Principal:\n-----ALUNOS-----\n 1 - Cadastrar Alunos\n 2 - Editar Aluno\n 3 - Excluir Aluno\n \n-----PROFESSORES-----\n 4 - Cadastrar professor \n 5 - Editar professor \n 6 - Excluir professor \n-----DISCIPLINAS-----\n\n 7 - Disciplinas  \n\n-----RELATORIOS----- \n8 - Listas \n  0 - para sair\n");
		scanf("%d", &i);
		switch (i)
        {
	        case 1:
	        	funcaocadastrarAluno(alunos, &qtd_alunos);
			break;
	        case 2:
	        	funcaoEditarAlunos(alunos, qtd_alunos);
			break;
	        case 3:
	           	funcaoRemoverAlunos(alunos, qtd_alunos);
			break;        
	        case 4:
	           	funcaocadastrarProfessor(professores, &qtd_professores);
			break;        
	        case 5:
	           funcaoEditarProfessores(professores, qtd_professores);
			break;        
	        case 6:
				funcaoRemoverProfessores(professores, qtd_professores);
			break;
			case 7:
				printf("\n1 - Cadastrar Disciplinas:\n");
				scanf("%d", &verificador);
				
				if(verificador == 1){
					funcaoDisciplinas (disciplinas, professores, alunos);
					verificador = -1;
				}
				
			break;
			case 8:
			printf("\n1 - Listar Alunos \n2 - Listar professores \n0 - voltar\n");
			scanf("%d", &verificador);
			if(verificador == 1){
				funcaoListarAlunos(alunos, qtd_alunos);
				verificador = -1;
			}else if(verificador == 2){
				funcaoListarProfessores(professores, qtd_professores);
				verificador = -1;
			}
			break;     		
        }		
	}
	
	return 0;
}

void funcaoDisciplinas (Disciplina disciplinas[], Professor professores[], Aluno alunos[]){
	
	Aluno descricaoA;
	Professor descricaoP;
	Disciplina descricaoD;
	int vald = 1;	
	char prof[30];
	int alu = -1;
	int i = 0;
	
	printf("\nDigite o nome da Materia:\n");
	fflush(stdin);
	scanf("%[^\n]",descricaoD.nome);
		
	printf("\nDigite o semestre Materia:\n");
	scanf("%d", descricaoD.semestre);
	
	printf("\nDigite o codigo do professor:\n");
	fflush(stdin);
	scanf("%[^\n]", prof);;

	if(prof == descricaoP.nome){
		fflush(stdin);
		scanf("%[^\n]", descricaoD.professor);

	}
}
	
	
void funcaoEditarAlunos(Aluno alunos [], int totalAlunos){
	
	Aluno descricao;
	int vald = 1;
	int num_matricula;
	int verificador = 1;
	int i;
	
	printf("\nInsira o numero do aluno voce quer editar:\n");
	scanf("%d", &num_matricula);
	
	for(i = 0; i < totalAlunos; i++){		
		
		if(alunos[i].status == 1 && alunos[i].matricula == num_matricula ){
			
			while( verificador != 0 ){
				
				printf("\n\nMenu Edicao Aluno:\n 1 - Editar nome\n 2 - Editar CPF\n 3 - Editar Data\n 4 -Editar Sexo\n 0 -Voltar Menu Principal\n");
				scanf("%d", &verificador);
				
				switch (verificador)
		        {
		        	case 0:
						break; 
		        	case 1:
		        		printf("Digite o novo nome do aluno:\n");
						fflush(stdin);
						scanf("%[^\n]", descricao.nome);
					
						vald = validaNome(descricao.nome);
						
						if(vald == 0){
							printf("nome invalido!");
							break;
						}
						strcpy(alunos[i].nome, descricao.nome);
						
						printf("mudei...");
		        		break;
			        case 2:
			        	printf("Digite o novo CPF do aluno:\n");
						scanf("%s", descricao.cpf);
						vald = validaCpf(descricao.cpf);
						
						if(vald == 0){
							printf("CPF invalido!");
							break;
						}
						strcpy(alunos[i].cpf, descricao.cpf);

						printf("mudei...");
						break;		
			        case 3:
			        	printf("Digite o novo CPF do aluno:\n");
						scanf("%s", descricao.dataNascimento);
						vald = validarData(descricao.dataNascimento);
						
						if(vald == 0){
							printf("Data invalida!");
							break;
						}
						strcpy(alunos[i].dataNascimento, descricao.dataNascimento);

						printf("mudei...");
						break;	
			        case 4:
			        	printf("Digite o novo sexo do aluno:\n");
						scanf("%s", descricao.sexo);
						vald = validarSexo(descricao.sexo);
						
						if(vald == 0){
							printf("Sexo invalido!");
							break;
						}
						strcpy(alunos[i].sexo, descricao.sexo);
						printf("mudei...");
						break;	       
		        }		
			}	
				
		}
	}

			
}

void funcaoEditarProfessores(Professor professores [], int totalProfessores){
	
	Professor descricao;
	int vald = 1;
	int num_matricula;
	int verificador = 1;
	int i;
	
	printf("\nInsira o numero do professor para ser editado:\n");
	scanf("%d", &num_matricula);
	
	for(i = 0; i < totalProfessores; i++){		
		
		if(professores[i].status == 1 && professores[i].matricula == num_matricula ){
			
			while( verificador != 0 ){
				
				printf("\n\n-----Menu Edicao Aluno-----\n 1 - Editar nome\n 2 - Editar CPF\n 3 - Editar Data\n 4 -Editar Sexo\n 0 -Voltar Menu Principal\n");
				scanf("%d", &verificador);
				
				switch (verificador)
		        {
		        	case 0:
						break; 
		        	case 1:
		        		printf("Digite o novo nome do professor:\n");
						fflush(stdin);
						scanf("%[^\n]", descricao.nome);
					
						vald = validaNome(descricao.nome);
						
						if(vald == 0){
							printf("nome invalido!");
							break;
						}
						strcpy(professores[i].nome, descricao.nome);
						
						printf("mudei...");
		        		break;
			        case 2:
			        	printf("Digite o novo CPF do professor:\n");
						scanf("%s", descricao.cpf);
						vald = validaCpf(descricao.cpf);
						
						if(vald == 0){
							printf("CPF invalido!");
							break;
						}
						strcpy(professores[i].cpf, descricao.cpf);

						printf("mudei...");
						break;		
			        case 3:
			        	printf("Digite o novo CPF do professor:\n");
						scanf("%s", descricao.dataNascimento);
						vald = validarData(descricao.dataNascimento);
						
						if(vald == 0){
							printf("Data invalida!");
							break;
						}
						strcpy(professores[i].dataNascimento, descricao.dataNascimento);

						printf("mudei...");
						break;	
			        case 4:
			        	printf("Digite o novo sexo do professor:\n");
						scanf("%s", descricao.sexo);
						vald = validarSexo(descricao.sexo);
						
						if(vald == 0){
							printf("Sexo invalido!");
							break;
						}
						strcpy(professores[i].sexo, descricao.sexo);
						printf("mudei...");
						break;	       
		        }		
			}	
				
		}
	}

			
}

void funcaoListarAlunos(Aluno alunos[], int totalAlunos){
	
	int i;

	for(i = 0; i < totalAlunos; i++){

		if(alunos[i].status == 1){
			printf("\n\n\n|Nome:\n%s\n|Numero Matricula:\n%d\n|CPF:\n%s\n|Sexo:\n%s\n|Data Nascimento:\n%s\n", alunos[i].nome, alunos[i].matricula, alunos[i].cpf, alunos[i].sexo, alunos[i].dataNascimento);
		}
		
	}
	
}

void funcaoListarProfessores(Professor professores[], int totalProfessores){
	
	int i;

	for(i = 0; i < totalProfessores; i++){

		if(professores[i].status == 1){
			printf("\n\n\n|Nome:\n%s\n|Numero Matricula:\n%d\n|CPF:\n%s\n|Sexo:\n%s\n|Data Nascimento:\n%s\n", professores[i].nome, professores[i].matricula, professores[i].cpf, professores[i].sexo, professores[i].dataNascimento);
		}
		
	}
	
}

void funcaoRemoverAlunos(Aluno alunos[], int totalAlunos){
	
	
	int i;
	int num_matricula;
	
	printf("\nInsira o Aluno a ser deletado(Informe o numero de Matricula):\n");
	scanf("%d", &num_matricula);
	for(i = 0; i < totalAlunos; i++){	
		
		if(alunos[i].status == 1 && alunos[i].matricula == num_matricula ){
			alunos[i].status = 0;
		}	
	}	
	printf("Apaguei...");
}

void funcaoRemoverProfessores(Professor professores[], int totalProfessores){
	
	
	int i;
	int num_matricula;
	
	printf("\nInsira o Professor a ser deletado(Informe o numero de Matricula):\n");
	scanf("%d", &num_matricula);
	for(i = 0; i < totalProfessores; i++){	
		
		if(professores[i].status == 1 && professores[i].matricula == num_matricula ){
			professores[i].status = 0;
		}	
	}	
	printf("Apaguei...");
}

void funcaocadastrarAluno(Aluno alunos[], int *totalAlunos){	

	
	Aluno descricao;
	int vald = 1;
	int cont = *totalAlunos;
	
	
	
	printf("Digite o nome do aluno:\n");
	fflush(stdin);
	scanf("%[^\n]", descricao.nome);
	vald = validaNome(descricao.nome);
	
	if(vald == 0){
		printf("nome invalido!");
		return;
	}
	
	printf("Digite o CPF do aluno:\n");
	scanf("%s", descricao.cpf);
	vald = validaCpf(descricao.cpf);
	
	if(vald == 0){
		printf("CPF invalido!");
	
		return;
	}
	
	printf("Digite a data de nascimento do aluno:\n");
	scanf("%s", descricao.dataNascimento);
	vald = validarData(descricao.dataNascimento);
	
	if(vald == 0){
		printf("Data invalida!");
	
		return;
	}
	
	printf("Digite o sexo do aluno:\n");
	scanf("%s", descricao.sexo);
	vald = validarSexo(descricao.sexo);
	
	if(vald == 0){
		printf("Sexo invalido!");
	
		return;
	}


	*totalAlunos += 1;
	
	alunos[cont].matricula = cont + 1; 
	strcpy(alunos[cont].nome, descricao.nome);
	strcpy(alunos[cont].cpf, descricao.cpf);
	strcpy(alunos[cont].dataNascimento, descricao.dataNascimento);
	strcpy(alunos[cont].sexo, descricao.sexo);
	alunos[cont].status = 1;
	
	printf("\nAluno Cadastrado\n");
}

void funcaocadastrarProfessor(Professor professores[], int *totalProfessores){
	
	Professor descricao;
	int vald = 1;
	int cont = *totalProfessores;
	
	
	
	printf("Digite o nome do Professor:\n");
	fflush(stdin);
	scanf("%[^\n]", descricao.nome);
	vald = validaNome(descricao.nome);
	
	if(vald == 0){
		printf("nome invalido!");
		return;
	}
	
	printf("Digite o CPF do professor:\n");
	scanf("%s", descricao.cpf);
	vald = validaCpf(descricao.cpf);
	
	if(vald == 0){
		printf("CPF invalido!");
	
		return;
	}
	
	printf("Digite a data de nascimento do professor:\n");
	scanf("%s", descricao.dataNascimento);
	vald = validarData(descricao.dataNascimento);
	
	if(vald == 0){
		printf("Data invalida!");
	
		return;
	}
	
	printf("Digite o sexo do professor:\n");
	scanf("%s", descricao.sexo);
	vald = validarSexo(descricao.sexo);
	
	if(vald == 0){
		printf("Sexo invalido!");
	
		return;
	}
	
		*totalProfessores += 1;
	
	professores[cont].matricula = cont + 1; 
	strcpy(professores[cont].nome, descricao.nome);
	strcpy(professores[cont].cpf, descricao.cpf);
	strcpy(professores[cont].dataNascimento, descricao.dataNascimento);
	strcpy(professores[cont].sexo, descricao.sexo);
	professores[cont].status = 1;
	
	printf("\n Professor Cadastrado\n");

}

int validaNome(char *nome){
    int contador=0;

    while (nome[contador] != '\0') {
        
        contador++;
        
    }

    if(contador <= 30){

        return 1;
    }else{

          return 0;

    }

}

int validaCpf(char *cpf){

    int cpfInt[11],i=0,somaDigi1,restoDigi1,somaDigi2,restoDigi2;
    int validador=0;
    char aux[1];
    
    for(i=0;i<11;i++){

        aux[0] = cpf[i];
        cpfInt[i] = atoi(aux);

    }


    somaDigi1 = (cpfInt[0] * 10) + (cpfInt[1] * 9) + (cpfInt[2] * 8) + (cpfInt[3] * 7) + (cpfInt[4] * 6) + (cpfInt[5] * 5) + (cpfInt[6] * 4) + (cpfInt[7] * 3) + (cpfInt[8] * 2);
    restoDigi1 = somaDigi1 % 11;

    if( (11 - restoDigi1) == 1 ){

        if(cpfInt[9] == 1){
            validador++;
        }

    }else if((11 - restoDigi1) == 2 ){

        if(cpfInt[9] == 2){
            validador++;
        }

    }else if((11 - restoDigi1) == 3 ){

        if(cpfInt[9] == 3){
            validador++;
        }

    }else if((11 - restoDigi1) == 4 ){

        if(cpfInt[9] == 4){
            validador++;
        }

    }else if((11 - restoDigi1) == 5 ){

        if(cpfInt[9] == 5){
            validador++;
        }

    }else if((11 - restoDigi1) == 6 ){

        if(cpfInt[9] == 6){
            validador++;
        }

    }else if((11 - restoDigi1) == 7 ){

        if(cpfInt[9] == 7){
            validador++;
        }

    }else if((11 - restoDigi1) == 8 ){

        if(cpfInt[9] == 8){
            validador++;
        }

    }else if((11 - restoDigi1) == 9 ){

        if(cpfInt[9] == 9){
            validador++;
        }

    }else if((11 - restoDigi1) >= 10 ){

        if(cpfInt[9] == 0){
            validador++;
        }

    }

    somaDigi2 = (cpfInt[0] * 11) + (cpfInt[1] * 10) + (cpfInt[2] * 9) + (cpfInt[3] * 8) + (cpfInt[4] * 7) + (cpfInt[5] * 6) + (cpfInt[6] * 5) + (cpfInt[7] * 4) + (cpfInt[8] * 3) + (cpfInt[9] * 2);
    restoDigi2 = somaDigi2 % 11;

    if( (11 - restoDigi2) == 1 ){

        if(cpfInt[10] == 1){
            validador++;
        }

    }else if((11 - restoDigi2) == 2 ){

        if(cpfInt[10] == 2){
            validador++;
        }

    }else if((11 - restoDigi2) == 3 ){

        if(cpfInt[10] == 3){
            validador++;
        }

    }else if((11 - restoDigi2) == 4 ){

        if(cpfInt[10] == 4){
            validador++;
        }

    }else if((11 - restoDigi2) == 5 ){

        if(cpfInt[10] == 5){
            validador++;
        }

    }else if((11 - restoDigi2) == 6 ){

        if(cpfInt[10] == 6){
            validador++;
        }

    }else if((11 - restoDigi2) == 7 ){

        if(cpfInt[10] == 7){
            validador++;
        }

    }else if((11 - restoDigi2) == 8 ){

        if(cpfInt[10] == 8){
            validador++;
        }

    }else if((11 - restoDigi2) == 9 ){

        if(cpfInt[10] == 9){
            validador++;
        }

    }else if((11 - restoDigi2) >= 10 ){

        if(cpfInt[10] == 0){
            validador++;
        }

    }

    if(validador == 2){

        return 1;
    }else{

        return 0;
    }
}

int validarData(char *data){
	char dia[2],mes[3];
    char ano[5];
	int diaInt=0,mesInt=0,anoInt=0;
	int contador=6,validador=0,contador2=0;

    while (data[contador2] != '\0') {
        
        contador2++;
        
    }

    if(contador2 < 10 ){

        return 0;
    }
	
	if(data[0] != '0'){
		
		dia[0] = data[0];
		dia[1] = data[1];
		
		diaInt = atoi(dia);
		
	}else{
		
		dia[0] = data[1];
		diaInt = atoi(dia);	
	}
	
	if(data[3] != '0'){

		mes[0] = data[3];
		mes[1] = data[4];

		mesInt = atoi(mes);
	}else{
		
		mes[0] = data[4];
		mesInt = atoi(mes);
	}
	
	while (data[contador] != '\0') {
        
        contador++;
        
    }
    
    if(contador == 8){
    	
        return 0;
    	ano[0] = data[6];
    	ano[1] = data[7];
    	
    	anoInt = atoi(ano);
    	
	}else if(contador == 10){
		
		ano[0] = data[6];
		ano[1] = data[7];
		ano[2] = data[8];
		ano[3] = data[9];
		
		anoInt = atoi(ano);
	}

	if(diaInt > 0 && diaInt <= 31){
	
		validador++;
		
	}
	
	if(mesInt > 0 && mesInt <= 12){
	
		validador++;
	}

    if(mesInt == 2 && diaInt > 28){

        validador++;
    }
	
	if(anoInt > 0 && anoInt <= 2021){

		validador++;
	}

	if(validador == 3){
		
		return 1;
		
	}else {

		return 0;
	
	}
	
}

int validarSexo(char *sexo){
	int contador = 0;
	 while (sexo[contador] != '\0') {
        
        contador++;
        
    }
    
    if(contador > 1){
    	
    	return 0;
	}
	
    if(sexo[0] == 'm' || sexo[0] == 'M'){

        return 1;
        
    }else if(sexo[0] == 'f' || sexo[0] == 'F'){
    	
    	return 1;
    	
	}else if(sexo[0] == 'o' || sexo[0] == 'O'){
		
		return 1;
	}

    return 0;
}

