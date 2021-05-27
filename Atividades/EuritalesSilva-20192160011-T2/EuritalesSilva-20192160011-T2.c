#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EuritalesSilva-20192160011-T2.h"

typedef struct{
    int *listaAuxiliar;
    int *contador;
    int *tamanho; 
} ListaAux;

ListaAux vetorPrincipal[TAM];


void dobrar(int *x)
{

    *x = *x * 2;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int verificarAuxiliar(int posicao){
    int retorno;
    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal[posicao];

    if(ponteiroListaPrincipal->listaAuxiliar != NULL)
            return JA_TEM_ESTRUTURA_AUXILIAR;    
    else
        return SEM_ESTRUTURA_AUXILIAR;
}


int verificadorLista(int tamanho, ListaAux *ponteiro){

    if(ponteiro->listaAuxiliar == NULL){
        ponteiro->listaAuxiliar = (int *) malloc(tamanho * sizeof(int *));
        if(ponteiro->listaAuxiliar == NULL){
            return SEM_ESPACO_DE_MEMORIA;
        }
        else{
            ponteiro->contador = 0;
            ponteiro->tamanho = tamanho;
            return SUCESSO;
        }    
    }else{
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }
}

int criarEstruturaAuxiliar(int tamanho, int posicao)
{
    int verificador, retorno = 0;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal[posicao];

    if(ehPosicaoValida(posicao) == SUCESSO){
        if(tamanho > 0){
            verificador = verificadorLista(tamanho, ponteiroListaPrincipal);
        }else{
            return TAMANHO_INVALIDO;
        }
    }else{
        return POSICAO_INVALIDA;
    }

    if(verificador == SUCESSO){
        retorno = SUCESSO;
    }else if(verificador == JA_TEM_ESTRUTURA_AUXILIAR){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }else{ 
        retorno = SEM_ESPACO_DE_MEMORIA;
    }

    return retorno;
}
int getQuantidadeElementosAuxiliar(int posicao){

   int verificador, retorno = 0;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal[posicao];

    if(ehPosicaoValida(posicao+1) == SUCESSO)
        if(verificarAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR)
            if(ponteiroListaPrincipal->contador > 0){
                retorno = ponteiroListaPrincipal->contador;
            }
            else{
                retorno = ESTRUTURA_AUXILIAR_VAZIA;
            }
        else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    else{
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
}


int verificarTamanhoAuxiliar(int posicao){
    int tamanho, tamanhoEstrutura, contador;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal[posicao];

    contador = getQuantidadeElementosAuxiliar(posicao);
    
    tamanho = ponteiroListaPrincipal->tamanho;
    tamanhoEstrutura = tamanho - contador;

    if(tamanhoEstrutura>0)
        return SUCESSO;
    else
        return SEM_ESPACO;
}


/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    int i = 1;
    int ponteiroContador, aux;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal[posicao];

    
    posicao_invalida = ehPosicaoValida(posicao);
    existeEstruturaAuxiliar = verificarAuxiliar(posicao);
    temEspaco = verificarTamanhoAuxiliar(posicao);
    
    aux = ponteiroContador + i;

    if (posicao_invalida){
        retorno = POSICAO_INVALIDA;
    } else {
        if (existeEstruturaAuxiliar == JA_TEM_ESTRUTURA_AUXILIAR){
            if (temEspaco == SUCESSO){
                ponteiroListaPrincipal->listaAuxiliar[ponteiroContador] = valor;
                ponteiroListaPrincipal->contador = aux;
                retorno = SUCESSO;
            }else{
                retorno = SEM_ESPACO;
            }
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

void ordenar(int lista[], int n){ 
    int i, j, aux;

    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++){
            if(lista[i] > lista[j]){
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal[posicao];

    if(ehPosicaoValida(posicao) == SUCESSO){
        if(verificarEstruturaAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){
            ponteiroListaPrincipal[posicao].contador--;
            retorno = SUCESSO;
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
        retorno = POSICAO_INVALIDA;
    }
    return retorno;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;
    int i, aux = 0;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal[posicao];

    for(i = 0; i< TAM; i++){
        if(ponteiroListaPrincipal[posicao].listaAuxiliar[i] == valor){
            ponteiroListaPrincipal[posicao].contador--;
            aux ++;
        }
    }if(aux == 0){
        retorno = NUMERO_INEXISTENTE;
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else{
        retorno = SUCESSO;
    }

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int retorno = 0;
    int i = 0;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal;

    int tamEstruturaAuxiliar = ponteiroListaPrincipal[posicao].contador;

    if(ehPosicaoValida(posicao) == SUCESSO){
        if(verificarAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){
            for(i=0;i<tamEstruturaAuxiliar;i++){
                vetorAux[i] = ponteiroListaPrincipal[posicao].listaAuxiliar[i];
            }
            retorno = SUCESSO;
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }else
        retorno = POSICAO_INVALIDA;

    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) //reparar
{   
    int retorno = 0;
    int i = 0;
    int tamanho;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal;

    if(ehPosicaoValida(posicao) == SUCESSO){
        if(verificarAuxiliar(posicao) == JA_TEM_ESTRUTURA_AUXILIAR){
            tamanho = sizeof(vetorAux);

            for(i = 0; i < tamanho; i++){
                vetorAux[i] = ponteiroListaPrincipal[posicao].listaAuxiliar[i];
            }
            selectionSort(vetorAux, tamanho);
            retorno = SUCESSO;
        }else{
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }else{
        retorno = SEM_ESTRUTURA_AUXILIAR;

    }
    return retorno;
}


/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int retorno = 0;
    int i,j,k, aux;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal;

    for(i = 0; i < TAM; i++){
        if(ponteiroListaPrincipal[i].listaAuxiliar != NULL){
            aux = ponteiroListaPrincipal[i].contador;
            for(j = 0; j < aux; j++){
                vetorAux[j] = ponteiroListaPrincipal[i].listaAuxiliar[j];
            }
            retorno = SUCESSO;
        }
    }
    return retorno;
    
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int contadorAux(){ 
    int i,j;
    int contador = 0;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal;

    for (i = 0; i < TAM; i++){

        if (ponteiroListaPrincipal[i].listaAuxiliar != NULL){
            contador = ponteiroListaPrincipal[i].contador;
        }
    }
    return contador;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{   int retorno = 0;
    int aux;

    getDadosDeTodasEstruturasAuxiliares(vetorAux);
    aux = contadorAux();

    ordenar(vetorAux, aux);
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;
    int tamanhoAtual = 0;

    ListaAux *ponteiroListaPrincipal = NULL;
    ponteiroListaPrincipal = &vetorPrincipal;

    tamanhoAtual = ponteiroListaPrincipal[posicao].tamanho;

    if(ehPosicaoValida(posicao) == SUCESSO){
        if(ponteiroListaPrincipal[posicao].listaAuxiliar != NULL){
            novoTamanho += tamanhoAtual;
            ponteiroListaPrincipal[posicao].tamanho = novoTamanho;
            return SUCESSO;
        }else{
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }else{
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/




/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
    int i = 0;
    ListaAux vetor[TAM];
    for( i = 0; i < TAM;i++){
        vetor[i].listaAuxiliar = NULL;
        vetor[i].tamanho = 0;
        vetor[i].contador = 0;
    }

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
    int i;
    for(i = 0; i < TAM; i += 1)
        free(vetorPrincipal[i].listaAuxiliar);
}

