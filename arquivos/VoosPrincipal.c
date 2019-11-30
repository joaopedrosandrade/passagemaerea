#include "vooss.h"

/*A primeira vez que executar o programa deve selecionar
a opcao 99 e confirmar digitando 1. Toda vez que a opção 99 
for confirmada o código de trechos irá inicializar em ZERO e também,
o vetor de trechos começará em ZERO, ou seja, caso existam elementos 
gravados estes serão sobrescritos.
Isso irá garantir que o código de trechos seja automático em:
0, 1, 2, 3, ... */

int Ehnumero(char leitura[]){
int val=1,i;
for(i=0; i<strlen(leitura); i++)
 if(!isdigit(leitura[i]) )
   val=0;
return val;
}
////////////////////////////////////////
void menu(){
int op, confirma, cod_trecho;
char opcao[2];
trechos *meus_voos; /*  Ponteiro que será utilizado para formar o vetor */

do {
printf("\n -----------Menu de Opcoes para Voos----------- ");
printf("\n-----------99 - Inicializar Codigo de VOOS em ZERO ----------- ");
printf("\n-----------1 - Cadastrar Voos ----------- ");
printf("\n-----------2 - Listar Voos ----------- ");
printf("\n-----------3 - Sair ----------- ");

do{
 printf("\nDigite uma opcao valida: ");
 scanf("%s",&opcao);
}while(!Ehnumero(opcao));/* Garante a leitura de apenas inteiros */
op=atoi(opcao);

switch (op){
	case 1:
    cod_trecho = leitura_codigo_trecho(); /*Recupera o código de trechos gravado */
    if (cod_trecho!=-1){ /* Irá retornar -1 se ainda não foi inicializado o Código de Trechos em arquivo - opção 99 */
	   meus_voos=malloc((cod_trecho+1)*sizeof(trechos));/*Aloca os espaços no vetor necessários para obter/inserir os dados  */
	   if (cod_trecho>0)
	       leitura(meus_voos,cod_trecho+1); /*Recupera, caso existam, os registros já gravados*/
	   entrada_Dados(meus_voos,cod_trecho); /* Pede Leitura de Elementos */
	   gravar_codigo_trecho(cod_trecho+1); /*Grava o código do trecho a ser utilizado na próxima leitura */
	   gravar(meus_voos,cod_trecho+1);  /* Grava no arquivo físico os elementos lidos */
	 }
	  else
	   printf("\nEsta eh a primeira vez que voce executa o programa. Selecione a opcao 99!\n");
	break;
	case 2:
    cod_trecho=leitura_codigo_trecho(); /*Recupera o código de trechos gravados */
	if (cod_trecho!=-1){
	   meus_voos=malloc((cod_trecho+1)*sizeof(trechos));
	   if (cod_trecho>0)
	     leitura(meus_voos,cod_trecho+1); /*Recupera, caso existam, os registros já gravados*/
	   imprime (meus_voos,cod_trecho); /*Imprime os elementos do vetor */
	  }
	  else
	   printf("\nEsta eh a primeira vez que voce executa o programa. Selecione a opcao 99!\n");
	break;
	
	case 3:
	exit(0);
	break;
	
	case 99:	
	printf("\nESTA OPCAO IRA INICILIZAR O CODIGO DE VOOS EM ZERO, portanto, se houverem registros serao sobreescritos, CONFIRMA? (1 - Sim; 2 - Nao) ");
	scanf("%d",&confirma);
	if (confirma==1){
	  gravar_codigo_trecho(0);
	  printf("\nCodigo gravado em %d!",leitura_codigo_trecho());
	}
	else
	 printf("\nCodigo nao RESETADO!");
	break;
	
	default :
	  printf("OPCAO INVALIDA!");
 }
}while(op!=3);
free(meus_voos); /*Libera a memória RAM referente ao vetor alocado */
}
////////////////////////////////////////////////
int main (void){ 
menu();
}

