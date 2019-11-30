/*Este programa, em C, tem o prop�sito de simular a verfica��o de poltronas,
tendo um vetor poltronas com 86 posi��es.
Nas posi��es de Poltronas j� vendidas � aplicado o valor 1 e as livres
para venda mantem o valor 0 (ZERO).
Quanto a impress�o na tela, as poltronas vendidas aparecem em vermelho e as livres em azul*/

#include <stdio.h>
#include <stdlib.h>
#include "cor.h" /*Usa o cabe�alho cor.h que possui a fun��o cor
para a altera��o de escritas em cores, sendo:
cor(1) - altera a escrita para branco/padr�o;
cor(2) - altera a escrita para verde;
cor(3) - altera a escrita para azul;
cor(4) - altera a escrita para vermelho*/
#define poltronas_vendas 86

/////////////////////////////////////////
void simula_poltronas (int poltronas[]){
/*Foi atribuido 1 em algumas posi��es do vetor simulando poltronas vendidas
 e deixando 0 (ZERO garantido pelo calloc) para simular poltronas livres para venda */
    poltronas[2]=1;     poltronas[5]=1;
    poltronas[9]=1;     poltronas[14]=1;
    poltronas[16]=1;    poltronas[18]=1;
    poltronas[20]=1;    poltronas[21]=1;
    poltronas[38]=1;	poltronas[45]=1;
	poltronas[60]=1;    poltronas[62]=1;
    poltronas[65]=1;    poltronas[69]=1;
	poltronas[74]=1;    poltronas[76]=1;
    poltronas[77]=1;    poltronas[84]=1;
    poltronas[85]=1;	poltronas[86]=1;
}
//////////////////////////////////////////////
int main(void) {

	int *poltronas, i;
    poltronas = calloc(poltronas_vendas, sizeof(int*)); /*Usado calloc para garantir zeros em todas as posi��es do vetor poltronas */
    simula_poltronas(poltronas);  /*Foi colocado o valor 1 em algumas posi��es do vetor para simular poltronas vendidas */
    printf("\n\n");
    for(i=1;i<poltronas_vendas-1;i++){

    	if (poltronas[i]==1){ /*Considera poltronas j� vendidas */
    		cor(4);/*Imprime na tela as letras em vermelho*/
    		printf("[%d] ",i);
    		cor(1); /*Retorna para a cor branca*/
		}
		else if (poltronas[i]==0){ /*Considera poltronas livres para serem vendidas */
		   cor(3);/*Imprime na tela as letras em azul*/
		   printf("[%d] ",i);
		   cor(1); /*Retorna para a cor branca	*/
		}

		if (i%14==0) /*filas de 14 poltronas sequenciais*/
		 printf("\n");

		if (i%42==0) /*Depois de formar um primeiro bloco de grupos de tr�s poltronas (3X14=42) pula-se linhas para gerar um segundo bloco */
		 printf("\n\n\n");

	}
	free(poltronas);

}
