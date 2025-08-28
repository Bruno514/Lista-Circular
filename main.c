#include "lista_circular.h"
#include <stdio.h>
#include <time.h>

int main(void)
{
  ListaCircular *lista = criar_lista();

  printf("Adicionar itens de 1 a 5 à calda da lista: \n");
  for (int i = 1; i <= 5; i++)
  {
    adicionar_item_calda(i, lista);
  }
  imprimir_lista(lista);

  printf("\nAdicionar itens de 1 a 5 à cabeça da lista: \n");
  for (int i = 1; i <= 5; i++)
  {
    adicionar_item_cabeca(i, lista);
  }
  imprimir_lista(lista);

  printf("\nInserir o valor 0 depois do index 4 da lista: \n");
  inserir_item_por_index(0, 4, lista);
  imprimir_lista(lista);

  printf("\nRemover elemento que procede a cabeça: \n");
  remover(lista, lista->cabeca);
  imprimir_lista(lista);

  printf("\nBuscar e remover o elemento de valor 4: \n");
  buscar_e_remover(4, lista);
  imprimir_lista(lista);

  printf("\nBuscar o elemento no index 4: \n");
  Elemento *elemento = buscar_por_index(4, lista);
  printf("Valor: %d\n", elemento->info);

  return 0;
}