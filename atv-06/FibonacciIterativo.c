#include <stdio.h>

float fibonacci(int num) {
    float n1, n2, res;

    for (int i = 1; i <= num; i++) {
        if (i <= 2) {
            res = 1;
            n1 = 1;
            n2 = 1;
        } else {
            res = n1 + n2;
            n1 = n2;
            n2 = res;
        }
    }

    return res;
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