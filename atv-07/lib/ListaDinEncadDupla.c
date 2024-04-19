#include <stdio.h>
#include <stdlib.h>

#include "ListaDinEncadDupla.h"

typedef struct elemento {
    struct elemento* anterior;
    struct elemento* proximo;
    Aluno dados;
} Elemento;

Lista* lista_cria() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));

    if (lista != NULL) {
        *lista = NULL;
    }

    return lista;
}

void lista_libera(Lista* lista) {
    if (lista == NULL)
        return;

    Elemento* no;
    while (*lista != NULL) {
        no = *lista;
        *lista = (*lista)->proximo;

        free(no);
    }

    free(lista);
}

int lista_tamanho(Lista* lista) {
    if (lista == NULL)
        return -1;

    int tamanho = 0;
    Elemento* no = *lista;
    while (no != NULL) {
        tamanho++;
        no = no->proximo;
    }

    return tamanho;
}

int lista_insere_inicio(Lista* lista, Aluno aluno) {
    if (lista == NULL)
        return 0;

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (novo == NULL)
        return 0;

    if (*lista != NULL) {
        (*lista)->anterior = novo;
    }

    novo->dados = aluno;
    novo->proximo = *lista;
    novo->anterior = NULL;

    *lista = novo;
}

int lista_insere_final(Lista* lista, Aluno aluno) {
    if (lista == NULL)
        return 0;

    Elemento* elemento = (Elemento*)malloc(sizeof(Elemento));

    if (elemento == NULL)
        return 0;

    elemento->dados = aluno;
    elemento->proximo = NULL;

    if (*lista == NULL) {
        *lista = elemento;
        elemento->anterior = NULL;
    } else {
        Elemento* no = *lista;
        while (no->proximo != NULL) {
            no = no->proximo;
        }

        no->proximo = elemento;
        elemento->anterior = no;
    }

    return 1;
}

int lista_remove_inicio(Lista* lista) {
    if (lista == NULL || *lista == NULL)
        return 0;

    Elemento* no = *lista;
    *lista = no->proximo;
    if (no->proximo != NULL) {
        no->proximo->anterior = NULL;
    }

    free(no);
    return 1;
}

int lista_remove_final(Lista* lista) {
    if (lista == NULL || *lista == NULL)
        return 0;

    Elemento* no = *lista;
    while (no->proximo != NULL) {
        no = no->proximo;
    }

    if (no->anterior != NULL) {
        no->anterior->proximo = NULL;
    } else {
        *lista = NULL;
    }

    free(no);
    return 1;
}

int lista_busca_posicao(Lista* lista, unsigned int posicao, Aluno* aluno) {
    if (lista == NULL || posicao < 0 || posicao > lista_tamanho(lista) - 1)
        return 0;

    Elemento* no = *lista;

    int counter = 0;
    while (counter != posicao) {
        no = no->proximo;
        counter++;
    }

    *aluno = no->dados;

    return 1;
}

int lista_busca_matricula(Lista* lista, int matricula, Aluno* aluno) {
    if (lista == NULL)
        return 0;

    int encontrado = 0;

    Elemento* no = *lista;
    while (no != NULL && encontrado == 0) {
        if (no->dados.matricula == matricula) {
            encontrado = 1;
        } else {
            no = no->proximo;
        }
    }

    if (encontrado) {
        *aluno = no->dados;
    }

    return encontrado;
}
