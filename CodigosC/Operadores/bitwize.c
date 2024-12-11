#include <stdio.h>

int main(){
    int a = 0b1010, b = 0b0011;// 10, 3
    printf("AND: %d\n", a & b); // Resultado: 0010(2)
    printf("OR: %d\n", a | b); // Resultado: 1011(11)
    printf("XOR: %d\n", a ^ b); // Resultado: 1001(9)
    printf("NOT: %d\n", ~a); // Resultado: 0101(-11)
    printf("Deslocamento para a esquerda: %d\n", a << 1); // Resultado: 10100(20)
    printf("Deslocamento para a direita: %d\n", a >> 1); // Resultado: 0101(5)

    unsigned char c =  0b1010; //2bytes
    printf("NOT 2: %u\n", ~c);// Resultado (4294967285)
}