#include "Aluno.h"
typedef struct elemento *EncadSimplesLista;

EncadSimplesLista *encadsimples_cria_lista();
void encadsimples_libera_lista(EncadSimplesLista *li);
int encadsimples_insere_lista_final(EncadSimplesLista *li, struct aluno al);
int encadsimples_insere_lista_inicio(EncadSimplesLista *li, struct aluno al);
int encadsimples_insere_lista_ordenada(EncadSimplesLista *li, struct aluno al);
int encadsimples_remove_lista(EncadSimplesLista *li, int mat);
int encadsimples_remove_lista_inicio(EncadSimplesLista *li);
int encadsimples_remove_lista_final(EncadSimplesLista *li);
int encadsimples_tamanho_lista(EncadSimplesLista *li);
int encadsimples_lista_vazia(EncadSimplesLista *li);
int encadsimples_lista_cheia(EncadSimplesLista *li);
void encadsimples_imprime_lista(EncadSimplesLista *li);
int encadsimples_consulta_lista_mat(EncadSimplesLista *li, int mat, struct aluno *al);
int encadsimples_consulta_lista_pos(EncadSimplesLista *li, int pos, struct aluno *al);
