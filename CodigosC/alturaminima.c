#include <stdio.h>
#define MAX 6

int main() {
    int N, H, i, count = 0;
    int alturas[MAX];

    // Lê o número de brinquedos e a altura de Carlitos
    scanf("%d %d", &N, &H);

    // Lê as alturas mínimas dos brinquedos
    for (i = 0; i < N; i++) {
        scanf("%d", &alturas[i]);
        if (H >= alturas[i]) {
            count++;
        }
    }

    // Imprime o resultado
    printf("%d\n", count);

    return 0;
}