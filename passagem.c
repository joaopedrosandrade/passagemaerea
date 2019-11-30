#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct aeroporto{
    char codigoAeroporto[50];
    char nomeAeroporto[100];
    char cidadeAeroporto[100];
    char estadoAeroporto[100];
}Aeroporto;

typedef struct voos{   
    int codigorota;
    char nomeRota[100];
    int diaData;
    int mesData;
    int anoData;
    int numeroPoltronas;
    float milhas;
}Voos;

typedef struct funcionarios{
    int matricula;
    char nome[100];
    char cargo[100];
}Funcionario;

typedef struct clientes{
    int codigoPassageiro;
    char nomePassageiro[100];
    char rg[20];
    char cpf[20];
    char dnasc[20];
    char telefone[20];
    char email[50];
    char contEmergencia[20];
    int bagagem;

}Clientes;

/* VARIAVEIS GLOBAIS DA FUNCAO DE FUNCIONARIO */
int quantidadeF;
Funcionario *cadFuncio;

/* VARIAVEIS GLOBAIS DA FUNCAO DE CLIENTES */
int quantidade,cod;
Clientes *cadClientes;

/* VARIAVEIS GLOBAIS DA FUNCAO DE ROTAS */
int quantidadeR,codR;
Voos *cadVoos;

/* PROTOTIPOS DAS FUNÇÕES */
void menu1();

void cadastraClientes(){
    
    printf("Digite a quantidade de Clientes que deseja cadastrar: ");
    scanf("%d",&quantidade);
    cadClientes =  malloc(quantidade * sizeof(Clientes));
    for(int i=0; i < quantidade; i++){
        cod = i+1;
        cadClientes[i].codigoPassageiro = cod;
        printf("\nO codigo do cliente e: %d ",cadClientes[i].codigoPassageiro);
        printf("\nDigite o nome do passageiro: ");
        fflush(stdin);
        fgets(cadClientes[i].nomePassageiro,100,stdin);
        printf("Digite o RG: ");
        fflush(stdin);
        fgets(cadClientes[i].rg,20,stdin);
        printf("Digite o CPF: ");
        fflush(stdin);
        fgets(cadClientes[i].cpf,20,stdin);
        printf("Data de nascimento no formato XX/XX/XXXX:  ");
        fflush(stdin);
        fgets(cadClientes[i].dnasc,20,stdin);
        printf("Digite o telefone: ");
        scanf("%li",&cadClientes[i].telefone);
        printf("Digite o email: ");
        fflush(stdin);
        fgets(cadClientes[i].email,50,stdin);
        printf("Digite o contato de emergencia: ");
        fflush(stdin);
        fgets(cadClientes[i].contEmergencia,20,stdin);
        printf("\nDeseja bagagem extra? 1 para SIM e 2 para NAO: ");
        scanf("%d",&cadClientes[i].bagagem);

    }
}

void pesquisaCliente(){
    char nomeCliente[100];
    int opAltera;
    printf("Digite o nome do Cliente a ser pesquisado: ");
    fflush(stdin);
    fgets(nomeCliente,100,stdin);

    for(int i=0; i < quantidade; i++){
        if(strcmp(nomeCliente,cadClientes[i].nomePassageiro)==0){
            printf("\n *** PASSAGEIRO ENCONTRADO **** \n ");
            printf("Codigo: %d \n",cadClientes[i].codigoPassageiro);
            printf("Nome: %s \n",cadClientes[i].nomePassageiro);
            printf("RG: %s \n",cadClientes[i].rg);
            printf("CPF: %s \n",cadClientes[i].cpf);
            printf("Data de Nascimento: %s \n",cadClientes[i].dnasc);
            printf("Telefone: %s \n",cadClientes[i].telefone);
            printf("Email: %s \n",cadClientes[i].email);
            printf("Contato de Emergencia: %s \n",cadClientes[i].contEmergencia);
                if(cadClientes[i].bagagem==1){
                    printf("\nBagagem extra:  SIM \n");
                }else{
                    printf("\nBagagem extra:  NAO \n");
                }
            printf(" _____________________________________________\n");
            printf("|            DESEJA ALTERAR ESSE CLIENTE?     |\n");
            printf("|_____________________________________________|\n\n");
            printf("\nDigite 1 para alterar ou 2 para voltar: "); 
            scanf("%d",&opAltera);
                if(opAltera==1){
                    printf("Digite o novo nome: ");
                   
                    
                }else{
                    menu1();
                }                  
        }else{
            printf("Esse cliente nao existe \n");
        }
    }
    
}
void cadastraAeroporto(){

    int quantidadeA;
    Aeroporto *cadAeroporto;
    printf("Quantos aeroportos deseja inserir: ");
    scanf("%d",&quantidadeA);
    cadAeroporto = malloc(quantidadeA * sizeof(Voos));
    for(int i=0; i < quantidadeA; i++){
        printf("Digite o codigo do aeroporto: ");
        fflush(stdin);
        fgets(cadAeroporto[i].codigoAeroporto,50,stdin);
        printf("Digite o nome do aeroporto: ");
        fflush(stdin);
        fgets(cadAeroporto[i].nomeAeroporto,100,stdin);
        printf("Cidade do aeroporto: ");
        fflush(stdin);
        fgets(cadAeroporto[i].cidadeAeroporto,100,stdin);
        printf("Estado do aeroporto: ");
        fflush(stdin);
        fgets(cadAeroporto[i].estadoAeroporto,100,stdin);
       
    }
   
    
}

