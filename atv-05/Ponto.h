typedef struct ponto Ponto;

Ponto* pontoCria(float x, float y);
void pontoLibera(Ponto* p);

int pontoAcessa(Ponto* p, float* x, float* y);
int pontoAtribui(Ponto* p, float x, float y);
float pontoDistancia(Ponto* p1, Ponto* p2);