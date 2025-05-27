#include <stdio.h>
#define MAX 3

void lerLetras (char lista[MAX]) {
    for(int i = 0; i < MAX; i++) {
        printf("Digite a letra %d\n", i+1);
        scanf("%c", &lista[i]);
        getchar();
    }

}

int main (){

char lista[MAX];
lerLetras(lista);
    for( int i = 0; i < MAX; i++){
        printf("Letra %d, %c\n", i+1, lista[i]);
    }

return 0;
}
