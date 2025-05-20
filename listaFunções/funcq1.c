// 1)  Crie um programa que tenha uma função soma e a função main. A função main deve ler dois
// valores,   enviar   para   a   função   soma.   A   função   soma   deve   realizar   a   soma   e   retornar   o   valor.   A
// Função main deve imprimir o resultado da soma.

#include <stdio.h>

int somar (int a, int b) {
    return a + b;
}

int main (){
    int a, b;
    printf("Digite o valor de A e B\n ");
    scanf("%d %d", &a, &b);
    printf("a soma é: %d\n", somar(a,b));
    printf("Resultado: %-10d <- alinhado à esquerda\n", somar(a, b));
    printf("Código formatado: %05d\n", somar(a, b));
    printf("A soma de %d + %d é %d\n", a, b, somar(a, b));

    return 0;
}