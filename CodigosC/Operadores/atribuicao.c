#include <stdio.h>

int main() {
    int a = 10, b = 3;
    a += b; // a = a + b
    printf("Atribuição de soma: %d\n", a); // Resultado: 13

    a = 10;
    a -= b; // a = a - b
    printf("Atribuição de subtração: %d\n", a); // Resultado: 7

    a = 10;
    a *= b; // a = a * b
    printf("Atribuição de multiplicação: %d\n", a); // Resultado: 30

    a = 10;
    a /= b; // a = a / b
    printf("Atribuição de divisão: %d\n", a); // Resultado: 3

    a = 10;
    a %= b; // a = a % b
    printf("Atribuição de módulo: %d\n", a); // Resultado: 1

    return 0;

}