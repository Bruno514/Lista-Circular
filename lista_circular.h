#include <stdbool.h>

typedef struct elemento
{
  int info;
  struct elemento *proximo;
} Elemento;

typedef struct lista_circular
{
  Elemento *cabeca;
} ListaCircular;

ListaCircular *criar_lista();

void imprimir_lista(ListaCircular *lista);

void adicionar_item_cabeca(int x, ListaCircular *lista);

void adicionar_item_calda(int x, ListaCircular *lista);

void inserir_item_por_index(int x, int index, ListaCircular *lista);

// Remove elemento que procede ao parâmetro
void remover(ListaCircular *lista, Elemento *elemento);

bool buscar_e_remover(int x, ListaCircular *lista);

Elemento *buscar(int x, ListaCircular *lista);

Elemento *buscar_por_index(int index, ListaCircular *lista);
