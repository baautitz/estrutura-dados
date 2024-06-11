#include <stdio.h>

#include "Aluno.h"
#include "ListaDinEncad.h"
#include "ListaDinEncadDupla.h"
#include "FilaDin.h"
#include "PilhaDin.h"

void leiaAluno(struct aluno *al) {
  printf("Matrícula: ");
  scanf("%d", &al->matricula);
  printf("Nome: ");
  scanf("%s", al->nome);
  printf("Nota 1: ");
  scanf("%f", &al->n1);
  printf("Nota 2: ");
  scanf("%f", &al->n2);
  printf("Nota 3: ");
  scanf("%f", &al->n3);
}

void menu_lista_simples() {
  int op;
  EncadSimplesLista *lista = encadsimples_cria_lista();
  struct aluno al;

  do {
    printf("\n--- Menu Lista Encadeada Simples ---\n");
    printf("1. Inserir no início\n");
    printf("2. Inserir no final\n");
    printf("3. Remover por matrícula\n");
    printf("4. Listar\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        printf("Inserir no início:\n");
        leiaAluno(&al);
        encadsimples_insere_lista_inicio(lista, al);
        break;
      case 2:
        printf("Inserir no final:\n");
        leiaAluno(&al);
        encadsimples_insere_lista_final(lista, al);
        break;
      case 3:
        printf("Remover por matrícula:\n");
        int mat;
        printf("Matrícula: ");
        scanf("%d", &mat);
        encadsimples_remove_lista(lista, mat);
        break;
      case 4:
        encadsimples_imprime_lista(lista);
        break;
      default:
        break;
    }
  } while (op != 0);

  encadsimples_libera_lista(lista);
}

void menu_lista_dupla() {
  int op;
  EncadDuplaLista *lista = encaddupla_cria_lista();
  struct aluno al;

  do {
    printf("\n--- Menu Lista Duplamente Encadeada ---\n");
    printf("1. Inserir no início\n");
    printf("2. Inserir no final\n");
    printf("3. Remover por matrícula\n");
    printf("4. Listar do início\n");
    printf("5. Listar do final\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        printf("Inserir no início:\n");
        leiaAluno(&al);
        encaddupla_insere_lista_inicio(lista, al);
        break;
      case 2:
        printf("Inserir no final:\n");
        leiaAluno(&al);
        encaddupla_insere_lista_final(lista, al);
        break;
      case 3:
        printf("Remover por matrícula:\n");
        int mat;
        printf("Matrícula: ");
        scanf("%d", &mat);
        encaddupla_remove_lista(lista, mat);
        break;
      case 4:
        encaddupla_imprime_lista(lista);
        break;
      case 5:
        encaddupla_imprime_lista_final(lista);
        break;
      default:
        break;
    }
  } while (op != 0);

  encaddupla_libera_lista(lista);
}

void menu_fila() {
  int op;
  Fila *fila = cria_Fila();
  struct aluno al;

  do {
    printf("\n--- Menu Fila ---\n");
    printf("1. Inserir\n");
    printf("2. Remover\n");
    printf("3. Listar\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        printf("Inserir:\n");
        leiaAluno(&al);
        insere_Fila(fila, al);
        break;
      case 2:
        remove_Fila(fila);
        break;
      case 3:
        imprime_Fila(fila);
        break;
      default:
        break;
    }
  } while (op != 0);

  libera_Fila(fila);
}

void menu_pilha() {
  int op;
  Pilha *pilha = cria_Pilha();
  struct aluno al;

  do {
    printf("\n--- Menu Pilha ---\n");
    printf("1. Inserir\n");
    printf("2. Remover\n");
    printf("3. Listar\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        printf("Inserir:\n");
        leiaAluno(&al);
        insere_Pilha(pilha, al);
        break;
      case 2:
        remove_Pilha(pilha);
        break;
      case 3:
        imprime_Pilha(pilha);
        break;
      default:
        break;
    }
  } while (op != 0);

  libera_Pilha(pilha);
}

int main() {
  int op;

  do {
    printf("\n--- Menu Principal ---\n");
    printf("1. Lista Encadeada Simples\n");
    printf("2. Lista Duplamente Encadeada\n");
    printf("3. Fila\n");
    printf("4. Pilha\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        menu_lista_simples();
        break;
      case 2:
        menu_lista_dupla();
        break;
      case 3:
        menu_fila();
        break;
      case 4:
        menu_pilha();
        break;
      default:
        break;
    }
  } while (op != 0);

  return 0;
}
