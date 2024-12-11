#include <stdio.h>

int somaPorvalor(int a, int b){
    return a + b;
}

int somaPorReferencia(int *a, int *b){
    return *a + *b;
}

int main(){
    int a = 10, b = 3;
    printf("Soma: %d\n", soma(a, b)); // Resultado: 13
    printf("Soma por referência: %d\n", somaPorReferencia(&a, &b)); // Resultado: 13
    return 0;
}