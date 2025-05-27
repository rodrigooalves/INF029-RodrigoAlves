#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[20];
    Data dataNascimento;
    char cpf[15];
    char sexo;
} Cliente;

void cadastrarCliente (Cliente cliente[1] ) {
    
    printf("Cadastrando cliente: \n");
    printf("Nome: \n");
    scanf("%s", cliente[0].nome);
    getchar();
    printf("Digite a data de nascimento '( 00 00 0000)':  ");
    scanf("%d %d %d", &cliente[0].dataNascimento.dia,&cliente[0].dataNascimento.mes,&cliente[0].dataNascimento.ano);
    printf("Digite o cpf 0000000000\n");
    scanf("%s", cliente[0].cpf);
    printf("Sexo [M/F]\n");
    getchar();
    scanf("%c", &cliente[0].sexo);
}

int validaNome (Cliente cliente[1]) {
    
}
void printCliente (Cliente cliente[1]) {
    printf("Nome: %s - Data de nascimento: %d/%d/%d - CPF: %s, Sexo: %c", 
        cliente[0].nome, cliente[0].dataNascimento.dia,
        cliente[0].dataNascimento.mes,cliente[0].dataNascimento.ano,
        cliente[0].cpf,cliente[0].sexo);
}

int main () {

    Cliente cliente[1];
    cadastrarCliente(cliente);
    printCliente(cliente);
return 0;
}