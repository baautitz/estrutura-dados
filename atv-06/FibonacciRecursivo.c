#include <stdio.h>

float fibonacci(int n) {
    if (n <= 2) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;

    printf("Digite quantidade de números: ");
    scanf("%d", &num);

    printf("Calculando %d números de Fibonacci: \n", num);
    for (int i = 1; i <= num; i++) {
        printf("%.0f ", fibonacci(i));
    }

    return 0;
}