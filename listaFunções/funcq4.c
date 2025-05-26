#include <stdio.h>
#define MAX 3

void listNum ( int lista[MAX]) {
    for (int i = 0; i < MAX ; i++) {
        printf("Digite o numero %d: \n", i+1);
        scanf("%d", &lista[i]);
    }
}

int main () {
    int numeros[MAX];
    listNum(numeros);

    for(int i = 0; i < MAX; i++) {
        printf("Numero %d: %d\n", i+1, numeros[i]);
    }
    return 0;
}