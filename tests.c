#include "lista_circular.h"
#include <stdio.h>
#include <time.h>

int main(void) {
  clock_t tempo_comeco = clock();

  ListaCircular *lista = criar_lista();

  for (int i = 0; i < 10000; i++) {
    adicionar_item_calda(i, lista);
  }

  imprimir_lista(lista);

  clock_t tempo_final = clock();
  double tempo_corrido = (double)(tempo_final - tempo_comeco) / CLOCKS_PER_SEC;

  printf("Tempo corrido: %f segundos\n", tempo_corrido);

  return 0;
}