#include "Aluno.h"

typedef struct elemento *EncadDuplaLista;

EncadDuplaLista *encaddupla_cria_lista();
void encaddupla_libera_lista(EncadDuplaLista *li);
int encaddupla_consulta_lista_pos(EncadDuplaLista *li, int pos, struct aluno *al);
int encaddupla_consulta_lista_mat(EncadDuplaLista *li, int mat, struct aluno *al);
int encaddupla_insere_lista_final(EncadDuplaLista *li, struct aluno al);
int encaddupla_insere_lista_inicio(EncadDuplaLista *li, struct aluno al);
int encaddupla_insere_lista_ordenada(EncadDuplaLista *li, struct aluno al);
int encaddupla_remove_lista(EncadDuplaLista *li, int mat);
int encaddupla_remove_lista_inicio(EncadDuplaLista *li);
int encaddupla_remove_lista_final(EncadDuplaLista *li);
int encaddupla_tamanho_lista(EncadDuplaLista *li);
int encaddupla_lista_vazia(EncadDuplaLista *li);
void encaddupla_imprime_lista(EncadDuplaLista *li);
void encaddupla_imprime_lista_final(EncadDuplaLista *li);
