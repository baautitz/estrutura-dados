#include <stdio.h>
#include "Ponto.h"

void main() {
    float d;
    Ponto *p, *q;

    p = pontoCria(10, 21);
    q = pontoCria(7, 25);

    d = pontoDistancia(p, q);
    printf("Distância entre os pontos: %f", d);

    pontoLibera(p);
    pontoLibera(q);
}
