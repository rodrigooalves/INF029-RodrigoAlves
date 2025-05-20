#include <stdio.h>

float aplicadorDesconto (float a, float b) {
    float resultado = a + b;
    return resultado;
}

int main (){
    float a,b;
    printf("digite o valor dos produtos: \n");
    scanf(" %f %f", &a, &b);
    float resultado = aplicadorDesconto(a,b);
    printf("Total bruto: %.2f\n",resultado);
    if (resultado >= 100) {
        resultado = resultado - (resultado * 0.10);
    }
    printf("Total com desconto: %.2f\n", resultado);
    return 0;
}