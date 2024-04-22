#include <stdio.h>
#include "ListaDuplEncadeada.h"

void imprime_lista(Lista *lista) {
  if (lista == NULL) return;
  if (*lista == NULL) return;

  Pessoa pessoa;
  for (int i = 0; i < lista_tamanho(lista); i++) {
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
  imprime_lista(lista);

  lista_insere_inicio(lista, p2);
  imprime_lista(lista);

  lista_insere_inicio(lista, p3);
  imprime_lista(lista);

  lista_libera(lista);
  // --------------------------


  // Testando inserir no final
  lista = lista_cria();

  printf("\nTestando inserir no final:\n");

  lista_insere_final(lista, p1);
  imprime_lista(lista);

  lista_insere_final(lista, p2);
  imprime_lista(lista);

  lista_insere_final(lista, p3);
  imprime_lista(lista);

  lista_libera(lista);
  // --------------------------

  // Testando inserir por posição
  lista = lista_cria();

  printf("\nTestando inserir por posição:\n");

  int aux = 1;
  for (int i = 0; i < 5; i++) {
    lista_insere(lista, p1, i);
    imprime_lista(lista);
  }

  Pessoa pTeste = {"1", "Teste123", 5};
  for (int i = 5; i > 0; i--) {
    lista_insere(lista, pTeste, i - 1);
    imprime_lista(lista);
  }

  lista_libera(lista);
  // --------------------------

  return 0;
}
