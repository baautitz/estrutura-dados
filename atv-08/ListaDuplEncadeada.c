#include <stdlib.h>
#include <string.h>
#include "ListaDuplEncadeada.h"

typedef struct elemento {
  struct elemento *proximo;
  struct elemento *anterior;
  Pessoa dados;
} Elemento;

Lista *lista_cria() {
  Lista *lista = (Lista *) malloc(sizeof(Lista));
  if (lista != NULL) {
    *lista = NULL;
  }

  return lista;
}

int lista_tamanho(Lista *lista) {
  if (lista == NULL)
    return -1;

  int tamanho = 0;
  Elemento *no = *lista;
  while (no != NULL) {
    no = no->proximo;
    tamanho++;
  }

  return tamanho;
}

void lista_libera(Lista *lista) {
  if (lista == NULL) return;

  Elemento *no;
  while (*lista != NULL) {
    no = *lista;
    *lista = no->proximo;
    free(no);
  }

  *lista = NULL;
  free(lista);
}

int lista_define(Lista *lista, Pessoa pessoa, int posicao) {
  if (lista == NULL) return 0;

  int tamanhoLista = lista_tamanho(lista);
  if (posicao < 0) return 0;
  if (posicao > tamanhoLista) return 0;

  if (posicao == tamanhoLista || tamanhoLista == 0) {
    return lista_insere_final(lista, pessoa);
  }

  Elemento *no = *lista;
  int counter = 0;
  while (counter < posicao) {
    no = no->proximo;
    counter++;
  }

  no->dados = pessoa;

  return 1;
}

int lista_insere(Lista *lista, Pessoa pessoa, int posicao) {
  if (lista == NULL) return 0;

  int tamanhoLista = lista_tamanho(lista);
  if (posicao < 0) return 0;
  if (posicao > tamanhoLista) return 0;

  if (posicao == 0) {
    return lista_insere_inicio(lista, pessoa);
  }

  if (posicao == tamanhoLista) {
    return lista_insere_final(lista, pessoa);
  }

  Elemento *novoElemento = (Elemento *) malloc(sizeof(Elemento));
  if (novoElemento == NULL) return 0;

  Elemento *no = *lista;
  int counter = 0;
  while (counter < posicao) {
    no = no->proximo;
    counter++;
  }

  novoElemento->anterior = no->anterior;
  novoElemento->proximo = no;

  no->anterior->proximo = novoElemento;
  no->anterior = novoElemento;

  novoElemento->dados = pessoa;

  return 1;
}

int lista_insere_inicio(Lista *lista, Pessoa pessoa) {
  if (lista == NULL) return 0;

  Elemento *novoElemento = (Elemento *) malloc(sizeof(Elemento));
  if (novoElemento == NULL) return 0;

  if (*lista != NULL) {
    (*lista)->anterior = novoElemento;
  }

  novoElemento->anterior = NULL;
  novoElemento->proximo = *lista;
  novoElemento->dados = pessoa;

  *lista = novoElemento;

  return 1;
}

int lista_insere_final(Lista *lista, Pessoa pessoa) {
  if (lista == NULL)
    return 0;

  Elemento *novoElemento = (Elemento *) malloc(sizeof(Elemento));
  if (novoElemento == NULL) return 0;

  novoElemento->dados = pessoa;
  novoElemento->proximo = NULL;
  novoElemento->anterior = NULL;

  if (*lista == NULL) {
    *lista = novoElemento;
  } else {
    Elemento *no = *lista;
    while (no->proximo != NULL) {
      no = no->proximo;
    }

    no->proximo = novoElemento;
    novoElemento->anterior = no;
  }

  return 1;
}

int lista_remove(Lista *lista, int posicao) {
  if (lista == NULL) return 0;
  if (*lista == NULL) return 0;
  if (posicao < 0) return 0;
  if (posicao >= lista_tamanho(lista)) return 0;

  Elemento *no = *lista;
  int counter = 0;
  while (counter != posicao) {
    no = no->proximo;
    counter++;
  }

  no->anterior->proximo = no->proximo;
  no->proximo->anterior = no->anterior;

  free(no);

  return 1;
}

int lista_remove_inicio(Lista *lista) {
  if (lista == NULL) return 0;
  if (*lista == NULL) return 0;

  Elemento *no = *lista;
  (*lista)->proximo->anterior = NULL;
  *lista = (*lista)->proximo;

  free(no);

  return 1;
}

int lista_remove_final(Lista *lista) {
  if (lista == NULL) return 0;
  if (*lista == NULL) return 0;

  Elemento *no = *lista;
  while (no->proximo != NULL) {
    no = no->proximo;
  }

  no->anterior->proximo = NULL;

  free(no);

  return 1;
}

int lista_busca_posicao(Lista *lista, int posicao, Pessoa *pessoa) {
  if (lista == NULL) return 0;
  if (*lista == NULL) return 0;
  if (posicao < 0) return 0;
  if (posicao >= lista_tamanho(lista)) return 0;

  Elemento *no = *lista;
  int counter = 0;
  while (counter < posicao) {
    no = no->proximo;
    counter++;
  }

  *pessoa = no->dados;

  return 1;
}

int lista_busca_cpf(Lista *lista, char *cpf, Pessoa *pessoa) {
  if (lista == NULL) return 0;
  if (*lista == NULL) return 0;

  Elemento *no = *lista;
  int encontrou = 0;
  while (no->proximo != NULL) {
    no = no->proximo;

    if (strcmp(cpf, no->dados.cpf) != 0) continue;

    encontrou = 1;
    break;
  }

  if (encontrou)
    *pessoa = no->dados;

  return encontrou;
}

