#include <stdio.h>
#include "ListaDuplEncadeada.h"

void lista_imprime(Lista *lista) {
  if (lista == NULL) return;

  int tamanhoLista = lista_tamanho(lista);

  if (tamanhoLista == 0) {
    printf("Lista vazia!\n");
    return;
  }

  Pessoa pessoa;
  for (int i = 0; i < tamanhoLista; i++) {
    lista_busca_posicao(lista, i, &pessoa);

    printf("%s ", pessoa.nome);
  }
  printf("\n");
}

int main() {
  Lista *lista;

  Pessoa p1 = {"123456789", "Vinicius", 20.0f};
  Pessoa p2 = {"987654321", "Suiciniv", 19.0f};
  Pessoa p3 = {"911981981", "Ciusvini", 25.0f};

  // Testando inserir no inicio
  lista = lista_cria();

  printf("\nTestando inserir no inicio:\n");

  lista_insere_inicio(lista, p1);
  lista_imprime(lista);

  lista_insere_inicio(lista, p2);
  lista_imprime(lista);

  lista_insere_inicio(lista, p3);
  lista_imprime(lista);

  lista_libera(lista);
  // --------------------------


  // Testando inserir no final
  lista = lista_cria();

  printf("\nTestando inserir no final:\n");

  lista_insere_final(lista, p1);
  lista_imprime(lista);

  lista_insere_final(lista, p2);
  lista_imprime(lista);

  lista_insere_final(lista, p3);
  lista_imprime(lista);

  lista_libera(lista);
  // --------------------------

  // Testando definir por posição
  lista = lista_cria();

  printf("\nTestando definir por posição:\n");

  for (int i = 0; i < 3; i++) {
    lista_define(lista, p1, i);
    lista_imprime(lista);
  }

  Pessoa pTeste = {"1", "Teste123", 5};
  for (int i = 3; i > 0; i--) {
    lista_define(lista, pTeste, i - 1);
    lista_imprime(lista);
  }

  lista_libera(lista);
  // --------------------------

  // Testando inserir por posição
  lista = lista_cria();

  printf("\nTestando inserir por posição:\n");

  lista_insere(lista, p1, 0);
  lista_imprime(lista);

  lista_insere(lista, p2, 0);
  lista_imprime(lista);

  lista_insere(lista, p3, 0);
  lista_imprime(lista);

  lista_insere(lista, p3, 2);
  lista_imprime(lista);

  lista_insere(lista, p2, 4);
  lista_imprime(lista);

  lista_insere(lista, p1, 4);
  lista_imprime(lista);

  lista_libera(lista);
  // --------------------------

  // Testando remover no final
  lista = lista_cria();

  printf("\nTestando remover no final:\n");

  lista_insere_final(lista, p1);
  lista_insere_final(lista, p2);
  lista_insere_final(lista, p3);
  lista_imprime(lista);

  lista_remove_final(lista);
  lista_imprime(lista);

  lista_remove_final(lista);
  lista_imprime(lista);

  lista_remove_final(lista);
  lista_imprime(lista);

  lista_libera(lista);
  // --------------------------

  // Testando remover no início
  lista = lista_cria();

  printf("\nTestando remover no início:\n");

  lista_insere_final(lista, p1);
  lista_insere_final(lista, p2);
  lista_insere_final(lista, p3);
  lista_imprime(lista);

  lista_remove_inicio(lista);
  lista_imprime(lista);

  lista_remove_inicio(lista);
  lista_imprime(lista);

  lista_remove_inicio(lista);
  lista_imprime(lista);

  lista_libera(lista);
  // --------------------------

  // Testando remover em uma posição
  lista = lista_cria();

  printf("\nTestando remover em uma posição:\n");

  lista_insere_final(lista, p1);
  lista_insere_final(lista, p2);
  lista_insere_final(lista, p3);
  lista_insere_final(lista, p1);
  lista_insere_final(lista, p2);
  lista_insere_final(lista, p3);
  lista_imprime(lista);

  lista_remove(lista, 1);
  lista_imprime(lista);

  lista_remove(lista, 0);
  lista_imprime(lista);

  lista_remove(lista, 3);
  lista_imprime(lista);

  lista_remove(lista, 0);
  lista_imprime(lista);

  lista_remove(lista, 1);
  lista_imprime(lista);

  lista_remove(lista, 0);
  lista_imprime(lista);

  lista_libera(lista);
  // --------------------------

  // Testando buscar por CPF
  lista = lista_cria();

  printf("\nTestando buscar por CPF:\n");

  lista_insere_final(lista, p1);
  lista_insere_final(lista, p2);
  lista_insere_final(lista, p3);
  lista_imprime(lista);

  Pessoa pessoaTeste;
  Pessoa aux;

  int codRetorno;

  for (int i = 0; i < lista_tamanho(lista); i++) {
    lista_busca_posicao(lista, i, &aux);
    printf("\nBuscando por CPF: %s (Deve retornar o nome '%s')...\n", aux.cpf, aux.nome);
    codRetorno = lista_busca_cpf(lista, aux.cpf, &pessoaTeste);

    if (codRetorno) {
      printf("Resultado: %s\n", pessoaTeste.nome);
    } else {
      printf("Deu errado!\n");
    }
  }

  lista_libera(lista);
  // --------------------------

  return 0;
}
