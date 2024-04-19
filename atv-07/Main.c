#include <stdio.h>
#include "./lib/ListaDinEncadDupla.h"

int main() {
    Lista* lista = lista_cria();

    Aluno aluno1 = {20, "Vinicius", 1, 2, 3};
    Aluno aluno2 = {25, "Bianca", 3, 2, 1};
    Aluno aluno3 = {30, "Andrey", 3, 2, 1};

    Aluno encontrado;

    printf("\nTam %d", lista_tamanho(lista));

    lista_insere_final(lista, aluno1);
    lista_busca_posicao(lista, 0, &encontrado);
    printf("\nMat: %d", encontrado.matricula);
    printf("\nTam %d", lista_tamanho(lista));

    lista_insere_final(lista, aluno2);
    lista_busca_posicao(lista, 1, &encontrado);
    printf("\nMat: %d", encontrado.matricula);
    printf("\nTam %d", lista_tamanho(lista));

    lista_insere_final(lista, aluno3);
    lista_busca_matricula(lista, 20, &encontrado);
    printf("\nMat: %d", encontrado.matricula);
    printf("\nTam %d", lista_tamanho(lista));
}