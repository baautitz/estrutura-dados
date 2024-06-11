#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"

struct elemento {
  struct aluno dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

EncadSimplesLista *encadsimples_cria_lista() {
  EncadSimplesLista *li = (EncadSimplesLista *) malloc(sizeof(EncadSimplesLista));
  if (li != NULL)
    *li = NULL;
  return li;
}

void encadsimples_libera_lista(EncadSimplesLista *li) {
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

int encadsimples_consulta_lista_pos(EncadSimplesLista *li, int pos, struct aluno *al) {
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

int encadsimples_consulta_lista_mat(EncadSimplesLista *li, int mat, struct aluno *al) {
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

int encadsimples_insere_lista_final(EncadSimplesLista *li, struct aluno al) {
  if (li == NULL)
    return 0;
  Elem *no;
  no = (Elem *) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  no->prox = NULL;
  if ((*li) == NULL) {//lista vazia: insere in�cio
    *li = no;
  } else {
    Elem *aux;
    aux = *li;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = no;
  }
  return 1;
}

int encadsimples_insere_lista_inicio(EncadSimplesLista *li, struct aluno al) {
  if (li == NULL)
    return 0;
  Elem *no;
  no = (Elem *) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  no->prox = (*li);
  *li = no;
  return 1;
}

int encadsimples_insere_lista_ordenada(EncadSimplesLista *li, struct aluno al) {
  if (li == NULL)
    return 0;
  Elem *no = (Elem *) malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  if ((*li) == NULL) {//lista vazia: insere in�cio
    no->prox = NULL;
    *li = no;
    return 1;
  } else {
    Elem *ant, *atual = *li;
    while (atual != NULL && atual->dados.matricula < al.matricula) {
      ant = atual;
      atual = atual->prox;
    }
    if (atual == *li) {//insere in�cio
      no->prox = (*li);
      *li = no;
    } else {
      no->prox = atual;
      ant->prox = no;
    }
    return 1;
  }
}

int encadsimples_remove_lista(EncadSimplesLista *li, int mat) {
  if (li == NULL)
    return 0;
  if ((*li) == NULL)//lista vazia
    return 0;
  Elem *ant, *no = *li;
  while (no != NULL && no->dados.matricula != mat) {
    ant = no;
    no = no->prox;
  }
  if (no == NULL)//n�o encontrado
    return 0;

  if (no == *li)//remover o primeiro?
    *li = no->prox;
  else
    ant->prox = no->prox;
  free(no);
  return 1;
}

int encadsimples_remove_lista_inicio(EncadSimplesLista *li) {
  if (li == NULL)
    return 0;
  if ((*li) == NULL)//lista vazia
    return 0;

  Elem *no = *li;
  *li = no->prox;
  free(no);
  return 1;
}

int encadsimples_remove_lista_final(EncadSimplesLista *li) {
  if (li == NULL)
    return 0;
  if ((*li) == NULL)//lista vazia
    return 0;

  Elem *ant, *no = *li;
  while (no->prox != NULL) {
    ant = no;
    no = no->prox;
  }

  if (no == (*li))//remover o primeiro?
    *li = no->prox;
  else
    ant->prox = no->prox;
  free(no);
  return 1;
}

int encadsimples_tamanho_lista(EncadSimplesLista *li) {
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

int encadsimples_lista_cheia(EncadSimplesLista *li) {
  return 0;
}

int encadsimples_lista_vazia(EncadSimplesLista *li) {
  if (li == NULL)
    return 1;
  if (*li == NULL)
    return 1;
  return 0;
}

void encadsimples_imprime_lista(EncadSimplesLista *li) {
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