void cadastraRota(){
    
    printf("Quantas rotas deseja inserir: ");
    scanf("%d",&quantidadeR);
    cadVoos = malloc(quantidadeR * sizeof(Voos));
    for(int i=0; i < quantidadeR; i++){
        codR = i+1;
        cadVoos[i].codigorota = codR;
        printf("O codigo da rota e %d \n",cadVoos[i].codigorota);
        printf("Nome da rota: ");
        fflush(stdin);
        fgets(cadVoos[i].nomeRota,100,stdin);
        printf("Dia da rota/voo (Ex: 15):  ");
        scanf("%d",&cadVoos[i].diaData);
        printf("Mes da rota/voo (Ex: 10): ");
        scanf("%d",&cadVoos[i].mesData);
        printf("Ano da rota/voo (Ex: 2010): ");
        scanf("%d",&cadVoos[i].anoData);
        printf("Quantidade de poltronas disponiveis: ");
        scanf("%d",&cadVoos[i].numeroPoltronas);
        printf("Distancia em milhas: ");
        scanf("%f",&cadVoos[i].milhas);      
        
    }

}

void cadastraFuncionario(){
   
    printf("\nQuantos funcionarios deseja cadastrar?: ");
    scanf("%d",&quantidadeF);
    cadFuncio = malloc(quantidadeF * sizeof(Funcionario));
    for(int i=0; i < quantidadeF; i++){
        printf("\nDigite a matricula do funcionario: ");
        scanf("%d", &cadFuncio[i].matricula);
        printf("Digite o nome do funcionario: ");
        fflush(stdin);
        fgets(cadFuncio[i].nome,100,stdin);
        printf("Digite o cargo do funcionario: ");
        fflush(stdin);
        fgets(cadFuncio[i].cargo,100,stdin);
    }

}
void pesquisaFuncio(){
    char nome[100], novoNome[100];
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(nome,100,stdin);
   
    for(int i=0;i<quantidadeF; i++){
    
        if(strcmp(cadFuncio[i].nome,nome)==0){
            printf("O funcionario %s foi encontrado \n",cadFuncio[i].nome);           
            printf("Digite o novo nome: ");
            fflush(stdin);
            fgets(novoNome,100,stdin);
            strcpy(cadFuncio[i].nome,novoNome);
            printf("%s", cadFuncio[i].nome);          
         

        }else{
            printf("Esse funcionario nao existe");
        }
    }

}


void menu2(){

    int op2;

    do{

    printf("\n[4] Cadastrar aeroportos");
    printf("\n[5] Cadastrar voos/trechos");
    printf("\n[6] Cadastrar passageiros");
    printf("\n[7] Pesquisar/alterar dados de passageiros");
    printf("\n[8] Cadastrar funcionarios");
    printf("\n[9] Pesquisar/Alterar funcionarios");
    printf("\nOpcao: ");

    scanf("%d", &op2);

    switch (op2){

        case 4:
            cadastraAeroporto();
            break;
        case 5:
            cadastraRota();
            break;
        case 6:
            cadastraClientes();
            break;
        case 7:            
            pesquisaCliente();
            break;
        case 8:
            cadastraFuncionario();
            break;
        case 9:
            
            pesquisaFuncio();
            break;
        case 10:
            break;
    }

    }while (op2>3 && op2<10);
}

void menu3(){

    int op3;

    do{
    printf("\n[11] Selecionar origem e destino");
    printf("\n[12] Voltar");
    printf("\nOpcao: ");
    scanf("%d", &op3);

    switch (op3){

        case 11:
            printf("funcionou");
            break;
        case 12:
            printf("funcionou");
            break;
    }
    }while (op3>10 && op3<13);
}
void menu1(){

    int op1;

    do{

    printf("\n[1] Configuracoes");
    printf("\n[2] Vendas");
    printf("\n[3] Sair");
    printf("\nDigite uma opcao: ");

    scanf("%d", &op1);

    switch (op1){

        case 1:

            menu2();
            break;

        case 2:

            menu3();
            break;
    }
    }while (op1>0 && op1<4);

}
int main(){
    setlocale(LC_ALL, "Portuguese");

    printf("****** SEJA BEM VINDO AO IKJ LINHAS AEREAS ******\n\n");

    menu1();
    return 0;
}