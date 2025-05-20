// Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
// valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
// (primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
// resultado da subtração.

#include <stdio.h>

int subtrair (int a, int b, int c){
    return (a-b)-c;
}

int main () {
    int a,b,c;
    printf("Digite os tres numeros: \n");
    scanf("%d %d %d", &a,&b,&c);
    printf("O valor é: %d", subtrair(a,b,c));
    return 0;
}