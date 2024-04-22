#define TAM_CPF 12
#define TAM_NOME 40

typedef struct pessoa {
  char cpf[TAM_CPF];
  char nome[TAM_NOME];
  float rendimentos;
} Pessoa;

typedef struct elemento *Lista;

Lista *lista_cria();
void lista_libera(Lista *lista);

int lista_tamanho(Lista *lista);

int lista_insere(Lista *lista, Pessoa pessoa, int posicao);
int lista_insere_inicio(Lista *lista, Pessoa pessoa);
int lista_insere_final(Lista *lista, Pessoa pessoa);

int lista_remove(Lista *lista, int posicao);
int lista_remove_inicio(Lista *lista);
int lista_remove_final(Lista *lista);

int lista_busca_posicao(Lista *lista, int posicao, Pessoa *pessoa);
int lista_busca_cpf(Lista *lista, char *cpf, Pessoa *pessoa);
