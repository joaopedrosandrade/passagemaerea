#include "vooss.h"

/*A primeira vez que executar o programa deve selecionar
a opcao 99 e confirmar digitando 1. Toda vez que a op��o 99 
for confirmada o c�digo de trechos ir� inicializar em ZERO e tamb�m,
o vetor de trechos come�ar� em ZERO, ou seja, caso existam elementos 
gravados estes ser�o sobrescritos.
Isso ir� garantir que o c�digo de trechos seja autom�tico em:
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
trechos *meus_voos; /*  Ponteiro que ser� utilizado para formar o vetor */

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
    cod_trecho = leitura_codigo_trecho(); /*Recupera o c�digo de trechos gravado */
    if (cod_trecho!=-1){ /* Ir� retornar -1 se ainda n�o foi inicializado o C�digo de Trechos em arquivo - op��o 99 */
	   meus_voos=malloc((cod_trecho+1)*sizeof(trechos));/*Aloca os espa�os no vetor necess�rios para obter/inserir os dados  */
	   if (cod_trecho>0)
	       leitura(meus_voos,cod_trecho+1); /*Recupera, caso existam, os registros j� gravados*/
	   entrada_Dados(meus_voos,cod_trecho); /* Pede Leitura de Elementos */
	   gravar_codigo_trecho(cod_trecho+1); /*Grava o c�digo do trecho a ser utilizado na pr�xima leitura */
	   gravar(meus_voos,cod_trecho+1);  /* Grava no arquivo f�sico os elementos lidos */
	 }
	  else
	   printf("\nEsta eh a primeira vez que voce executa o programa. Selecione a opcao 99!\n");
	break;
	case 2:
    cod_trecho=leitura_codigo_trecho(); /*Recupera o c�digo de trechos gravados */
	if (cod_trecho!=-1){
	   meus_voos=malloc((cod_trecho+1)*sizeof(trechos));
	   if (cod_trecho>0)
	     leitura(meus_voos,cod_trecho+1); /*Recupera, caso existam, os registros j� gravados*/
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
free(meus_voos); /*Libera a mem�ria RAM referente ao vetor alocado */
}
////////////////////////////////////////////////
int main (void){ 
menu();
}

