#include <stdio.h>
#define MAX 3

typedef struct{
    char texto[20];
} Palavra;

void gravarPalavra (Palavra palavra[MAX]) {
    for( int i = 0; i < MAX; i ++){
            printf("Digite a palavra %d, \n", i+1);
            scanf("%s", palavra[i].texto);
            getchar();
        }
    }

int main () {
    Palavra lista[MAX];
    gravarPalavra(lista);

    for( int i = 0; i < MAX; i++) {
        printf("%d: %s\n", i+1, lista[i].texto);
    }
    return 0;
}