#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main(int argc, char* argv[]) {
    int valor1, valor2, op;

    if (argc < 2) {
        printf("Faltam atlgumentos!\nUso correrto: calculadora <valor> <valor>");
        return 1;
    }

    valor1 = atoi(argv[1]);
    valor2 = atoi(argv[2]);

    printf("\nDigite a operação desejada: \n");
    printf("  1- Soma\n  2- Subtração\n  3- Multiplicação\n  4- Divisão\n\nOperação: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("%d + %d = %d", valor1, valor2, soma(valor1, valor2));
            break;
        case 2:
            printf("%d - %d = %d", valor1, valor2, subtracao(valor1, valor2));
            break;
        case 3:
            printf("%d * %d = %d", valor1, valor2, multiplicacao(valor1, valor2));
            break;
        case 4:
            if (valor2 == 0) {
                printf("Não é possível dividir por 0.");
                break;
            }

            printf("%d / %d = %f", valor1, valor2, divisao(valor1, valor2));
            break;
        default:
            printf("Operação inválida!");
            break;
    }
}