#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "lista_circular.h"

typedef struct elemento
{
  int info;
  struct elemento *proximo;
} Elemento;

typedef struct lista_circular
{
  Elemento *cabeca;
} ListaCircular;

ListaCircular *criar_lista()
{
  ListaCircular *lista;
  lista = malloc(sizeof(ListaCircular));
  lista->cabeca = NULL;

  return lista;
}

void imprimir_lista(ListaCircular *lista)
{
  if (lista->cabeca == NULL)
  {
    return;
  }

  Elemento *atual;
  atual = lista->cabeca;

  while (atual->proximo != lista->cabeca)
  {
    printf("%d -> ", atual->info);
    atual = atual->proximo;
  }

  printf("%d\n", atual->info);
}

void adicionar_item_cabeca(int x, ListaCircular *lista){
  Elemento *novo;
  novo = malloc(sizeof(Elemento));

  novo->info = x;

  if (lista->cabeca == NULL)
  {
    lista->cabeca = novo;
    novo->proximo = lista->cabeca;

    return;
  }

  Elemento *atual;
  atual = lista->cabeca;

  while (atual->proximo != lista->cabeca)
  {
    atual = atual->proximo;
  }

  novo->proximo = lista->cabeca;
  atual->proximo = novo;

  lista->cabeca = novo;
}

void adicionar_item_calda(int x, ListaCircular *lista)
{
  Elemento *novo;
  novo = malloc(sizeof(Elemento));

  novo->info = x;

  if (lista->cabeca == NULL)
  {
    lista->cabeca = novo;
    novo->proximo = lista->cabeca;

    return;
  }

  Elemento *atual;
  atual = lista->cabeca;

  while (atual->proximo != lista->cabeca)
  {
    atual = atual->proximo;
  }

  novo->proximo = lista->cabeca;
  atual->proximo = novo;
}

// Insere um elemento com o valor especificado após o index
void inserir_item_por_index(int x, int index, ListaCircular *lista)
{
  if (index < 0)
  {
    return;
  }

  int contador = 0;
  Elemento *novo, *atual;

  atual = lista->cabeca;

  novo = malloc(sizeof(Elemento));
  novo->info = x;

  if (lista->cabeca == NULL)
  {
    lista->cabeca = novo;
    novo->proximo = lista->cabeca;

    return;
  }

  while (1)
  {
    if (contador++ == index)
    {
      novo->proximo = atual->proximo;

      atual->proximo = novo;

      return;
    }

    atual = atual->proximo;
  } 
}

// Remove elemento que procede ao parâmetro
void remover(ListaCircular *lista, Elemento *elemento)
{
  Elemento *lixo;

  if (elemento == NULL)
    return;

  if (elemento->proximo == NULL)
    return;

  lixo = elemento->proximo;

  // Caso o elemento a ser deletado seja o mesmo que a cabeça da lista 
  if (elemento == lixo)
  {
    lista->cabeca = NULL;
    free(lixo);

    return;
  }

  // Caso o elemento a ser removido se referir à cabeça da lista, apontar para o proximo
  if (lixo == lista->cabeca)
  {
    lista->cabeca = lixo->proximo;
    elemento->proximo = lista->cabeca;
    free(lixo);

    return;
  }

  elemento->proximo = lixo->proximo;
  free(lixo);

  return;
}

bool buscar_e_remover(int x, ListaCircular *lista)
{
  if (lista->cabeca == NULL)
  {
    return false;
  }

  Elemento *atual, *proximo;

  atual = lista->cabeca;
  proximo = atual->proximo;
  while (1)
  {
    if (proximo->info == x)
    {
      remover(lista, atual);

      return true;
    }

    if (proximo == lista->cabeca)
    {
      return false;
    }

    atual = proximo;
    proximo = proximo->proximo;
  };

  return false;
}

Elemento *buscar(int x, ListaCircular *lista)
{
  if (lista->cabeca == NULL)
  {
    return NULL;
  }

  Elemento *atual;

  atual = lista->cabeca;

  do
  {
    if (atual->info == x)
    {
      return atual;
    }

    atual = atual->proximo;
  } while (atual != lista->cabeca);

  return NULL;
}

Elemento *buscar_por_index(int index, ListaCircular *lista)
{
  if (index < 0)
  {
    return NULL;
  }

  if (lista->cabeca == NULL)
  {
    return NULL;
  }

  int contador = 0;
  Elemento *atual;

  atual = lista->cabeca;

  while (1)
  {
    if (contador++ == index)
    {
      return atual;
    }

    atual = atual->proximo;
  } 
}