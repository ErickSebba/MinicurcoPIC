#include <stdio.h>

int count_set_bits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int number;

    printf("Digite um número inteiro: ");
    scanf("%d", &number);

    int set_bits = count_set_bits(number);
    printf("O número de bits setados é: %d\n", set_bits);

    return 0;
}


