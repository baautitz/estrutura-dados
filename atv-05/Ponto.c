#include <math.h>
#include <stdlib.h>

#include "Ponto.h"

struct ponto {
    float x;
    float y;
};

Ponto* pontoCria(float x, float y) {
    Ponto* p = (Ponto*)malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }

    return p;
}

void pontoLibera(Ponto* p) {
    free(p);
}

int pontoAcessa(Ponto* p, float* x, float* y) {
    if (p == NULL)
        return 0;

    *x = p->x;
    *y = p->y;

    return 1;
}

int pontoAtribui(Ponto* p, float x, float y) {
    if (p == NULL)
        return 0;

    p->x = x;
    p->y = y;

    return 1;
}

float pontoDistancia(Ponto* p1, Ponto* p2) {
    if (p1 == NULL || p2 == NULL)
        return 0;

    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;

    return sqrt(dx * dx + dy * dy);
}