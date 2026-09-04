#include <stdio.h>

int main() {
    int X[10];
    int i;

    // Preenchendo o vetor com 30
    for (i = 0; i < 10; i++) {
        X[i] = 30;
    }

    // Exibindo o vetor
    for (i = 0; i < 10; i++) {
        printf("%d ", X[i]);
    }

    return 0;
}
