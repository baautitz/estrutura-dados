typedef struct {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;

typedef struct elemento* Lista;

Lista* lista_cria();
void lista_libera(Lista* lista);

int lista_tamanho(Lista* lista);

int lista_insere(Lista* lista, int posicao, Aluno aluno);
int lista_insere_inicio(Lista* lista, Aluno aluno);
int lista_insere_final(Lista* lista, Aluno aluno);

int lista_remove(Lista* lista, int posicao);
int lista_remove_inicio(Lista* lista);
int lista_remove_final(Lista* lista);

int lista_busca_posicao(Lista* lista, unsigned int posicao, Aluno* aluno);
int lista_busca_matricula(Lista* lista, int matricula, Aluno* aluno);