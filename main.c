#include "lista_circular.h"
#include <stdio.h>

int main(void) {
  ListaCircular *lista = criar_lista();

  adicionar_item_calda(20, lista);
  adicionar_item_calda(40, lista);
  adicionar_item_calda(30, lista);
  adicionar_item_calda(30, lista);
  adicionar_item_calda(70, lista);

  inserir_item_por_index(24, 5, lista);
  adicionar_item_cabeca(34, lista);
  adicionar_item_cabeca(60, lista);

  imprimir_lista(lista);
  buscar_e_remover(40, lista);

  imprimir_lista(lista);
  buscar_e_remover(20, lista);

  imprimir_lista(lista);
  buscar_e_remover(30, lista);

  imprimir_lista(lista);
  buscar_e_remover(30, lista);

  imprimir_lista(lista);
  buscar_e_remover(60, lista);

  imprimir_lista(lista);

  printf("Item por index: %d\n", buscar_por_index(5, lista)->info);

  return 0;
}