#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadDupla.h"

struct elemento {
  struct elemento *ant;
  struct aluno dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

EncadDuplaLista *encaddupla_cria_lista() {
  EncadDuplaLista *li = (EncadDuplaLista *) malloc(sizeof(EncadDuplaLista));
  if (li != NULL)
    *li = NULL;
  return li;
}

void encaddupla_libera_lista(EncadDuplaLista *li) {
  if (li != NULL) {
    Elem *no;
    while ((*li) != NULL) {
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

int encaddupla_consulta_lista_pos(EncadDuplaLista *li, int pos, struct aluno *al) {
  if (li == NULL || pos <= 0)
    return 0;
  Elem *no = *li;
  int i = 1;
  while (no != NULL && i < pos) {
    no = no->prox;
    i++;
  }
  if (no == NULL)
    return 0;
  else {
    *al = no->dados;
    return 1;
  }
}

int encaddupla_consulta_lista_mat(EncadDuplaLista *li, int mat, struct aluno *al) {
  if (li == NULL)
    return 0;
  Elem *no = *li;
  while (no != NULL && no->dados.matricula != mat) {
    no = no->prox;
  }
  if (no == NULL)
    return 0;
  else {
    *al = no->dados;
    return 1;
  }
}

int encaddupla_insere_lista_final(EncadDuplaLista *li, struct aluno al) {
  if (li == NULL)
    return 0;
  Elem *no;
  no = (Elem *) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  no->prox = NULL;
  if ((*li) == NULL) {//lista vazia: insere in�cio
    no->ant = NULL;
    *li = no;
  } else {
    Elem *aux;
    aux = *li;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = no;
    no->ant = aux;
  }
  return 1;
}

int encaddupla_insere_lista_inicio(EncadDuplaLista *li, struct aluno al) {
  if (li == NULL)
    return 0;
  Elem *no;
  no = (Elem *) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  no->prox = (*li);
  no->ant = NULL;
  if (*li != NULL)//lista n�o vazia: apontar para o anterior!
    (*li)->ant = no;
  *li = no;
  return 1;
}

int encaddupla_insere_lista_ordenada(EncadDuplaLista *li, struct aluno al) {
  if (li == NULL)
    return 0;
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  if ((*li) == NULL) {//lista vazia: insere in�cio
    no->prox = NULL;
    no->ant = NULL;
    *li = no;
    return 1;
  } else {
    Elem *ante, *atual = *li;
    while (atual != NULL && atual->dados.matricula < al.matricula) {
      ante = atual;
      atual = atual->prox;
    }
    if (atual == *li) {//insere in�cio
      no->ant = NULL;
      (*li)->ant = no;
      no->prox = (*li);
      *li = no;
    } else {
      no->prox = ante->prox;
      no->ant = ante;
      ante->prox = no;
      if (atual != NULL)
        atual->ant = no;
    }
    return 1;
  }
}

int encaddupla_remove_lista(EncadDuplaLista *li, int mat) {//TERMINAR
  if (li == NULL)
    return 0;
  if ((*li) == NULL)//lista vazia
    return 0;
  Elem *no = *li;
  while (no != NULL && no->dados.matricula != mat) {
    no = no->prox;
  }
  if (no == NULL)//n�o encontrado
    return 0;

  if (no->ant == NULL)//remover o primeiro?
    *li = no->prox;
  else
    no->ant->prox = no->prox;

  if (no->prox != NULL)//n�o � o �ltimo?
    no->prox->ant = no->ant;

  free(no);
  return 1;
}

int encaddupla_remove_lista_inicio(EncadDuplaLista *li) {
  if (li == NULL)
    return 0;
  if ((*li) == NULL)//lista vazia
    return 0;

  Elem *no = *li;
  *li = no->prox;
  if (no->prox != NULL)
    no->prox->ant = NULL;

  free(no);
  return 1;
}

int encaddupla_remove_lista_final(EncadDuplaLista *li) {
  if (li == NULL)
    return 0;
  if ((*li) == NULL)//lista vazia
    return 0;

  Elem *no = *li;
  while (no->prox != NULL)
    no = no->prox;

  if (no->ant == NULL)//remover o primeiro e �nico
    *li = no->prox;
  else
    no->ant->prox = NULL;

  free(no);
  return 1;
}

int encaddupla_tamanho_lista(EncadDuplaLista *li) {
  if (li == NULL)
    return 0;
  int cont = 0;
  Elem *no = *li;
  while (no != NULL) {
    cont++;
    no = no->prox;
  }
  return cont;
}

int encaddupla_lista_cheia(EncadDuplaLista *li) {
  return 0;
}

int encaddupla_lista_vazia(EncadDuplaLista *li) {
  if (li == NULL)
    return 1;
  if (*li == NULL)
    return 1;
  return 0;
}

void encaddupla_imprime_lista(EncadDuplaLista *li) {
  if (li == NULL)
    return;
  Elem *no = *li;
  while (no != NULL) {
    printf("Matricula: %d\n", no->dados.matricula);
    printf("Nome: %s\n", no->dados.nome);
    printf("Notas: %f %f %f\n", no->dados.n1,
           no->dados.n2,
           no->dados.n3);
    printf("-------------------------------\n");

    no = no->prox;
  }
}

void encaddupla_imprime_lista_final(EncadDuplaLista *li) {
  if (li == NULL)
    return;

  Elem *no = *li;
  if (no == NULL)
    return;

  while (no->prox != NULL) {
    no = no->prox;
  }

  while (no != NULL) {
    printf("Matricula: %d\n", no->dados.matricula);
    printf("Nome: %s\n", no->dados.nome);
    printf("Notas: %f %f %f\n", no->dados.n1,
           no->dados.n2,
           no->dados.n3);
    printf("-------------------------------\n");

    no = no->ant;
  }
}

