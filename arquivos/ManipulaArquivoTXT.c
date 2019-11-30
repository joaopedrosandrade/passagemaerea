/*Este programa, em C, realiza a leitura de N dados de funcion�rios, 
os elementos s�o armazenados em um vetor din�mico e 
posteriormente ocorre a grava��o em um arquivo f�sico chamado 
emp.txt. Trata-se de um arquivo texto sequencial.
Em seguida, ocorre a recupera��o dos dados salvos para o vetor 
dinamicamente alocado.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
 char nome[40];
 int matricula;
 char profissao[30];
 int tempo_servico;
}funcionario;

//PROT�TIPOS
void gravar (funcionario vetor[],int tamanho);
void leitura (funcionario vetor[],int tamanho);
void entrada(funcionario vetor[],int tamanho);
void imprime_Vetor(funcionario vetor[],int tamanho);

//IMPLEMENTA��O DAS FUN��ES

void gravar (funcionario vetor[],int tamanho){	
int i;
FILE *arq; /*Cria um ponteiro apontando para um endere�o 
			de mem�ria RAM que ir� trabalhar com dados 
			do tipo FILE*/
arq = fopen ("emp.txt", "w+"); /*Cria o arquivo pelo 
								fisicamente emp.txt 
								pelo comando w+*/
if (arq != NULL) {/* verifica se conseguiu criar o arquivo*/
 for(i=0;i<tamanho;i++) 
  fprintf(arq,"%s%s\n %d\n %s%s\n %d\n",vetor[i].nome,",",vetor[i].matricula,vetor[i].profissao,",",vetor[i].tempo_servico); /*grava fisicamente os dados 
   
 																																			no arquivo previamente criado*/
   /* Foi adicionada uma v�rgula no final de cada campo string.
   Isso ser� �til no momento da leitura do arquivo, em particular,
   para os campos de nome e profiss�o que s�o strings e podem conter espa�os */ 																																			
}
else
 printf("Arquivo nao criado <<<Error<<");
fclose (arq); 

}
////////////////////////
void leitura (funcionario vetor[],int tamanho){
int i;
FILE *arq; /*Cria um ponteiro apontandp para um endere�o 
			de mem�ria RAM que ir� trabalhar com dados 
			do tipo FILE*/
arq = fopen ("emp.txt", "r+"); /* Acesssa o arquivo f�sico 
									pela fun��o fopen e o 
									par�metro "r+"  */
if (arq != NULL){

 for(i=0;i<tamanho;i++)
  	fscanf(arq, "%[^,], %d %[^,], %d",&vetor[i].nome,&vetor[i].matricula,&vetor[i].profissao,&vetor[i].tempo_servico);

     /* O comando %[^,], significa ler tudo at� encontrar uma v�rgula. 
	 Esta v�rgula foi adicionada, no final de cada elemento
	 no arquivo no momento da grava��o. 
	 Funciona como um marcador. Isso foi necess�rio para facilitar 
	 a leitura de nomes com espa�os em branco dentro do arquivo*/
	 
	 //char conteudo_arquivo[10];
	 //fscanf(arq,"%[^][^]s",&conteudo_arquivo);
	 //printf("%s",conteudo_arquivo);
	 
	 /*OBS: O comando fscanf(arq,"%[^][^]s",&strings); isoladamente, sem o for e sem o primeiro fscanf
	 imprime todo o arquivo, isso pode ser �til para imprimir o cart�o de embarque!*/
	
}
else
  printf("\nNao foi possivel ler o arquivo!");
fclose (arq); /*fecha o arquivo*/

}
///////////////////////////////////////
void entrada(funcionario *vetor,int tamanho){
 int i;
for(i=0;i<tamanho;++i) {
  fflush(stdin);//__fpurge(stdin);
  printf("\nNome da posicao %d ",(i+1));
  scanf("%[^\n]s",vetor[i].nome);
  printf("\nMatricula da posicao %d ",(i+1));
  scanf("%d",&vetor[i].matricula); 
  fflush(stdin);//__fpurge(stdin);
  printf("\nProfissao da posicao %d ",(i+1));
  scanf("%[^\n]s",&vetor[i].profissao);
  printf("\nTempo de Servico %d ",(i+1));
  scanf("%d",&vetor[i].tempo_servico);
  
 }

}
////////////////////////////////////////
void imprime_Vetor(funcionario vetor[],int tamanho){
 int i;
 printf("\nNome\t Matricula\t Profissao\t Tempo de Servico");

 for(i=0;i<tamanho;++i) 
    printf("\n%s\t %d\t %s\t %d\t",vetor[i].nome,vetor[i].matricula,vetor[i].profissao,vetor[i].tempo_servico);

}
////////////////////////////////////////

int main (void){ 
funcionario *vetor_func;
int n=2,i;

printf("Digite o tamanho do vetor que deseja alocar: ");
scanf("%d",&n);

vetor_func=malloc(n*sizeof(funcionario));/*Definindo dinamicamente o tamanho do vetor*/ 

entrada(vetor_func,n);/* Entrada dos elementos do vetor*/

gravar(vetor_func,n); /*Grava o vetor de tamanho n na mem�ria N�O Vol�til*/

leitura(vetor_func,n); /*carrega os elementos salvos na mem�ria N�O vol�til para a mem�ria RAM por meio do vetor vetor_func */
								
imprime_Vetor(vetor_func,n); /*imprime o vetor com os dados carregados */

free(vetor_func);/*libera mem�ria alocada para vetor_func*/

}
