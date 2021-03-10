#include <stdio.h>
#include <stdlib.h>

#include "Promocao.h"

/*O posto est� vendendo combust�veis com a seguinte tabela de descontos:
�lcool: Acima de 25 litros, desconto de 4% por litro
Gasolina:Acima de 25 litros, desconto de 5% por litro. 
Pre�o do litro da gasolina � R$ 5,70 e o pre�o do litro
do �lcool � R$ 3,90*/

int main(int argc, char *argv[]) {
	
	int combustivel;
	float litros, valor;
	
	
	printf("0 - ALCOOL (R$3,90) \n1 - GASOLINA (R$5,70) \n");
	scanf("%d", &combustivel);
	
	printf("INSIRA A QUANTIDADE DE LITROS(compras acima de 25L sujeitas a promocao):\n");
	scanf("%f", &litros);
	
	if(combustivel == 1){
		
		valor = promocao_gasolina(litros);
		printf("Valor:\n%.2f", valor);		
	} else if(combustivel == 0){
		valor = promocao_alcool(litros);
		printf("Valor:\n%.2f", valor);
	}
	
	return 0;
}

