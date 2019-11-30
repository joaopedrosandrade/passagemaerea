#ifndef __VOOSS_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct trecho{
  int codigo_trecho;
  char nome_trecho[30];
  int dia_data;
  int mes_data;
  int ano_data;
  int numero_poltronas;
  float milhas;
}trechos;


void gravar (trechos vetor[],int tam){	
FILE *arq;
arq = fopen ("trechos.dat", "wb"); /* Define o nome do arquivo a ser gravado*/
if (arq != NULL) 
 fwrite(vetor, sizeof (trechos), tam, arq); /*Realiza a gravação propriamente dita */
else
 printf("Arquivo nao criado <<<Error<<");
fclose (arq); 

}
//////////////////////////////////////////////
void leitura (trechos vetor[],int tam){
FILE *arq;
arq = fopen ("trechos.dat", "rb");
if (arq != NULL)
 fread(vetor, sizeof (trechos), tam, arq); // copia os registros do arquivo para o vetor

fclose (arq); 
}
/////////////////////////////////////////////////
void gravar_codigo_trecho (int cod){	
FILE *arq;
arq = fopen ("codigotrecho.dat", "wb"); /* Define o nome do arquivo a ser gravado*/
if (arq != NULL) 
 fwrite(&cod, sizeof (int), 1, arq); /*Realiza a gravação propriamente dita */
else
 printf("Arquivo nao criado <<<Error<<");
fclose (arq); 

}
//////////////////////////////////////////////
int leitura_codigo_trecho (){
int cod=-1;
FILE *arq;
arq = fopen ("codigotrecho.dat", "rb");
if (arq != NULL)
 fread(&cod, sizeof (int), 4, arq); /* copia o código gravado no arquivo para a variável cod, se não houver registro irá trazer um valor qualquer e precisa ser tratado */
fclose (arq); 
if (cod>=0 && cod<1000) /* tratamento para garantir que retornará apenas valores válidos. Isso é necessário porque caso ocorra tentativa de leitura sem ainda ter gravado o código de trecho */
  return cod;
else
  return -1;
}
/////////////////////////////////////////////////
void entrada_Dados(trechos vetor[], int codigo){
	
  vetor[codigo].codigo_trecho = codigo;
  fflush(stdin);//__fpurge(stdin);
  printf("\nNome do Trecho/Voo de Codigo %d: ",codigo);
  scanf("%[^\n]s",vetor[codigo].nome_trecho);
  printf("\nDia do Trecho/Voo de Codigo %d: ",codigo);
  scanf("%d",&vetor[codigo].dia_data);
  printf("\nMes do Trecho/Voo de Codigo %d: ",codigo);
  scanf("%d",&vetor[codigo].mes_data);
  printf("\nAno do Trecho/Voo de Codigo %d: ",codigo);
  scanf("%d",&vetor[codigo].ano_data);
  printf("\nPoltronas do Trecho/Voo de Codigo %d: ",(codigo));
  scanf("%d",&vetor[codigo].numero_poltronas);
  printf("\nMilhas do Trecho/Voo de Codigo %d: ",(codigo));
  scanf("%f",&vetor[codigo].milhas);

}
 //////////////////////////////////////////////
void imprime(trechos vetor[],int tam){
 int i;
 printf("\nCodigo\t Nome Voo/Trecho\t Dia\t Mes\t Ano\t Poltronas\t Milhas\t\n");
 for(i=0;i<tam;i++)
  printf("%d\t %s\t %d\t %d\t %d\t %d\t\t %.2f\t\n",vetor[i].codigo_trecho,vetor[i].nome_trecho,vetor[i].dia_data,vetor[i].mes_data,vetor[i].ano_data,vetor[i].numero_poltronas,vetor[i].milhas);
  
}
 //////////////////////////////////////////////////
#endif
