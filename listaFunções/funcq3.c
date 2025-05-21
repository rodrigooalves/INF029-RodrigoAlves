#include <stdio.h>

int fatorial (int n) {
    if (n < 0){
        return -1;
    }
    
    int resultado = 1;
    for ( int i = n; i >= 1; i-- ){ 
        resultado *= i;
    }
    return resultado;
}

int main (){

int fat;

    printf("Digite um numero para saber seu fatorial: \n");
    scanf("%d", &fat);
    
    printf("Fatorial de %d e %d", fat, fatorial(fat));

return 0;
}