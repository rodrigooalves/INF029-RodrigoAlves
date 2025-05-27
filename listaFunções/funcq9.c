#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[20];
    Data dataNascimento;
    int cpf;
    char sexo;
} Cliente;

void cadastrarCliente (Cliente cliente[1] ) {
    
    printf("Cadastrando cliente: \n");
    printf("Nome: ");
    scanf("%s", cliente[0].nome);

}

int main () {


return 0;
}