#include <stdio.h>
#define MAX 4

typedef struct {
    int valor;
} Numero;

void ler4Numeros (Numero lista[MAX] ) { 
    for( int i = 0; i < MAX; i++) {
        printf("Digite o valor %d: \n", i+1);
        scanf("%d", &lista[i].valor);
    }
}

void imprimir (Numero lista[MAX]) {
    for( int i = 0; i < MAX; i++) {
        printf("Numero %d, %d\n", i+1, lista[i].valor);
    }
}

int main (){

    Numero numeros[MAX];
    ler4Numeros(numeros);
    imprimir(numeros);

return 0;
}