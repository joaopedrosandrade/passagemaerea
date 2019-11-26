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
    char horarioH[10];
    char horarioS[10];
    int poltronas;
    float distancia;
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
    long int cpf;
    char dnasc[10];
    long int telefone;
    char email[50];
    char contEmergencia[20];
    int bagagem;

}Clientes;

void cadastraClientes(){
    
    int quantidade,cod;
    Clientes *cadClientes;
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
        scanf("%li",&cadClientes[i].cpf);
        printf("Data de nascimento no formato XX/XX/XXXX:  ");
        fflush(stdin);
        fgets(cadClientes[i].dnasc,10,stdin);
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
    int quantidadeR,codR;
    Voos *cadVoos;
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
        printf("Horario da rota XX:XX ");
        fflush(stdin);
        fgets(cadVoos[i].horarioH,10,stdin);
        printf("Quantidade de poltronas disponiveis: ");
        scanf("%d",&cadVoos[i].poltronas);
        printf("Distancia em milhas: ");
        scanf("%f",&cadVoos[i].distancia);
       
        
    }

}

void cadastraFuncionario(){
    int quantidadeF;
    Funcionario *cadFuncio;
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
void pesquisaFuncio(Funcionario *cadFuncio, int quantidadeF){
    char nome[100];
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(nome,100,stdin);
    for(int i=0;i<quantidadeF; i++){
        if(strcmp(cadFuncio[i].nome,nome)==0){
            printf("E igual");
        }else{
            printf("Nao existe");
        }
    }

}


void menu2(){

    int op2;

    do{

    printf("\n[4] Cadastrar aeroportos");
    printf("\n[5] Cadastrar voos/trechos");
    printf("\n[6] Cadastrar passageiros fidelizados");
    printf("\n[7] Pesquisar/alterar dados de passageiros fidelizados");
    printf("\n[8] Cadastrar funcionarios matricula, nome do funcionario e cargo");
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
            printf("funcionou");
            //alteraClientes():
            break;
        case 8:
            cadastraFuncionario();
            break;
        case 9:
            Funcionario *cadFuncio;
            int quantidadeF;
            pesquisaFuncio(cadFuncio,quantidadeF);
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
    printf("\nOpcao: ");

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

    printf("****** SEJA BEM VINDO AO PASSAGENS.JIK ******\n\n\n");

    menu1();
    return 0;
}